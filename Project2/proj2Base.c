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
    printf("The stack has grown from %d to %d, and a total of %dvalues were copied into the larger array.\n", theStack->inUse, theStack->allocated, theStack->inUse);

    free(temp); // deallocate

    if (debugMode == true)
      printf("Character %c was pushed into the stack.\n", value);
  }
  
  // add value to stack and update size
  theStack->dArray[ theStack->inUse] = value; 

  theStack->inUse++;
  


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
  

   while (ptr != NULL)
   {  
      strcpy(wordList[j], ptr); 
      ptr = strtok(NULL, delim);
      j++;

   }
   /*Run the algorithm to decode the message*/
for (int wordIndex = 1; wordIndex <= j; ++wordIndex) {
    printf ("\nTESTING 1\n");
      int letterIndex = 0;
      bool isWord;
      isWord = true;
      
      // loop through the characters of each word
      while ( wordList[ wordIndex][ letterIndex] != '\0') {
        char letter = wordList[wordIndex][letterIndex];
        
        // add character to stack if it is from L
        if (letter >= 'a' && letter <= 'd') {
             printf ("\nTESTING 2\n");

          push(&L, letter);
        }
        // compare character to top of stack if it is from L2
        else if (letter >= 'm' && letter <= 'p') {
          if (!is_empty(&L)) {
            // check if dummy alphabet matches to main alpahbet, else reject word
            if (letter == top(&L) + 12) {
                   printf ("\nTESTING 3\n");

              pop(&L);
            }
            else {
              isWord = false;
               //printf ("No valid word decoded.\n");
            }
          }
        }
        
        letterIndex++;
        if (!isWord) break; // skip to next
      }
      
      if (!is_empty( &L)) isWord = false; // stack should be empty if not dummy word
      
      // decrypt and output non-dummy words
      if (isWord) {
        RemoveExtraLetters( wordList[wordIndex]);
        printf( "%s ", wordList[wordIndex]);
            printf ("\nTESTING 4\n");

      }

      clear(&L); // empty stack for next word

    }


 }


 printf ("\nGoodbye\n");
 return 0;
}
