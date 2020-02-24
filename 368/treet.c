#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "countt.h"

Tree *createNode(char charac, int freq)
{
    Tree *parent = malloc(sizeof(*parent));
    parent -> next = NULL;
    parent -> left = NULL;
    parent -> right = NULL;
    parent -> freq = freq;
    parent -> charac = charac;
    return parent;
}

void insert(Tree * head, Tree * new)
{
    if(head == NULL)
    {
        head = new;
        return;
    } //makes sure list is sorted:
    else
    {
        Tree* curr = head;
        while (curr -> next != NULL)
        {
            curr = curr -> next;
        }
        curr -> next = new;
    }
    return;
}

Tree *createList(int *freq, char *ascii, int total)
{
    Tree *head = NULL;
    for(int x=0; x < total; x++)
    {
        Tree * new = createNode(ascii[x], freq[x]);
        insert(head, new);
    }
    return head;
}
/*
Tree *addNodes(Tree * one) // merge two nodes into one
{
    for(int z = 1; one-> next != NULL; z++)
    {
        Tree * two = one -> next;
        Tree * three = createNode(z, one->freq + two->freq);
        three -> left = one;
        three -> right = two;
        one = two -> next;
        one = insert(one, three);

    }
    return one;
} */
