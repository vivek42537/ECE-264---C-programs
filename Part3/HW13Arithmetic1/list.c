// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#ifdef TEST_READLIST
// read line by line from the input file
// each line shorter than WORDLENGTH (including '\n' and '\0')
// arithlist should have memory to store head and tail
// If arithlist is NULL, return false
// If fopen fails, return false
// If a line is too long,
//    free memory of the list
//    fclose
//    return false
// If everything is fine
//    fclose
//    arithlist points to the head and tail of the list
//    return true
bool readList(char * filename, List * arithlist)
{
  char air[WORDLENGTH];
  
  FILE * fur = fopen(filename,"r");
  if(arithlist == NULL)
	return false;

  if(fur == NULL)
	return false;

  while(fgets(air, WORDLENGTH, fur) != NULL)
  {
	if(air == NULL)
	{
		free(air);
		fclose(fur);
		return false;
	}
	else
	{
		addNode(arithlist, air);
	}
  }
  fclose(fur);
  return true;	
}
#endif

#ifdef TEST_DELETELIST
// If arithlist is NULL, do nothing
// release the memory of every node in the list
// release the memory of the list 
void deleteList(List * arithlist)
{
 if(arithlist != NULL)
 {
 	ListNode * curr = arithlist->tail;
	ListNode * bef = NULL;
	while(curr != NULL)
	{
		bef = curr->prev;
		free(curr);
		curr = bef;
	}
  free(bef);
  }
  free(arithlist);
 
}
#endif

#ifdef TEST_ADDNODE
// Input: 
// arithlist stores the addresses of head and tail
// If arithlist is NULL, do nothing
// word is the word to be added
//
// Output:
// a ListNode is added to the end (become tail)
//
// allocate memory for a new ListNode
// copy word to the word attribute of the new ListNode
// insert the ListNode to the list
void addNode(List * arithlist, char * word)
{
  if(arithlist == NULL)
        return;

  ListNode * newNode = malloc(sizeof(ListNode));
  strcpy(newNode->word,word);
  
  if(arithlist->head == NULL)
  {
	arithlist->head = newNode;
	arithlist->tail = newNode;
  }
  else
  {
  	newNode->prev = NULL;
	newNode->prev = arithlist->tail;
  	newNode->next = NULL;

    
	arithlist->tail->next = newNode;
        arithlist->tail = newNode;
  }
}
#endif

#ifdef TEST_DELETENODE
//  Input:
// arithlist stores the addresses of head and tail
// If arithlist is NULL, return false
// If the list is empty (head and tail are NULL), return false
// ln is the node to be deleted
// If ln is not in the list, return false
// 
// Output:
// arithlist stores the addresses of head and tail
//   after ln is deleted
// return true.
//
// Be careful about delete the first or the last node
bool deleteNode(List * arithlist, ListNode * ln)
{
  if(arithlist == NULL)
	return false;
  
  if((arithlist->tail == NULL) && (arithlist->head == NULL))
	return false;

  if(ln == NULL)
	return false;
  
  ListNode * temp = arithlist->head;
 
  while((temp != NULL) && (temp != ln))
  {
	temp = temp->next;
  }
 
  if(temp->prev != NULL)
  {
   temp->prev->next = ln->next;
  }
  else{
  arithlist->head = ln->next;
  }

  if(temp->next != NULL){
  temp->next->prev = ln->prev;
  }
  else{
  arithlist->tail = ln->prev;
  }
  
  free(ln);	  
  return true;
}
#endif

