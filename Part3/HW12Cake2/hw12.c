// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h>
#include "hw12.h"

// DO NOT MODIFY this function --->>>
void printListNode(ListNode * head)
{
  ListNode * p = head;
  printf("printListNode: ");
  while (p != NULL)
    {
      printf("%7d ", p -> value);
      p = p -> next;
    }
  printf("\n");
}
// <<<--- until here

// You MUST modify the following functions

#ifdef TEST_CREATELIST
// create a linked list storing values 0, 1, 2, ... valn - 1
// The first node (head) stores 0, the next node stores 1,
// ..., the last node stores valn - 1
// return the head of the linked listn
ListNode * createList(int valn)
{
	ListNode * head = NULL;
	head = malloc(sizeof(ListNode));
	
	ListNode * nex = NULL;
	nex = head;

	for(int i = 0; i < valn; i++)
	{
	  nex -> value = i;
          if(i == (valn - 1))
	  {
		nex->next = NULL;
	  }
	  else
	  {
		nex->next = malloc(sizeof(ListNode));
	  }
	nex = nex->next; 
        
	}
	return head;
}
#endif

#ifdef TEST_ELIMINATE
// eliminate the nodes in the linked list
// starting from the head, move one node at a time and count to valk.
// eliminate that node, keep counting
//
// when reaching the end of the list, continue from the beginning of
// the list
//
// print the values of the nodes to be deleted
void eliminate(ListNode * head, int valk)
{
  int i = 0;
  ListNode * p = head;
  while (head -> next != NULL)
  {
	while(i < valk - 1)
	{
	  if(p -> next == NULL)
	  {
		p = head;
		i++;
	  }
	  else
	  {
		p = p->next;
		i++;
	  }
	}
#ifdef DEBUG
  // this #ifdef ... #endif should be inside the condition *BEFORE* a
  // node' value is printed and it is deleted
	ListNode * todelete = p;
	printListNode (todelete); 
#endif
	printf("%d\n", todelete -> value);
	if(p->next == NULL)
	{
		p = head;
	}
	else
	{
		p = p->next;
	}
	head = deleteNode(head,todelete);
	i = 0;
  }
  printf("%d\n", head->value);
  free(head);
}
#endif

#ifdef TEST_DELETENODE
// head points to the first node in the linked list
// todelete points  to the node to be deleted
//
// delete the node and return the head of the linked list
// release the memory of the deleted node
//
// should check several conditions:
// 1. If head is NULL, the list is empty and this function returns
//    NULL
// 2. If todelete is NULL, nothing can be deleted, return head
// 3. If todelete is not in the list, keep the list unchanged and
//    return head
// It is possible that todelete is the first node in the list (i.e.,
// the head). If this occurs, return the second node of the list.
ListNode * deleteNode(ListNode * head, ListNode * todelete)
{
	ListNode * p = head;
	ListNode * c = NULL;
	if(p != todelete)
	{
		while(p -> next != NULL)
		{
			if (p -> next == todelete)
			{
				c = p->next;
				p-> next = (p->next)->next;
				c->next = NULL;
				free(c);
				return head;
			}
			p = p->next;
		}
	}
	if(head == NULL)
	{
		return NULL;
	}
	if(todelete == NULL)
	{
		return head;
	}
        if(head == todelete)
	{
		ListNode * a = head;
		head = head->next;
		free(a);
	}
	return head;
}
#endif


