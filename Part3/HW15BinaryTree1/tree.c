// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

// DO NOT MODIFY FROM HERE --->>>
void deleteTreeNode(TreeNode * tr)
{
  if (tr == NULL)
    {
      return;
    }
  deleteTreeNode (tr -> left);
  deleteTreeNode (tr -> right);
  free (tr);
}

void freeTree(Tree * tr)
{
  if (tr == NULL)
    {
      // nothing to delete
      return;
    }
  deleteTreeNode (tr -> root);
  free (tr);
}

static void preOrderNode(TreeNode * tn, FILE * fptr)
{
  if (tn == NULL)
    {
      return;
    }
  fprintf(fptr, "%d\n", tn -> value);
  preOrderNode(tn -> left, fptr);
  preOrderNode(tn -> right, fptr);
}

void preOrder(Tree * tr, char * filename)
{
  if (tr == NULL)
    {
      return;
    }
  FILE * fptr = fopen(filename, "w");
  preOrderNode(tr -> root, fptr);
  fclose (fptr);
}
// <<<--- UNTIL HERE

// ***
// *** You MUST modify the follow function
// ***

#ifdef TEST_BUILDTREE
// Consider the algorithm posted on
// https://www.geeksforgeeks.org/construct-a-binary-tree-from-postorder-and-inorder/

TreeNode * newNode(int k)
{
  TreeNode * node = (TreeNode*)(malloc(sizeof(TreeNode)));
  node->value = k;
  node->left = node->right = NULL;
 
  return node;
}

int search(int * arg, int start, int end, int val)
{
 int i = 0;
    for(i = start; i <= end; i++)
    {
          if(arg[i] == val)
                  break;
    }
    return i;
}

 

TreeNode * build(int * inArray, int * postArray, int start, int end, int *ind)
{
  if(start > end)
  	return NULL;
  
  TreeNode * node = newNode(postArray[*ind]);
  (*ind)--;

  if(start == end)
	return node;
  
  
  int iind = search(inArray, start, end, node->value);
  node->right = build(inArray, postArray, iind + 1, end, ind);
  node->left = build(inArray, postArray, start,  iind-1, ind);

  return node;
}

Tree * buildTree(int * inArray, int * postArray, int size)
{
 int ind = size - 1;
 Tree * tree = (Tree*)malloc(sizeof(Tree));
 tree -> root = build(inArray, postArray, 0, size - 1, &ind);
 return tree;
}

#endif

