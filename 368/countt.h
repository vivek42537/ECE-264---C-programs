#ifndef __countt__
#define __countt__

typedef struct Tree{
    char charac;
    int freq;
    struct Tree *left;
    struct Tree *right;
    struct Tree *next;
} Tree;

int freq(int *count, char *filename);
void sort(char *ascii,int* freq,int total);

Tree *createNode(char charac, int freq);
void insert(Tree * head, Tree*);
Tree *createList(int *freq, char *ascii, int total);

#endif
