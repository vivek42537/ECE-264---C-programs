// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifdef TEST_COUNTINT
int countInt(char * filename)
{
	// count the number of integers in the file
	// Please notice that if a file contains
	// 124 378 -56
	// There are three integers: 124, 378, -56
	// DO NOT count individual character '1', '2', '4' ...
	//
	// If fopen fails, return -1
	FILE * fur = fopen(filename, "r");

	int i;
	int c;
	c = 0; 

	if (fur == NULL)
	{
		return -1;
	}
	else
	{
		while(!feof(fur))
		{
			if(fscanf(fur, "%d", &i) == 1)
			{
				c++;
			}
		}

		fclose(fur);
		return c;
	}	
	// remember to fclose if fopen succeeds
}
#endif

#ifdef TEST_READINT
bool readInt(char* filename, int * intArr, int size)
{
	// if fopen fails, return false
	// read integers from the file.
	// 
	//
	// if the number of integers is different from size (too
	// few or too many) return false
	// 
	// if everything is fine, fclose and return true
	FILE * furr = fopen(filename, "r");
	int c;
	c = 0;
	if(furr == NULL)
	{
		return false;
	}
	else{
	while(!feof(furr))
	{
		if(fscanf(furr, "%d", &intArr[c]) == 1)
		{
			c++;
		}
	}
	if (c != size)
	{
		return false;
	}
	else{
		return true;
	}
	fclose(furr);
	}
}
#endif

#ifdef TEST_COMPAREINT
int compareInt(const void *p1, const void *p2)
{
	// needed by qsort
	//
	// return an integer less than, equal to, or greater than zero if
	// the first argument is considered to be respectively less than,
	// equal to, or greater than the second.
	if (*(int*)p1 < *(int*)p2) 
		return -1;
	else if (*(int*)p1 > *(int*)p2)
		return 1;
	else 
		return 0; 
}
#endif

#ifdef TEST_WRITEINT
bool writeInt(char* filename, int * intArr, int size)
{
	// if fopen fails, return false
	// write integers to the file.
	// one integer per line
	// 
	// fclose and return true
	FILE * fub = fopen(filename, "w");
	int ii;
	if (fub == NULL)
	{
		return false;
	}
	else
	{
		for(ii = 0; ii<size; ii++)
		{
			fprintf(fub, "%d\n", intArr[ii]);
		}
		fclose(fub);
		return true;
	} 
}
#endif
