#include <stdlib.h> 
#include <string.h> 
#include <stdio.h>
#include "packing.h"

int main(int argc, char ** argv)
{
    if(argc != 5)
    {
        return EXIT_FAILURE;
    }
    char * infile = argv[1];
    char * out1 = argv[2];
    char * out2 = argv[3];
    char * out3 = argv[4];
    Tree *node = NULL;
    FILE *fur = fopen(infile, "r");
    if(fur == NULL)
    {
        return EXIT_FAILURE;
    }

    node = loadfile(fur);
    fclose(fur);


    FILE *furo1 = fopen(out1, "w");
    if(furo1 == NULL)
    {
        return EXIT_FAILURE;
    }
    preorder(furo1, node);
    fclose(furo1);

    

    FILE *furo2 = fopen(out2, "w");
    if(furo2 == NULL)
    {
        return EXIT_FAILURE;
    }
    pack(node);
    dimensions(furo2, node);
    fclose(furo2); 

    FILE *furo3 = fopen(out3, "w");
    if(furo3 == NULL)
    {
        return EXIT_FAILURE;
    }
    coordinate(node);
    printCoor(furo3, node);
    fclose(furo3); 

    return EXIT_SUCCESS;
}
