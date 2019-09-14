// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h> 

#ifdef TEST_ELIMINATE
// 100% of the score
void eliminate(int n, int k)
{
 // allocate an arry of n elements
  int * arr = malloc(sizeof(* arr) * n);
  // check whether memory allocation succeeds.
  // if allocation fails, stop
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }
  // initialize all elements
  for (int i = 0; i < n; i++)
    { 
      arr[i] = 0;
    }

  int q = 0; //array counter i.e 1,2,3
  int l = n; // elements left

  for(int j = 0; l > 0; j++)
    {
     if (arr[j - 1] == 'X') //in order to skip X count
	{
	 q = q - 1;
	}
    
     if (q % k == 0 && q != 0) //marks x
	{
	 arr[j - 1] = 'X';
	 l = l - 1;
	 q = 0;
	 printf("%d\n",j-1);
	} 
     
     if (j % n == 0)
	{
	 j = 0;
	}
     q++;
    }

  
  // counting to k,
  // mark the eliminated element
  // print the index of the marked element
  // repeat until only one element is unmarked




  // print the last one




  // release the memory of the array
  free (arr);
}
#endif
