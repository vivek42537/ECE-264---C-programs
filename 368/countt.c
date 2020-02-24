#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "countt.h"

int freq(int *count,char *filename)
{
    FILE * fur = fopen(filename, "r");
    if(fur == NULL)
    {
        printf("hello");
        return -1;
    }
    int end = 0;
    int total = 0;
    while(end < 1)
    {
        int charac = fgetc(fur);
        if (charac == EOF)
        {
            end++;
        }
        else
        {
            count[charac]++;
            total++;
        }

    }
    int x = 0;
    for(int k = 0; k < 256; k++)
    {
        if(count[k] != 0)
        {
            x++;
        }
    }

    fclose(fur);
    return x;
}

void sort(char *ascii,int* frequen,int total)
{
    int i;
    int j;
    int temp1;
    char temp2;

    for(i = 0; i < total; ++i)
    {
        for(j =  i + 1; j < total; ++j)
        {
            if(frequen[i] > frequen[j])
            {
                temp1 = frequen[i];
                temp2 = ascii[i];
                frequen[i] = frequen[j];
                ascii[i] = ascii[j];
                frequen[j] = temp1;
                ascii[j] = temp2;
            }
            
        }
    }
}
