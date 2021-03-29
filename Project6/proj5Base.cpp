#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "island.h"
#include <string.h>
#include <string>


class ArchipelagoExpedition
{
 private:
   // Create the Data Members for the Archipelago Network here
  Island* IslandArr;
  queue* IslandQue;
  stack* stackList;
  int size;
  Myfilelist* fileInUse;
  
 public:
  
 // Use a constructor to initialize the Data Members for your expedition
   ArchipelagoExpedition()
   {
    size=11;
    IslandArr = new Island[size];
    IslandQue = new queue();
    stackList = new stack();

    fileInUse= new Myfilelist();

   }



void depthFirstSearchHelper(int x, int y){
  //mark all islands as unvisited;
  for(int i =1; i<size; i++){
    IslandArr[i].markUV();
  }

  if(dfs(x, y)){
    printf("You can get from island %d to island %d in one or more ferry rides\n", x, y);
  }
  else{
      printf ("You can NOT get from island %d to island %d in one or more ferry rides\n", x, y);
  }
}

bool dfs(int a, int b){
  for (int i =0; i< IslandArr[a].getList()->getListLength(); i++){
    //printf("%d\n", IslandArr[a].getList()->getNthValue(i));
    if(IslandArr[a].getList()->getNthValue(i)==b){
      return true;

    }
    if(IslandArr[IslandArr[a].getList()->getNthValue(i)].getV()==false){
      IslandArr[IslandArr[a].getList()->getNthValue(i)].markV();
      if(dfs(IslandArr[a].getList()->getNthValue(i), b)){
        return true;
      }
    }
  }
  return false;
  }
//   MyNode* temp= IslandArr[a].getList()->gethead();
//   //printf("%d,  %d\n", temp->getNum(), a);
//   while(temp->getNext()!=NULL){
//     if(temp->getNum()==b){
//       return true;
//     }
//     if(IslandArr[temp->getNum()].getV()==false){
//       IslandArr[temp->getNum()].markV();
//       //printf("from %d, to %d\n", temp->getNum(), b);
//       if(dfs(temp->getNum(), b)==true){
//         return true;
//       }
//       // else{
//       //   if(temp->getNext())
//       // }
//     }
//     temp=temp->getNext();
//   }
//   return false;
// }

stack breadthFirstSearch(int x, int y){

  int curI;
  for(int i =1; i<size; i++){
    IslandArr[i].markUV();
    IslandArr[i].setPre(-1);

  }
    IslandQue->removeAll();
    IslandQue->insertValue(x);
    //printf("%s\n", bfs(y, IslandQue));
    stackList->removeAll();
    if(bfs(y, IslandQue)==false){
      printf("You can NOT get from island %d to island %d\n", x, y );
      return *stackList;
    }
    else{
      printf("You can get from island %d to island %d\n", x, y);
      
      curI=y;
      stackList->insert_front(curI);
      //printf("%d\n", stackList->getListLength());
      do{
        // printf("%d\n", curI);
        // printf("%d\n", x);
        curI=IslandArr[curI].getPre();
        stackList->insert_front(curI);
      }while(curI!=x);
        // printf("%d\n", curI);
        // printf("%d\n", x);
      //------------------------------
      //printf("%d\n", stackList->getListLength());
  //----------------------------------
      return *stackList;
    }
  }
bool bfs(int b, queue* IslandQue){
  //printf("IN BFS %d\n", b);
  int a;
  while(IslandQue->gethead()!=NULL){
    //printf("testing\n");
    a=IslandQue->gethead()->getNum();
    IslandQue->delete_front();
    for(int i =0; i< IslandArr[a].getList()->getListLength(); i++){

      if(IslandArr[IslandArr[a].getList()->getNthValue(i)].getPre()==-1){
        //printf("testing for loop\n");
        IslandArr[IslandArr[a].getList()->getNthValue(i)].setPre(a);
        if(IslandArr[a].getList()->getNthValue(i)==b){
          return true;
        }
        IslandQue->insertValue(IslandArr[a].getList()->getNthValue(i));
      }
    }
  }
  return false;
}
  


