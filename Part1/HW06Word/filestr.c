// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifdef TEST_COUNTWORD
int countWord(char * filename, char * word, char * line, int size)
{
  // filename: name of the input file
  // word: the word to search
  // line: temporary space to store what is read from the file
  // size: size of line
  FILE * fur = fopen(filename, "r");  // open a file whose name is filename for reading
  if (fur == NULL)
  {
   return -1;
  }
  else 
  {
   // if fopen fails, return -1. 
  int sum = 0;// if fopen succeeds, set sum to zero
  // use fgets to read the file
  
  int i;
  char * donde; 
  while((fgets(line, size, fur)) != NULL)// if word appears in a line, add one to sum
  {
	i = 0;
	
  	while ((donde = strstr(line + i, word)) != NULL)// It is possible that the same word appears multiple times in a line
  	{// If this word is split in two or more lines, do not count the word.
  		i = (donde - line) + strlen(word);
		sum++;
	}
   }
  
  // It is also possible that a long line is split by fgets. If this happens,
  // do not count the word.
  //
  // return sum
  //
  // If a line is "aaaaa" and the word is "aa", how is the count defined?
  // In this assignment, the first two letters are consumed when the
  // the first match occurs. Thus, the next match starts at the third
  // character. For this case, the correct answer is 2, not 4.
  
   return sum;
  }
}
#endif
