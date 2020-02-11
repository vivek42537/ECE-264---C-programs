#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shell_list.h"

typedef struct List {
  Node *node;
  struct List *next;
} List;

int length(Node *front)
{
  Node *i = front;
  int c = 0;
  while(i != NULL)
  {
    c++;
    i = i->next;
  }
  return c;
}

List * createNode()
{
  List *x = malloc(sizeof(List));
  if(x == NULL)
  {
    return NULL;
  }
  x->node = NULL;
  x->next = NULL;
  return x;
}

int insertNode(List **hicks, Node **front, Node *nu, int d)
{
  long num = 0;
  Node *cur;
  Node *comp = nu;
  if(d == 1)
  {
    if((*hicks)->node->value >= nu->value || (*hicks)->node == NULL)
    {
      num++;
      nu->next = (*hicks)->node;
      (*hicks)->node = nu;
    }
    else
    {
      cur = *front;
      while(cur->next != NULL && (cur->next->value < nu->value))
      {
        num++;
        cur = cur->next;
      }
      nu->next = cur->next;
      cur->next = nu;
    }
  }
  if(d == 0)
  {
    if((*hicks)->node->value <= nu->value || (*hicks)->node == NULL)
    {
      num++;
      nu->next = (*hicks)->node;
      (*hicks)->node = nu;
    }
    else
    {
      cur = *front;
      while(cur->next != NULL && (cur->next->value >= nu->value))
      {
        num++;
        cur = cur->next;
      }
      nu->next = cur->next;
      cur->next = nu;
    }
  }
  if(comp == nu)
  {
    num++;
  }
  return num;

}

Node *createList(FILE *fur, int size)
{
  int x = 1;
  Node* front  = malloc(sizeof(Node));
  if(front == NULL)
  {
    exit(0);
  }
  Node * temp = front;
  fread(&temp->value, sizeof(long), 1, fur);

  while(x < size)
  {
    temp->next = malloc(sizeof(Node));
    if(temp->next == NULL)
    {
      exit(0);
    }
    temp = temp->next;
    fread(&temp->value, sizeof(long), 1, fur);
    temp->next = NULL;
    x++;
  }
  return front;
}


Node *List_Load_From_File(char *filename)
{
  FILE *fur = fopen(filename, "rb");
  if(fur == NULL)
  {
    return NULL;
  }
  fseek(fur, 0, SEEK_END);
  int size = ftell(fur)/(sizeof(long));
  fseek(fur, 0, SEEK_SET);
  if(size == 0)
  {
    fclose(fur);
    return NULL;
  }
  Node *front = createList(fur, size);
  fclose(fur);
  return front;
}

int List_Save_To_File(char *filename, Node *list)
{
  FILE * furo = fopen(filename, "wb");
  if(furo == NULL)
  {
    exit(0);
  }
  fseek(furo, 0, SEEK_SET);
  int i = 0;
  while(list != NULL)
  {
    fwrite(&(list -> value), sizeof(long), 1, furo);
    list = list ->next;
    i++;
  }
  fclose(furo);
  return i;
}

void freeNode(List **z)
{
  List *curr = (*z);
  List *next;
  while(curr != NULL)
  {
    next = curr->next;
    free(curr);
    curr = next;
  }
  *z = NULL;
}

void realSort(int listSize, Node** list, long sas, long *n_comp, int sleep)
{
  Node* listone = *list;
  List *front = createNode();
  List *temp = front;
  Node* listuno;
  int path;

  if(sleep%2 == 1)
  {
    path = 0;
  }
  else
  {
    path = 1;
  }
  int x = 1; 
  while (x != sas)
  {
    temp->next = createNode();
    temp = temp->next;
    x++;
  }

  temp = front;
  for(int y = 0; y < sas; y++)
  {
    listuno = listone;
    listone = listone->next;
    listuno->next = NULL;
    temp->node = listuno;
    temp = temp->next;
  }
  int rem = listSize - sas; //remaining nodes
  int add = listSize;

  while(rem != 0)
  {
    temp = front;
    for(int y = 0; y < sas; y++)
    {
      if(listone != NULL)
      {
        listuno = listone;
        listone = listone->next;
        *n_comp += insertNode(&temp, &temp->node, listuno, path);
        rem--;
        temp = temp->next;
      }
    }
  }

  Node *mo;
  int f = 0;
  temp = front;
  while(add > 0)
  {
    for(int h = 0; h<sas; h++)
    {
      if((temp->node != NULL)&&(add = listSize))
      {
        mo = temp->node;
        temp->node = temp->node->next;
        listone = mo;
        add--;
      }
      else if(temp->node != NULL)
      {
        mo = temp->node;
        temp->node = temp->node->next;
        listone->next = mo;
        add--;
      }

      if(f == 0)
      {
        *list = listone;
        f = 1;
      }
      temp = temp->next;
      if((h != (sas - 1))&&(temp->node != NULL))
      {
        listone->next = temp->node;
        add--;
        listone = listone->next;
      }
      else
      {
        temp = front;
        mo = temp->node;
        listone->next = mo;
        add--;
      }
    }
  } freeNode(&front);
}

Node * List_Shellsort(Node *list, long *n_comp)
{
  int len = length(list);
  int k = 1;
  while(k <= len)
  {
    k = 3*k + 1;
  }
  k = (int)((k - 1) / 3);
  for(int i = k -1; i>=0; i--)
  {
    realSort(len, &list, k, n_comp, i);
  }
  return list;
}