 // The main loop for reading in input
 void processCommandLoop (FILE* inFile)
 {
  char  buffer[300];
  char* input;

  input = fgets ( buffer, 300, inFile );   // get a line of input
    
  // loop until all lines are read from the input
  while (input != NULL)
  {
    // process each line of input using the strtok functions 
    char* command;
    command = strtok (input , " \r\n\t");

    printf ("*%s*\n", command);
    
    if ( command == NULL )
      printf ("Blank Line\n");
 
    else if ( strcmp (command, "q") == 0){
      IslandQue->removeAll();
      delete IslandQue;
      stackList->removeAll();
      delete stackList;
      for(int i=0;i<size;i++){
      IslandArr[i].getList()->removeAll();
      delete IslandArr[i].getList();
      }
      delete[] IslandArr;
      fileInUse->removeAll();
      delete fileInUse;
      fclose(inFile);
      exit(1);
    }
     
    else if ( strcmp (command, "?") == 0) 
      showCommands();

    else if ( strcmp (command, "s") == 0) 
      doShortestPath();

    else if ( strcmp (command, "t") == 0) 
      doTravel();
     
    else if ( strcmp (command, "r") == 0) 
      doResize();

    else if ( strcmp (command, "i") == 0){ 
      doInsert();
      //doList();
    }
    else if ( strcmp (command, "d") == 0) 
      doDelete();

    else if ( strcmp (command, "l") == 0) 
      doList();

    else if ( strcmp (command, "f") == 0) 
      doFile();

    else if ( strcmp (command, "#") == 0) 
      ;
      //printf ("Command is not known: %s\n", command);
      
     
    else
      ;
      //printf ("Command is not known: %s\n", command);
     
    input = fgets ( buffer, 300, inFile );   // get the next line of input

  }
 }
 
 void showCommands()
 {
   printf ("The commands for this project are:\n");
   printf ("  q \n");
   printf ("  ? \n");
   printf ("  # \n");
   printf ("  s <int1> <int2> \n");
   printf ("  t <int1> <int2> \n");
   printf ("  r <int> \n");
   printf ("  i <int1> <int2> \n");
   printf ("  d <int1> <int2> \n");
   printf ("  l \n");
   printf ("  f <filename> \n");
 }
 
