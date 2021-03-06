#include <stdio.h>
#include <time.h>
#include <stdlib.h>



#define r rand()

#define ARRAYSIZE 25


void quicksort(int array[], int lo, int hi);


void printArray(int array[]);

int main(){
  srand(time(NULL));

  //  int ARRAYSIZE = (r % 50);
  int myarray[ARRAYSIZE];

  int i;
  for(i = 0; i < ARRAYSIZE; i++){
    myarray[i] = r % 100;
  }

  printArray(myarray);

  quicksort(myarray, 0, ARRAYSIZE - 1);

  printArray(myarray);

  return 0;
}

void printArray(int array[]){
  int i;
  int arrayunitsize = sizeof(array[0]);
  int arraylen = ARRAYSIZE;
  printf("The array is... \n\tUnit Size: %d \n\tArray Lenght: %d \n\tUnits: ", arrayunitsize, arraylen);
  for(i = 0; i < arraylen; i++){

    printf("%d", array[i]);
    if (i < arraylen - 1){
      printf(", ");
    }
  }
  printf("\n");


}


void quicksort(int array[], int lo, int hi){
  int i = lo, j = hi;
  int tmp;
  int pivot = array[(lo+hi)/2];

  /* partition */
  while(i <= j){
    while(array[i] < pivot)
      i++;
    while(array[j] > pivot)
      j--;
    if(i <= j){
      tmp = array[i];
      array[i] = array[j];
      array[j] = tmp;
      i++;
      j--;
    }
  }
  if (lo < j)
    quicksort(array, lo, j);
  if (i < hi)
    quicksort(array, i, hi);
}




