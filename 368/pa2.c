#include <stdlib.h> 
#include <string.h> 
#include <stdio.h>
#include "countt.h"


int main(int argc, char ** argv)
{
    if(argc != 6)
    {
        return EXIT_FAILURE;
    }
    char * filename = argv[1];
    //printf("%s", filename);

    int count[256] = {0};

    int total = freq(count, filename);
    char* ascii = malloc(sizeof(*ascii) * total);
    int* frequen = malloc(sizeof(*frequen) * total);
    int k = 0;
    for(int x = 0; x < 256; x++)
    {
        if(count[x] != 0)
        {
            k++;
            ascii[k] = (char)x;
            frequen[k] = count[x];
        }
    }

    sort(ascii, frequen,total);
    for(int i = 0; i < total; i++){
        printf("%d\n",frequen[i]);
        printf("%c\n",ascii[i]);
    }

    Tree * list = createList(frequen, ascii, total);
    printf("%d", list -> freq);
    return 0;
}
