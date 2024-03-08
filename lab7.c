#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
int temp = *x;
*x = *y;
*y = temp;
}

typedef struct element{
  int data;
  int numSwap;
}element;

void bubbleSort(int array[], int n)
{
  element* swapped = (element*)malloc(sizeof(element)*n);
  for(int i =0; i < n; i++)
    {
      swapped[i].data = array[i];
      swapped[i].numSwap = 0;
    }
  
  int total = 0;
  for(int i = 0; i < n-1; i++)
    {
      for(int j = 0; j < n-i-1; j++)
        {
          if(swapped[j].data > swapped[j+1].data)
          {
            swap(&swapped[j].data, &swapped[j+1].data);
            total++;

            swapped[i].numSwap++;
            
          }
        }
    }
  
  for(int i = 0; i < n; i++)
    {
      printf("%d: %d\n", swapped[i].data, swapped[i].numSwap);
    }
  printf("%d\n", total);
  
}

void selectionSort(int array[], int n)
{
  element* swapped = (element*)malloc(sizeof(element)*n);
  for(int i =0; i < n; i++)
    {
      swapped[i].data = array[i];
      swapped[i].numSwap = 0;
    }
  int total = 0;
  int min;
  int numswap = 0;
  for(int i = 0; i< n-1; i++)
    {
      min = i;
      for(int j= i+1; j < n;j++)
        {
          if(swapped[j].data < swapped[min].data)
          {
             min = j;
          }
        }
        swap(&swapped[min].data,&swapped[i].data);
        swapped[i].numSwap++;
        total++;
        
    }
  for(int i = 0; i < n; i++)
    {
      printf("%d: %d\n", swapped[i].data, swapped[i].numSwap);
    }
  printf("%d\n", total);
  
}

int main(void) {
  int arr1[] = {97,  16,  45,  63,  13,  22,  7,  58,  72};
  int arr2[]= {90,  80,  70,  60,  50,  40,  30,  20,  10};

  int n1 = 9;
  int n2 = 9;
  

  printf("array 1: bubble sort\n");
  bubbleSort(arr1, n1);

  printf("array 2: bubble sort\n");
  bubbleSort(arr2, n2);
  

  printf("array 1: selection sort\n");
  selectionSort(arr1, n1);
  
  printf("array 2: selection sort\n");
  selectionSort(arr2, n2);
  
}