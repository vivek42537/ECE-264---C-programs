#include <stdlib.h>
#include <string.h> 
#include <stdio.h>

typedef struct Tree{
    int key;
    char internalKey;
    int isInternal;
    int x;
    int y;
    int width;
    int height;
    struct Tree *left;
    struct Tree *right;
} Tree;

typedef struct _StackNode {
    Tree * node;
    struct _StackNode *next;
} StackNode;


Tree *loadfile(FILE *fur);
void preorder(FILE *fur, Tree *node);
void pack(Tree *node);
void dimensions(FILE *fur, Tree *node);
void coordinate(Tree *node);
void printCoor(FILE *fur, Tree *node);
