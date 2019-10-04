// ***
// *** You must modify this file
// ***
#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "hw09.h"

// DO NOT MODIFY --->>>> From Here
// Do not modify this function. It is used for grading.
void printInput(char * msg, int * arr, int l, int m, int r)
{
  printf("%s(%6d, %6d, %6d)", msg, l, m, r);
  int ind;
  for (ind = l; ind <= r; ind ++)
    {
      printf("%d\n", arr[ind]);
    }
}
// DO NOT MODIFY <<<<--- Until Here

#ifdef TEST_READDATA
// the input file is binary, storing integers
//
// arr stores the address of a pointer for storing the
// address of the allocated memory
//
// size stores the address keeping the size of the array
bool readData(char * filename, int * * arr, int * size)
{
  // use fopen to open the file for read
  // return false if fopen fails
  FILE * fur = fopen(filename, "r");  

  if (fur == NULL)
  {
   fclose(fur);
   return false;
  }
   


  // use fseek to go to the end of the file
  // check whether fseek fails
  // if fseek fails, fclose and return false
  int sick = fseek(fur, 0, SEEK_END);
  if (sick != 0)
  {
   fclose(fur);
   return false;
  }
   

  // use ftell to determine the size of the file
  int thicc;
  thicc = ftell(fur);


  
  // use fseek to go back to the beginning of the file
  // check whether fseek fails
  sick = fseek(fur, 0, SEEK_SET);
  if (sick != 0)
  {
   fclose(fur);
   return false;
  }
  
  // if fseek fails, fclose and return false

  // the number of integers is the file's size divided by
  // size of int  
  int numElem;
  numElem = thicc / sizeof(int);

  // allocate memory for the array


  // if malloc fails, fclose and return false
  int *newarr = malloc(numElem * sizeof(int)); 
       
  if (newarr == NULL)
  {
   fclose(fur);
   free(newarr);
   return false;
  }
  

  int red;
  red = fread(newarr, sizeof(int), numElem, fur);
  // use fread to read the number of integers in the file
  if (red != numElem)
   {
     free(newarr);
     fclose(fur);
     return false;
   } 
  fclose(fur);
    


  // if fread does not read the correct number
  // release allocated memory
  // fclose
  // return false




  
  // if fread succeeds
  // close the file

  
  // update the argument for the array address
  *arr = newarr;
  *size = numElem;
  
  // update the size of the array


  return true;
}
#endif

#ifdef TEST_WRITEDATA
// the output file is binary, storing sorted integers
// write the array of integers to a file
// must use fwrite. must not use fprintf
bool writeData(char * filename, const int * arr, int size)
{
  // fopen for write
  FILE * furr = fopen(filename, "w");


  // if fopen fails, return false
  if(furr == NULL)
  {
   return false;
  }


  // use fwrite to write the entire array to a file
  int i;
  i = fwrite(arr, sizeof(int), size, furr);


  // check whether all elements of the array have been written
  if (i != size)
  {
   fclose(furr);
   return false;
  }

  fclose(furr);
  return true;


  // fclose


  
  // if not all elements have been written, return false



  // if all elements have been written, return true





}
#endif


#ifdef TEST_MERGE
// input: arr is an array and its two parts arr[l..m] and arr[m+1..r]
// are already sorted
//
// output: arr is an array and all elements in arr[l..r] are sorted
//
// l, m, r mean left, middle, and right respectively
//
// You can assume that l <= m <= r.
//
// Do not worry about the elements in arr[0..l-1] or arr[r+1..]

static void merge(int * arr, int l, int m, int r)
// a static function can be called within this file only
// a static function is invisible to other files
{
  // at the beginning of the function
#ifdef DEBUG
  // Do not modify this part between #ifdef DEBUG and #endif
  // This part is used for grading. 
  printInput("Merge in", arr, l, m, r);
#endif

  // Hint: you may consider to allocate memory here.
  // Allocating additiional memory makes this function easier to write
  int n1 = m - l + 1;
  int n2 = r - m;

  int *left = malloc(sizeof(int) * n1);
  int *right = malloc(sizeof(int) * n2);

  for(int b = 0; b < n1; b++)
  {
   left[b] = arr[l + b];
  }
  for(int j = 0; j < n2; j++)
  {
   right[j] = arr[m + 1 + j];
  }
  // merge the two parts (each part is already sorted) of the array
  // into one sorted array
  int b = 0;
  int j = 0;
  int k = l;
  while (( b < n1) && (j < n2))
  {
   if (left[b] <= right[j])
   {
    arr[k] = left[b];
    b++;
    k++;
   }
   else if (left[b] > right[j])
   {
    arr[k] = right[j];
    j++;
    k++;
   }
  }
  
 while (b < n1)
 {
  arr[k] = left[b];
  b++;
  k++;
 }
 
 while (j < n2)
 {
  arr[k] = right[j];
  j++;
  k++;
 }
 
 free(left);
 free(right);  


  // the following should be at the bottom of the function
#ifdef DEBUG
  // Do not modify this part between #ifdef DEBUG and #endif
  // This part is used for grading. 
  printInput("Merge out", arr, l, m, r);
#endif
}
#endif

// merge sort has the following steps:

// 1. if the input array has one or no element, it is already sorted
// 2. break the input array into two arrays. Their sizes are the same,
//    or differ by one
// 3. send each array to the mergeSort function until the input array
//    is small enough (one or no element)
// 4. sort the two arrays 
#ifdef TEST_MERGESSORT
void mergeSort(int arr[], int l, int r) 
{
  // at the beginning of the function
#ifdef DEBUG
  // Do not modify this part between #ifdef DEBUG and #endif
  // This part is used for grading. 
  printInput("mergeSort", arr, l, r, -1);
#endif

  // if the array has no or one element, do nothing
  if (l < r)
  {
   int m = (l + r)/2;
   mergeSort(arr, l, m);
   mergeSort(arr, m+1, r);

   merge(arr, l, m, r); 
  }

  // divide the array into two arrays
  // call mergeSort with each array
  // merge the two arrays into one
  




} 
#endif
