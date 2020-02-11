#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shell_array.h"



long * Array_Load_From_File(char *filename, int *size)
{
  FILE *fur = fopen(filename,"rb"); //open file
  *size = 0;
  if(fur == NULL)
  {
    return NULL;
  }
  fseek(fur, 0, SEEK_END); //size of file
  *size = ftell(fur)/sizeof(long);
  fseek(fur, 0, SEEK_SET);

  long *arr = (long *) malloc(*size *sizeof(long));
  

  for(int i = 0; i < *size; i++)
  {
    fread(&arr[i], sizeof(long), 1, fur);
  }
  fclose(fur);
  return arr;
}

int Array_Save_To_File(char *filename, long *array, int size)
{
  FILE *furo = fopen(filename, "wb");
  int i = 0;
  if(filename == NULL)
  {
    return -1;
  }
  fseek(furo,0, SEEK_SET);

    i = fwrite(array, sizeof(long), size, furo);
    

  fclose(furo);
  return i;
}

void Array_Shellsort(long *array, int size, long *n_comp)
{
  int k = 1;
  while(k <= size)
  {
    k = 3*k +1;
  }
  k = (int)((k - 1) / 3);

  for(; k > 0; k = (int)((k - 1) / 3))
  {
    for(int i = k; i < size; i+= 1)
    {
      long temp = array[i];
      int j = i;
      (*n_comp)++;
      while(j >= k && temp < array[j-k])
      {
        array[j] = array[j-k];
        j = j - k;
      }
      array[j] = temp;
    }
  }
  

}
