#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "packing.h"

/*char *line = malloc(3*10*sizeof(char) + 3*sizeof(char) +1); //10 is max number of digits
    while((fgets(line, sizeof(char*), fur)) != NULL)
    {
        printf("%s", line);
        Tree *node = malloc(sizeof(Tree));
        
*/
static void toString(Tree *node) {

    if(node -> isInternal == 1)
        printf("%c\n", node -> internalKey);
    else
        printf("%d(%d,%d)\n", node -> key, node -> width, node -> height);
}

StackNode *newStackNode(Tree *node) {
    
    StackNode *stackNode = (StackNode*) malloc(sizeof(StackNode));
    
    stackNode -> node = node;
    stackNode -> next = NULL;

    return stackNode;
}

void push(StackNode **root, Tree *node) {
    StackNode *stackNode = newStackNode(node);

    stackNode -> next = *root;

    *root = stackNode;
}

Tree* pop(StackNode **root) {

    StackNode *oldRoot = *root;

    Tree *pop = (*root) -> node;

    *root = (*root) -> next;

    free(oldRoot);

    return pop;
}

void preOrder(Tree *node) {

    if(node == NULL)
        return;

    toString(node);
    preOrder(node -> left);
    preOrder(node -> right);

}

Tree *loadfile(FILE *fur)
{
    
    char *line = malloc(3*10*sizeof(char) + 3*sizeof(char) +1); //10 is max number of digits
    
    StackNode *root = NULL;
    
    while((fgets(line, sizeof(char*), fur) != NULL))
    {
        Tree *node = malloc(sizeof(Tree));
        
        if(strlen(line) == 2) //internal node (H or V)
        {
            node -> internalKey = line[0];
            node -> x = 0;
            node -> y = 0;
            node -> width = 0;
            node -> height = 0;
            node -> isInternal = 1;

            node -> right = pop(&root);
            node -> left = pop(&root);

            push(&root, node);

        }
        else //is a leaf node
        {
            char delim[] = "(,)\n";
            char *token = strtok(line, delim);
            
            node -> key = strtol(token, &token, 10);
            token = strtok(NULL, delim);

            node -> width = strtol(token, &token, 10);
            token = strtok(NULL, delim);

            node -> height = strtol(token, &token, 10);
            token = strtok(NULL, delim);

            node -> isInternal = 0;

            push(&root, node);

        }
        
  
    }

    return pop(&root);

    // while(root) {

    //     Tree *temp = pop(&root);

    //     preOrder(temp);

    //     free(temp);
    // }



 


   /*
    int ch;
    while((ch = fgetc(fur)) != EOF)
    {
        printf("%c", ch);
        Tree *root = malloc(sizeof(*root));
        if((ch == 'V') || (ch == 'H')) //if internal node
        {
            root -> charac = 0;
            root -> width = 0;
            root -> height = 0;
            root -> x = 0;
            root -> y = 0;
            fseek(fur, -1, SEEK_CUR);
            fscanf(fur, "%d\n", &(root->charac));
            root -> left = loadfile(fur);
            root -> right = loadfile(fur);
            //return root;
        }
        else //otherwise its a leaf node
        {
            root -> left = NULL;
            root -> right = NULL;
            root -> charac = ch;
            fseek(fur, -1, SEEK_CUR);
            fscanf(fur, "%d(%d,%d)\n", &(root -> charac), &(root -> width), &(root -> height));
            //return root;
        }
    } */


    return NULL;
}




void preorder(FILE *fur, Tree *node)
{
    if(node == NULL)
    {
        printf("jslfjs\n");
        return;
    }
    else
    { 
        if((node -> left == NULL) && (node -> right ==NULL)) //is a leaf node and checks if NULL
        {
            fprintf(fur, "%d(%d,%d)\n", (node -> key), (node -> width), (node -> height));
            //printf("%d(%d,%d)\n", (node -> key), (node -> width), (node -> height));
        
        }
        else // internal node (only V or H)
        {
            fprintf(fur, "%c\n", node -> internalKey);
           // printf("%c\n", node -> internalKey);
            preorder(fur, node -> left);
            preorder(fur, node -> right);
        }
    }
}


    
// }


void pack(Tree *node)
{
    if(node == NULL)
    {
        return;
    }
    else
    {
        pack(node -> left);
        pack(node -> right);

        if((node -> left == NULL) && (node -> right ==NULL))
        {
            return;
        }
        if(node -> internalKey == 'V')
        {
            node -> width = node -> left -> width + node -> right -> width;
            node -> height = ((node -> left -> height) > (node -> right -> height)) ? node->left->height : node->right->height;
        }
        if(node -> internalKey == 'H')
        {
            node -> width = ((node -> left -> width) > (node -> right -> width)) ? node->left->width : node->right->width;
            node -> height = node -> left -> height + node -> right -> height;
        }
    }
    
}

void dimensions(FILE *fur, Tree *node)
{
    if(node == NULL)
    {
        return;
    }
    else
    {
        dimensions(fur, node -> left);
        dimensions(fur, node -> right);
        if((node -> left == NULL) && (node -> right ==NULL)) //is a leaf node and checks if NULL
        {
            fprintf(fur, "%d(%d,%d)\n", (node -> key), (node -> width), (node -> height));
        }
        else // internal node (only V or H)
        {
            fprintf(fur, "%c(%d,%d)\n", (node -> internalKey), (node -> width), (node -> height)); //prints in preorder now
        }   
    } 
}


void coordinate(Tree *node)
{
    if(node != NULL)
    {
        if(node -> internalKey == 'H')
        {
            node->left->x = node->x; //which is 0
            node->left->y = node->right->height + node->y ;
            coordinate(node->right); //H is preserves when going left, so H nodes goes right first
            
            node->right->x = node->x;
            node->right->y = node->y;
            coordinate(node->left);
        }
        if(node -> internalKey == 'V')
        {
            node->left->x = node->x;
            node->left->y = node->y;
            coordinate(node->left); //V node goes left first since left childs position is needed for the right child
            
            node->right->x = node->left->width + node->x;
            node->right->y = node->y;
            coordinate(node->right);
        }
    }
}

void printCoor(FILE *fur, Tree *node)
{
    if(node == NULL)
    {
        return;
    }
    else
    {
        printCoor(fur, node -> left);
        printCoor(fur, node -> right);
        if((node -> left == NULL) && (node -> right ==NULL)) //is a leaf node and checks if NULL
        {
            fprintf(fur, "%d((%d,%d)(%d,%d))\n", (node -> key), (node -> width), (node -> height), (node->x), (node->y));
        }
    } 
}

void freeTree(Tree *node)
{
    if (node == NULL){
        return;
    }
    if (node ->left != NULL)
    {
        freeTree(node->left);
    }
    if (node->right != NULL)
    {
        freeTree(node->right);
    }
    free(node);
    return;
}