 void doTravel()
 {
   int val1 = 0;
   int val2 = 0;

   // get an integer value from the input
   char* next = strtok (NULL, " \r\n\t");
   
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val1 = atoi ( next );
   if ( val1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   // get another integer value from the input
   next = strtok (NULL, " \n\t");


   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val2 = atoi ( next );
   if ( val2 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   
   printf ("Performing the Travel Command from %d to %d\n", 
            val1, val2);
   //doList();
   depthFirstSearchHelper(val1, val2);
   
 }
 
 void doResize()
 {
    int val1 = 0;


  // get an integer value from the input
  char* next = strtok (NULL, " \r\n\t");
  //printf("%s\n", next);
  if ( next == NULL )
  {
   printf ("Integer value expected\n");
   return;
  }
  val1 = atoi ( next );
  if ( val1 == 0 && strcmp (next, "0") != 0)
  {
   printf ("Integer value expected\n");
   return;
  }
   printf ("Performing the Resize Command with %d\n", val1 );
   //size=val1;

  if(val1>0){
    for(int i=0;i<size;i++){
      IslandArr[i].getList()->removeAll();
      delete IslandArr[i].getList();
    }
    delete[] IslandArr;
    IslandArr=new Island[val1+1];
    size=val1+1;
  }

 }
 
 void doInsert()
 {
  int val1 = 0;
   int val2 = 0;

  // get an integer value from the input
  char* next = strtok (NULL, " \r\n\t");
  //printf("%s\n", next);
  if ( next == NULL )
  {
   printf ("Integer value expected\n");
   return;
  }
  val1 = atoi ( next );
  if ( val1 == 0 && strcmp (next, "0") != 0)
  {
   printf ("Integer value expected\n");
   return;
  }
  if(val1<1||val1>=size){
    printf("Invalid value for island\n");
    return;
  }
   next = strtok (NULL, " \r\n\t");
    val2 = atoi ( next );
  if ( val2 == 0 && strcmp (next, "0") != 0)
  {
   printf ("Integer value expected\n");
   return;
  }
  if(val2<1||val2>=size){
    printf("Invalid value for island\n");
    return;
  }

  else{
    printf ("Performing the Insert Command for %d\n", val1);
  }
  if(IslandArr[val1].getList()->pathexist(val2)==false){


  //printf("%d %d\n", val1, val2);
  IslandArr[val1].getList()->insertValue(val2);
  }
  else{
    printf("Ferry ride already added!\n");
    return;
  }
  //doList();
  //printf("%d\n", size);

 }
 
 void doDelete()
 {   
   int val1 = 0;
   int val2 = 0;

   // get an integer value from the input
   char* next = strtok (NULL, " \r\n\t");
   
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val1 = atoi ( next );
   if ( val1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   // get another integer value from the input
   next = strtok (NULL, " \n\t");


   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val2 = atoi ( next );
   if ( val2 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   if(val1>size-1||val1<=0){
        printf("Invalid value for island\n");
        return;
   }
    if(val2>size-1||val2<=0){
        printf("Invalid value for island\n");
        return;
   }
   printf ("Performing the Delete Command for %d\n", val1);

    if(IslandArr[val1].getList()->pathexist(val2)==true){

      IslandArr[val1].getList()->deleteValue(val2);
    }
  else{
    printf("Ferry ride does not exist\n");
    return;
  }
 }
 
 void doList()
 {
  printf ("Displaying the adjacency list:\n" );
  for (int i =1; i<size; i++){
    MyNode* temp= (IslandArr[i].getList())->gethead();
    printf("%d -->  ", i);
    while (temp!= NULL){
      printf ("%d  ", temp->getNum());
      temp = temp->getNext();
    }
    printf("\n");
  }
 }

 void doFile()
 {
  
   // get a filename from the input
   char* fname = strtok (NULL, " \r\n\t");
   if ( fname == NULL )
   {
     printf ("Filename expected\n");
     return;
   }
   FILE* pfile = fopen(fname, "r");
   if(pfile==NULL){
    printf("Cannot open the file\n");
    return;
   }
   if(fileInUse->fexist(fname)==false){
   

    fileInUse->insertValue(fname);
   printf ("Performing the File command with file: %s\n", fname);
   processCommandLoop(pfile);
   fclose(pfile);
 }
 else{
  printf ("Performing the File command with file: %s\n", fname);
  printf("File is already in use\n");
  fclose(pfile);
  return;
 }
   //make sure to remove file
   // next steps:  (if any step fails: print an error message and return ) 
   //  1. verify the file name is not currently in use
   //  2. open the file using fopen creating a new instance of FILE*
   //  3. recursively call processCommandLoop() with this new instance of FILE* as the parameter
   //  4. close the file when processCommandLoop() returns

 }
  void doShortestPath()
 {
   int val1 = 0;
   int val2 = 0;

   // get an integer value from the input
   char* next = strtok (NULL, " \r\n\t");
   
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val1 = atoi ( next );
   if ( val1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   // get another integer value from the input
   next = strtok (NULL, " \n\t");


   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val2 = atoi ( next );
   if ( val2 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
    if(val1>(size-1)||val1<=0){
        printf("Invalid value for island\n");
        return;
   }
    if(val2>(size-1)||val2<=0){
        printf("Invalid value for island\n");
        return;
   }
   printf("Performing the shortest pathCommand from %d to %d\n", val1, val2);
   // if(val1==1&&val2==4){
   // printf("checking \n");
   // }
  //printf("checking printf\n");
   breadthFirstSearch(val1, val2);
   if(stackList->gethead()!=NULL){
    printf("shortest path from %d to %d: ", val1, val2);
    stackList->printList();
  }
  //printf("checking printf after\n");
 }
};





int main (int argc, char** argv)
{
  // set up the variable inFile to read from standard input
  FILE* inFile = stdin;

  // set up the data needed for the island adjcency list
  ArchipelagoExpedition islandData;
   
  // call the method that reads and parses the input
  islandData.showCommands();
  printf ("\nEnter commands at blank line\n");
  printf ("    (No prompts are given because of f command)\n");
  islandData.processCommandLoop (inFile);
   
  printf ("Goodbye\n");
  return 1;
 }
