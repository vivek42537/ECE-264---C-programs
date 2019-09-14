// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>

#ifdef TEST_ADDFILE
bool addFile(char * filename, int * sum)
{
	* sum = 0; // You cannot assume * sum is zero. Thus, * sum needs to be set 0
	FILE * fur = fopen(filename, "r");// open a file whose name is filename for reading

	int i;
	// if fopen fails, return false. Do NOT fclose
	if (fur == NULL)// if fopen succeeds, read integers using fscan (do not use fgetc)
	{
		return false;
	}
	else 
	{
		while(!feof(fur))
		{
		
			if(fscanf(fur, "%d", &i) == 1)
				*sum += i;
		}
		//
		// * sum stores the result of adding all numbers from the file
		fclose(fur);// When no more numbers can be read, fclose, return true
		//
		return true;
	}
}
#endif


#ifdef TEST_WRITESUM
bool writeSum(char * filename, int sum)
{
	FILE * furr = fopen(filename, "w");// open a file whose name is filename for writing
		// if fopen succeeds, write sum as an integer using fprintf
        if (furr == NULL) // fprintf should use one newline '\n'
	{
		return false;
        }
	else
	{
		fprintf(furr,"%d\n",sum);		// fclose, return true
	}
	fclose(furr);				//
	return true;
	
}
#endif


