#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct stack {
  int* dArray;
  int allocated;
  int inUse;
} stack;

stack* init() {
  stack theStack;
  theStack.dArray = ( int *) malloc ( 4 * sizeof( int));
  theStack.allocated = 4;
  theStack.inUse = 0;
  stack* stackPtr = &theStack;
  return stackPtr;
}

bool is_empty(stack* theStack) {
  if ( theStack->inUse == 0) {
    return true;
  }
  else {
    return false;
  }
}

char top(stack* theStack) {
  return theStack->dArray[theStack->inUse-1];
}

bool debugMode;

void pop(stack* theStack) {
  --theStack->inUse;

  if (debugMode == true){
   printf("Character %c was popped from the stack.\n", theStack->dArray[theStack->inUse]);
}
}


void push(stack* theStack, char value) {
  //grow the stack if it is full
  if (theStack->inUse == theStack->allocated) {
    theStack->allocated += 4;
    int* temp = theStack->dArray;
    theStack->dArray = (int*) malloc (theStack->allocated * sizeof(int));
    
    //copy all elements
    for (int i = 0; i < theStack->inUse; ++i) {
      theStack->dArray[i] = temp[i];
    }
    printf("The stack has grown from %d to %d, and a total of %d values were copied into the larger array.\n", theStack->inUse, theStack->allocated, theStack->inUse);

    free(temp); // deallocate

    
  }
  if (debugMode == true)
      printf("Character %c was pushed into the stack.\n", value);
  // add value to stack and update size
  theStack->dArray[theStack->inUse] = value; 

  theStack->inUse++;
  
}

void clear(stack* theStack) {
  for (int i = 0; i < theStack->inUse; ++i) {
    theStack->dArray[i] = '\0';
  }
  theStack->inUse = 0;
}

void RemoveExtraLetters (char *str) {
  int size = strlen(str); 
  int j = 0;
  
  for (int i = 0; i < size; i++) {
    if (str[i] >= 'a' && str[i] <= 'd') { 
      str[ j] = str[ i];
      ++j;
    } 
  }
  str[ j] = '\0';
}

int main(int argc, char const *argv[])
{
   debugMode = false;
   for (int i = 0 ; i < argc ; i++ ){
      if (strcmp (argv[i], "-d") == 0 ){
      debugMode = true;
      }
   }
   char input[300];
   stack L = *(init());
    /* set up an infinite loop */
 while (1)
 {
   /* get line of input from standard input */
   printf ("\nEnter input to check or q to quit\n");
   fgets(input, 300, stdin);
   
   
  
   /* remove the newline character from the input */
   int i = 0;
   while (input[i] != '\n' && input[i] != '\0')
   {
      i++;
   }
   input[i] = '\0';


   /* check if user enter q or Q to quit program */
   if ((strcmp (input, "q") == 0) || (strcmp (input, "Q") == 0))
     break;
 
   printf ("%s\n", input);
   /*Start tokenizing the input into words separated by space
    We use strtok() function from string.h*/
   /*The tokenized words are added to an array of words*/
   
   char delim[] = " ";
   char *ptr = strtok(input, delim);
   int j = 0 ; 

   //Needs proper allocation
   char *wordList[15];
  //*wordList = (char*)malloc(4*sizeof(char));

   while (ptr != NULL)
   {  
      wordList[j] = (char*)malloc((strlen(ptr)+1)*sizeof(char));
      strcpy(wordList[j], ptr); 
      ptr = strtok(NULL, delim);
      j++;

   }
   /*Run the algorithm to decode the message*/
for (int wordIndex = 0; wordIndex < j; ++wordIndex) {
    //printf ("\nTESTING 1\n");
      int letterIndex = 0;
      bool isWord;
      isWord = true;
      
      // loop through the characters of each word
      while ( wordList[wordIndex][letterIndex] != '\0') {
        char letter = wordList[wordIndex][letterIndex];
        
        // add character to stack if it is from L
        if (letter >= 'a' && letter <= 'd') {
             //printf ("\nTESTING 2\n");

          push(&L, letter);
        }
        // compare character to top of stack if it is from L2
        else if (letter >= 'm' && letter <= 'p') {
          if(wordList[wordIndex][letterIndex] == 'm' && top(&L) == 'a'){
          pop(&L);
        }
        else if(wordList[wordIndex][letterIndex] == 'n' && top(&L) == 'b'){
          pop(&L);
        }
        else if(wordList[wordIndex][letterIndex] == 'o' && top(&L) == 'c'){
          pop(&L);
        }
        else if(wordList[wordIndex][letterIndex] == 'p' && top(&L) == 'd'){
          pop(&L);
        }
        }
        
        letterIndex++;
        if (!isWord) break; // skip to next
      }
      
      if (!is_empty( &L)){
      isWord = false; // stack should be empty if not dummy word
               printf("No valid word decoded.\n" );
}
      // decrypt and output non-dummy words
      char store[15];
        int i =0;
      if (isWord) {
        RemoveExtraLetters( wordList[wordIndex]);
        // string store;
        // store = store + wordList[wordIndex];
        // char store[15];
        // int i =0;
         // store[i] = (char*)malloc((strlen(wordList[wordIndex])+1)*sizeof(char));
         // store[i]=store[i]+wordList[wordList];
         // i++;
       //store=store+wordList[wordIndex];
        //printf( "%s ", wordList[wordIndex]);
        //    printf ("\nTESTING 4\n");

      }
      
      // for(int k = 0; k<strlen(store[]);k++){
      //    printf("%s\n", store[k]);
      // }

      clear(&L); // empty stack for next word

    }
    //printf( "%s ", store);//-----------------
        // printf("No valid word decoded.\n" );
    //printf("%s\n", store);


 }


 printf ("\nGoodbye\n");
 return 0;
}
