#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void copyArray(int fromArray[], int toArray[], int size) {
  for (int i = 0; i < size; i++) {
    toArray[i] = fromArray[i];
  }
}



void indexComparison (int arr[], int sorted[], int size, int *counter) {
  *counter = 0;
  for ( int i = 0; i < size; i++) {
    if (arr[i] == sorted[i]) {
      (*counter)++;
    }
  }
  return;
}

int targetSum (int arr[], int size, int target, int* index1, int* index2) {
  *index1 = 0;
  *index2 = size - 1;

  while (*index1 != *index2) {
    if ( arr[*index1] + arr[*index2] == target) {
      return 1; //found
    }
    else if ( arr[*index1] + arr[*index2] < target) { //small
      ++(*index1);
    }
    else { //large
      --(*index2);
    }
  }
  return -1; //not found
}

void quicksort(int arr[], int first, int last){
 int i, j, pivot, temp;

 if (first < last){
    pivot = first;
    i = first;
    j = last;
    while(i < j){
       while(arr[i] <= arr[pivot] && i < last)
          i++;
       while(arr[j] > arr[pivot])
          j--;
       if(i < j){
          temp = arr[i];
          arr[i] = arr[j];
          arr[j] = temp;
       }
    }

    temp = arr[pivot];
    arr[pivot] = arr[j];
    arr[j] = temp;
    quicksort(arr, first, j-1);
    quicksort(arr, j+1, last);
  }
}

int main (int argc, char** argv) {
  int val;
  int counter;
  /* prompt the user for input */
  printf ("Enter in a list of numbers to be stored in a dynamic array.\n");
  printf ("End the list with the terminal value of -999\n");

  /* Create an empty array */
   int *darr;
  int allocated =4;
  
  darr = (int *) malloc (allocated * sizeof(int) );
  int size = 0;
  int matches;

  /* loop until the user enters -999 */
  scanf ("%d", &val); // take initial input
  
  while (val != -999) {
    /* double size of array it is full */
    if ( size == allocated) {
      int *temp = darr;
      darr = (int *) malloc ( allocated * 2 * sizeof(int) );
      for ( int i = 0; i < allocated; i++) darr[i] = temp[i];
      free(temp);
      allocated = allocated * 2;
    }

    /* store the value into an array */
    darr[size] = val;
    size++;
    
    /* get next value */
    scanf("%d", &val);
  }

  /* call function to make a copy of the array of values */
  int *sortedArray = (int *) malloc (size * sizeof(int));
  copyArray(darr, sortedArray, size);

 quicksort(sortedArray, 0, size - 1);
 /* Call function to count matches, and report results. */
  printf("Enter 1 to perform index comparison, enter 2 to perform target sum.\n"); 
  scanf("%d", &val);
  while(1){
  if (val == 1){
    indexComparison(sortedArray, darr, size, &counter);
    if(counter==size||counter==0){
      printf("All elements change location in the sorted array.\n");
      //printf("%d values are in the same location in both arrays.\n", counter);
    }
    else{
     //printf("All elements change location in the sorted array.\n");
      printf("%d values are in the same location in both arrays.\n", counter);
    }
    break;
    } // matches / currSize
 /* loop until the user enters -999 */
  else if(val==2){
  int index1;
  int index2;

  /* loop until the user enters -999 */
  printf ("Enter in a list of numbers to use for searching.  \n");
  printf ("End the list with a terminal value of -999\n");
  scanf ("%d", &val);
  while (val != -999) {
    /* call function to perform target sum operation */
    if (targetSum(sortedArray, size, val, &index1, &index2) == 1) { // TwoSum Succeeded

      /* print out info about the target sum results  */
      printf("Success! Elements at indices %d and %d add up to %d\n", index1, index2, val);
    }
    else { // TwoSum Failed
      printf("Target sum failed! \n");
    }

    /* get next value */
    scanf("%d", &val);
    }
    break;
  }
  else{
    printf("Invalid input. Enter 1 or 2. \n");
    scanf("%d", &val);
  }
}

  printf ("Good bye");
  return 0;
}