#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* This program will read the first 3 lines of input 
   and prints a static 2D maze*/

typedef struct mazeStruct
{
 char **arr;  /* allows for a maze of size 30x30 plus outer walls */
 int xsize, ysize;
 int xstart, ystart;
 int xend, yend;
} maze;


typedef struct nodeStruct
{
  int Xpos;
  int Ypos;
  struct nodeStruct* Next;
} node;

typedef struct stackStruct
{
  node* Head;
} stack;

stack init() {
  stack newStack;
  newStack.Head = NULL;
  return newStack;
}

bool isEmpty(node* head) {
  if (head == NULL) {
    return true;
  }
  else {
    return false;
  }
}
bool debugMode;

void push(node** head, int xpos, int ypos, int flag) {
  node* newNode = (node*) malloc(sizeof( node));
  newNode->Xpos = xpos;
  newNode->Ypos = ypos;
  newNode->Next = *head;
  *head = newNode;
  if (debugMode&&flag==1) 
    printf("(%d,%d) pushed into the stack.\n", xpos, ypos);
}

void pop( node** head, int flag) {
  //flag=0;
  node* temp = *head;
  //printf("(%d,%d) popped off the stack.\n", temp->Xpos, temp->Ypos);
  //printf("11111");
  if ( temp != NULL) {
    //printf("00000");  

    if (debugMode&&flag==1) {
      printf("(%d,%d) popped off the stack.\n", temp->Xpos, temp->Ypos);
    }
    
    *head = temp->Next;
    free (temp);
  }
}
node* top(node* head) {
  return head;
}

void clear(node** head) {
  while(isEmpty(*head)==false) {
    pop(head,1);
  }
}

void reversePath(node* head) {
  //debugMode = false; 

  stack reverseS;
  reverseS = init();

  int xpos;
  int ypos;
  while(head != NULL) {
    push(&reverseS.Head, head->Xpos, head->Ypos, 0);
    head = head->Next;
  }
  while(!isEmpty(reverseS.Head)) {
    printf("(%d,%d) ", reverseS.Head->Xpos, reverseS.Head->Ypos);
    //debugMode=true;

    pop(&reverseS.Head, 0);
  }

  clear(&reverseS.Head);
}

