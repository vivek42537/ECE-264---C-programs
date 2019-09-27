// ***
// *** You must modify this file
// ***
#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "hw08.h"

#ifdef TEST_COUNTVECTOR
int countVector(char * filename)
{
  // count the number of vectors in the file and return the number
  // The input is a binary file. You must use fread.
  // You must not use fscanf(, "%d", ) 
  //
  // If fopen fails, return -1
  //
  //
  // For the mode of fopen, you may use "r" without b
  //
  FILE * fur = fopen(filename, "r");
  int c=0; // c 
  Vector v;
  if (fur == NULL)
  {
   return -1;
  }
  else
  { 
   while (((fread(&v, sizeof(Vector), 1, fur)) == 1))
   {
     c++;
   }
  }
   
  fclose(fur);  

  return c;
}
#endif

#ifdef TEST_READVECTOR
bool readVector(char* filename, Vector * vecArr, int size)
{
  // if fopen fails, return false
  // read Vectors from the file.
  // 
  //
  // if the number of integers is different from size (too
  // few or too many) return false
  // 
  // if everything is fine, fclose and return true
  FILE * furr = fopen(filename, "r");

  if (furr == NULL)
  {
   return false;
  }
  else
  {
   if (((fread(vecArr, sizeof(Vector), size, furr)) == size))
   {
     fclose(furr);
     return true;
   }  
   else
   {
    fclose(furr);
    return false;   
   }
  }
}
#endif

#ifdef TEST_COMPAREVECTOR
int compareVector(const void *p1, const void *p2)
{
  // compare the x attribute first
  // If the first vector's x is less than the second vector's x
  // return -1
  // If the first vector's x is greater than the second vector's x
  // return 1
  // If the two vectors' x is the same, compare the y attribute
  //
  // If the first vector's y is less than the second vector's y
  // return -1
  // If the first vector's y is greater than the second vector's y
  // return 1
  // If the two vectors' y is the same, compare the z attribute
  //
  // If the first vector's z is less than the second vector's z
  // return -1
  // If the first vector's z is greater than the second vector's z
  // return 1
  // If the two vectors' x, y, z are the same (pairwise), return 0
  const Vector * ptr1 = (const Vector *) p1;
  const Vector * ptr2 = (const Vector *) p2;
  Vector v1 = * ptr1;
  Vector v2 = * ptr2;

  if (v1.x < v2.x)
  {
   return -1;
  }
  else if (v1.x > v2.x)
  {
   return 1;
  }
  else if (v1.x == v2.x)
  {
   if (v1.y < v2.y)
   {
    return -1;
   }
   else if (v1.y > v2.y)
   {
    return 1;
   }
   else if (v1.y == v2.y)
   {
    if (v1.z < v2.z)
    {
     return -1;
    }
    else if (v1.z > v2.z)
    {
     return 1;
    }
    else if (v1.z == v2.z)
    {
     return 0;
    }
   }
  }
 return 0;
}
#endif

#ifdef TEST_WRITEVECTOR
bool writeVector(char* filename, Vector * vecArr, int size)
{
  // if fopen fails, return false
  // write the array to file using fwrite
  // need to check how many have been written
  // if not all are written, fclose and return false
  // 
  // fclose and return true
  FILE * fum = fopen(filename, "w");
  int w; // how many written
 
  if (fum == NULL)
  {
   return false;
  }
  w = fwrite(vecArr, sizeof(Vector), size, fum);
 
  if (w != size)
  {
   fclose(fum);
   return false;
  }  
   
  fclose(fum);
  return true;
}
#endif

// This function is provided to you. No need to change
void printVector(Vector * vecArr, int size)
{
  int ind = 0;
  for (ind = 0; ind < size; ind ++)
    {
      printf("%6d %6d %6d\n",
	     vecArr[ind].x, vecArr[ind].y, vecArr[ind].z);
    }
}
