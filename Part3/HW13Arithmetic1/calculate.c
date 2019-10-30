// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "calculate.h"

// DO NOT MODIFY FROM HERE --->>>
const int Operations[] = {'+', '-', '*'};

// return -1 if the word is not an operator
// return 0 if the word contains '+'
// return 1 if the word contains '-'
// ...
int isOperator(char * word)
{
	int ind;
	int numop = sizeof(Operations) / sizeof(int);
	for (ind = 0; ind < numop; ind ++)
	{
		char *loc = strchr(word, Operations[ind]);
		if (loc != NULL && !isdigit(loc[1]))
		{
			return ind;
		}
	}
	return -1;
}
// <<<--- UNTIL HERE

// ***
// *** You MUST modify the calculate function
// ***
#ifdef TEST_CALCULATE
// if arithlist is NULL, return true
// if arithlist -> head is NULL, return true
// if the input list is invalid, return false
bool calculate(List * arithlist)
{
	if (arithlist == NULL)
		return true;  
        
        if ((arithlist -> head) == NULL)
		return true;

	// go through the list until there is only node in the list
	// find the next operator
	// If no operator can be found, return false
	// If an operator is found, find the two previous nodes as operands
	// If cannot find previous two operands, return false
	// If two operands can be found, perform the arithmetic operation
	// Be careful, subtraction is no commutative: 4 2 - means 4 - 2,
	//    not 2 - 4
	// After the operation,
	//     put the result back to the list
	//     remove the two nodes used to store the two operands
	// After going through the entire list and performing the operations,
	//     the list should have exactly one node left. If this is not
	//     true, return false
	// If the input is valud, return true
	ListNode * rush = arithlist->head;
	while(rush != NULL)
	  {
		if(isOperator(rush->word) == -1)
	        {  
		}
		
		else
		{
		  int d = 0;
		  int s = 0;
		  if(isOperator(rush->word) == 0)
		  {
			if((rush->prev == NULL) || (rush->prev->prev == NULL))
				return false;
			
			else
			{
				d = strtol((rush->prev->prev->word), NULL, 10);
				s = strtol((rush->prev->word), NULL, 10);
				int sd = s + d;
				sprintf(rush->word, "%d\n", sd);
				deleteNode(arithlist, rush->prev->prev);
				deleteNode(arithlist, rush->prev);
			}
		  }

		  if(isOperator(rush->word) == 1)
		  {
			if((rush->prev == NULL) || (rush->prev->prev == NULL))
				return false;
			
			else
			{
				d = strtol((rush->prev->prev->word), NULL, 10);
                                s = strtol((rush->prev->word), NULL, 10);
                                int sd = -s + d;
                                sprintf(rush->word, "%d\n", sd);
                                deleteNode(arithlist, rush->prev->prev);
                                deleteNode(arithlist, rush->prev);
			}
		  }

		  if(isOperator(rush->word) == 2)
                  {
                        if((rush->prev == NULL) || (rush->prev->prev == NULL))
                                return false;

                        else
                        {
                                d = strtol((rush->prev->prev->word), NULL, 10);
                                s = strtol((rush->prev->word), NULL, 10);
                                int sd = s * d;
                                sprintf(rush->word, "%d\n", sd);
                                deleteNode(arithlist, rush->prev->prev);
                                deleteNode(arithlist, rush->prev);
			}
		  }
		}
                rush = rush->next;
	}		 	

	// if more than one node left, return false

	// if the remaining node is an operator, return false
	// if everything is OK, return true
		  int c = 0;
		  ListNode * count = arithlist->head;
		  while(count != NULL)
		  {
			c++;
			count = count->next;
		  }

		  if(c > 1)
		  	return false;

		  if((isOperator(arithlist->head->word) != -1))
		  	return false;
		  
		  arithlist-> tail = arithlist -> head;

	return true;
}
#endif