int main (int argc, char **argv)
{
  maze m1;
  debugMode = false; 

  for (int i = 1 ; i < argc ; i++ ){
    if (strcmp ( argv[i], "-d") == 0 ){
      debugMode = true;
    }
  }

  int xpos, ypos;
  int i,j;
  char thirdinput;
  stack s1;
  s1.Head=NULL;
  FILE *src;

  /* verify the proper number of command line arguments were given */
  if(argc >3) {
     printf("Usage: %s <input file name>\n", argv[0]);
     exit(-1);
  }
   
  /* Try to open the input file. */
  if ( (src = fopen( argv[1], "r" )) == NULL )
  {
    printf ("Can't open input file: %s", argv[1] );
    exit(-1);
  }
  
  setbuf(stdout, NULL);
  /* read in the size, starting and ending positions in the maze */

  // while(fscanf (src, "%d %d", &xpos, &ypos)!=EOF){
  //   count++;
  //   for (int i =0;i<4;i++){
  //   fscanf (src, "%d %d", &m1.xsize, &m1.ysize);
  //   fscanf (src, "%d %d", &m1.xstart, &m1.ystart);
  //   fscanf (src, "%d %d", &m1.xend, &m1.yend);
  // }
  int count = 0;
  count += fscanf (src, "%d %d", &m1.xsize, &m1.ysize);
  count += fscanf (src, "%d %d", &m1.xstart, &m1.ystart);
  count += fscanf (src, "%d %d", &m1.xend, &m1.yend);
  if (count < 6)
  {
    printf("Invalid data file.\n");
    exit(-1);
  }


  //fscanf (src, "%d %d", &m1.xstart, &m1.ystart);
  if(m1.xsize<=0||m1.ysize<=0){ 
    //printf ("size: %d, %d\n", m1.xsize, m1.ysize);
    fprintf( stderr, "Maze sizes must be greater than 0.\n");
    exit(-1);
  }

  // if(m1.xsize == 0 || m1.ysize == 0 || m1.xstart == 0 || m1.ystart == 0 || m1.xend == 0 || m1.yend == 0) { 
  //   fprintf( stderr, "Invalid data file.\n");
  //   exit(-1);
  // }

  if(m1.xstart>m1.xsize||m1.ystart>m1.ysize){
    //printf ("size: %d, %d\n", m1.xsize, m1.ysize);
    printf ("size: %d, %d\n", m1.xsize, m1.ysize);
    printf ("start: %d, %d\n", m1.xstart, m1.ystart);
    fprintf( stderr, "Start/End position outside of maze range.\n");
    exit(-1);
  }


  //fscanf (src, "%d %d", &m1.xend, &m1.yend);
  if(m1.xend>m1.xsize||m1.yend>m1.ysize){
    //printf("%d %d %d %d \n", m1.xstart, m1.ystart, m1.xend, m1.yend);
    //printf ("end: %d, %d\n", m1.xend, m1.yend);
    printf ("size: %d, %d\n", m1.xsize, m1.ysize);
    printf ("start: %d, %d\n", m1.xstart, m1.ystart);
    fprintf( stderr, "Start/End position outside of maze range.\n");
    exit(-1);
  }
  /* print them out to verify the input */
  printf ("size: %d, %d\n", m1.xsize, m1.ysize);
  printf ("start: %d, %d\n", m1.xstart, m1.ystart);
  printf ("end: %d, %d\n", m1.xend, m1.yend);

  m1.arr = (char**) malloc((m1.xsize + 2) * sizeof(char*));

  for ( i = 0; i < m1.xsize + 2; ++i) {
    m1.arr[i] = (char*) malloc((m1.ysize + 2) * sizeof(char));
  }

  /* initialize the maze to empty */
  for (i = 0; i < m1.xsize+2; i++)
     for (j = 0; j < m1.ysize+2; j++)
       m1.arr[i][j] = '.';

  /* mark the borders of the maze with *'s */
  for (i=0; i < m1.xsize+2; i++)
    {
     m1.arr[i][0] = '*';
     m1.arr[i][m1.ysize+1] = '*';
    }
  for (i=0; i < m1.ysize+2; i++)
    {
     m1.arr[0][i] = '*';
     m1.arr[m1.xsize+1][i] = '*';
    }

    /* mark the starting and ending positions in the maze */
  m1.arr[m1.xstart][m1.ystart] = 's';
  m1.arr[m1.xend][m1.yend] = 'e';
        
  /*This code will only read the first three lines */
  /*Complete this code by reading the rest of the input
    and placing blocked and coin positions. */
  /* Blocked positions are marked with 'b' in the input file
     They should be marked by * in the maze */
  
  while(fscanf (src, "%d %d %c", &xpos, &ypos, &thirdinput)!=EOF){
    if(xpos>m1.xsize||ypos>m1.ysize){
      printf("Invalid coordinates: outside of maze range.\n");
      continue;
    }
    //fscanf (src, "%d %d %c", &xpos, &ypos, &thirdinput); 
    if(thirdinput=='b'){
      if((xpos==m1.xstart&&ypos==m1.ystart)||(xpos==m1.xend&&ypos==m1.yend)){
        fprintf( stderr,"Invalid coordinates: attempting to block start/end position.\n");
        continue;
      }

      else{
        m1.arr[xpos][ypos]='*';
      }
    }

   /*Coin positions are marked by 'c' in the input file
      They should be marked by C in the maze*/
    else if(thirdinput=='c'){
      if((xpos==m1.xstart&&ypos==m1.ystart)||(xpos==m1.xend&&ypos==m1.yend)){
        fprintf( stderr,"Invalid coordinates: attempting to block start/end position.\n");
        continue;
      }

      else{
        m1.arr[xpos][ypos]='C';
      }
    }
    else{
      fprintf( stderr,"Invalid type: type is not recognized.\n");
      continue;
    }
}

  /*Close the file*/
   fclose(src);

  /* print out the initial maze */
  for (i = 0; i < m1.xsize+2; i++)
    {
     for (j = 0; j < m1.ysize+2; j++)
       printf ("%c", m1.arr[i][j]);
     printf("\n");
    }
  push( &s1.Head, m1.xstart, m1.ystart, 1);

  m1.arr[m1.xstart][m1.ystart] = 'V';
    // for (i = 0; i < m1.xsize+2; i++){
    //  for (j = 0; j < m1.ysize+2; j++){
    //   if(m1.arr[i][j]!='*'){
    //     m1.arr[i][j]='UNVISITED';
    //   }
    //  }
    // }
  xpos = m1.xstart; // to the starting point
  ypos = m1.ystart;
  int coin = 0;
  while(!(xpos == m1.xend && ypos == m1.yend) && !isEmpty(s1.Head)){
    xpos=top(s1.Head)->Xpos;
    ypos=top(s1.Head)->Ypos;
    // printf("%d \n", xpos);
    // printf("%d\n", ypos);
    // for (i = 0; i < m1.xsize+2; i++)
    // {
    //  for (j = 0; j < m1.ysize+2; j++)
    //    printf ("%c", m1.arr[i][j]);
    //  printf("\n");
    // }

    //int coin=0;
    if(m1.arr[xpos][ypos] == 'C'){
      coin++;
    }

    m1.arr[xpos][ypos] = 'V';
    

    if((xpos==m1.xend && ypos==m1.yend)){   //reached ending point
      break;
    }

    if ( m1.arr[xpos + 1][ypos] != '*' && m1.arr[xpos + 1][ypos] != 'V') {
      push(&s1.Head, xpos + 1, ypos, 1);
      //m1.arr[xpos + 1][ypos] = 'V';
    }
    else if (m1.arr[xpos][ypos + 1] != '*' && m1.arr[xpos][ypos + 1] != 'V') {
      push( &s1.Head, xpos, ypos + 1, 1);
      //m1.arr[xpos][ypos + 1] = 'V';
    }
    else if ( m1.arr[xpos - 1][ypos] != '*' && m1.arr[xpos - 1][ypos] != 'V') {
      push( &s1.Head, xpos - 1, ypos, 1);
      //m1.arr[xpos - 1][ ypos] = 'V';
    }
    else if (m1.arr[xpos][ypos - 1] != '*' && m1.arr[xpos][ypos - 1] != 'V') {
      push( &s1.Head, xpos, ypos - 1, 1);
      //m1.arr[xpos][ypos - 1] = 'V';
    }



    else {
      pop(&s1.Head, 1);
    }
    //if(isEmpty(s1.Head)==true){
      // xpos=top(s1.Head)->Xpos;
      // ypos=top(s1.Head)->Ypos;
    //}
    

  }
  
  // for (i = 0; i < m1.xsize+2; i++)
  // {
  //   for (j = 0; j < m1.ysize+2; j++) {
  //     printf ("%c", m1.arr[i][j]);
  //   }
  //   printf("\n");
  // }
  if(isEmpty(s1.Head)){
    printf("This maze has no solution.\n");
  }

  else{
    printf("\nThe maze has a solution.\n");
    printf("The amount of coins collected: %d\n", coin);
    printf("The path from start to end: \n");
    reversePath(s1.Head);
    while(!isEmpty(s1.Head)){
      //debugMode=true;
      pop(&s1.Head, 1);
    }
  }
  for (i = 0; i < m1.xsize+2; ++i) {
    free(m1.arr[i]);
  }
  free(m1.arr);
}