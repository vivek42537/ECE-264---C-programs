#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shell_array.h"
#include "shell_list.h"

void freelist(Node **z);

void freelist(Node **z)
{
    Node *curr = (*z);
    Node *next;
    while(curr != NULL)
    {
        next = curr->next;
        free(curr);
        curr = next;
    }
    *z = NULL;
}

int main(int argc, char **argv)
{
    if(argc != 4)
    {
        return EXIT_FAILURE;
    }

    if(strcmp(argv[1], "-a") == 0)
    {
        int size = 0;
        long n_comp = 0;
        int done;
        long *arr = Array_Load_From_File(argv[2], &size);
       
        if(arr == NULL)
        {
            return EXIT_FAILURE;
        }
        if(size == 0)
        {
            done = Array_Save_To_File(argv[3], arr, size);
            n_comp = 0;
        }
        else
        {
            Array_Shellsort(arr, size, &n_comp);
           
            done = Array_Save_To_File(argv[3], arr, size);
        }
        printf("%ld\n", n_comp);
        if(done != size)
        {
            exit(0);
        }
        free(arr);
    }
    if(strcmp(argv[1], "-l")== 0)
    {
        long n_comp = 0;
        Node *head = List_Load_From_File(argv[2]);
       
        head = List_Shellsort(head, &n_comp);
     
        List_Save_To_File(argv[3], head);
	freelist(&head);
        printf("%ld\n", n_comp);
    freelist(&head);
    }
    return EXIT_SUCCESS;

}

