// ***
// *** You MUST modify this file, only the ssort function
// ***

#include <stdio.h>
#include <stdbool.h>

#ifdef TEST_COUNTCHAR
bool countChar(char * filename, int * counts, int size)
{
	FILE * fur = fopen(filename, "r");	// open a file whose name is filename for reading
	if(fur == NULL)
	{
		return false;	// if fopen fails, return false. Do NOT fclose
	}	// if fopen succeeds, read every character from the file

	int onechar;
	do
	{
		onechar = fgetc(fur);
		printf(" %c %d\n", onechar, onechar);
	}   while (onechar != EOF);


	if((0 <= onechar) && (onechar <= (size - 1)))
	{	
		counts[onechar]++;
	}
	// if a character (call it onechar) is between
	// 0 and size - 1 (inclusive), increase
	// counts[onechar] by one
	// You should *NOT* assume that size is 256
	// reemember to call fclose
	// you may assume that counts already initialized to zero
	// size is the size of counts
	// you may assume that counts has enough memory space
	//
	// hint: use fgetc
	// Please read the document of fgetc carefully, in particular
	// when reaching the end of the file
	//
	fclose(fur);
	return true; 
}
#endif

#ifdef TEST_PRINTCOUNTS
int ind;
void printCounts(int * counts, int size)
{
	// print the values in counts in the following format
	// each line has three item
	if (('a' <= ind) && (ind <= 'z') && ('A' <= ind) && (ind <= 'Z'))
	{
		printf("%d, %c, %d\n", ind, ind, counts[ind]);	// ind, onechar, counts[ind]
	}    	// ind is between 0 and size - 1 (inclusive)
	else if (counts[ind] != 0)
	{
		printf(" ");	// onechar is printed if ind is between 'a' and 'z' or
	}	// 'A' and 'Z'. Otherwise, print space
	// if counts[ind] is zero, do not print
}
#endif
