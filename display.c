#define _DEFAULT_SOURCE

#include <stdio.h>
#include <dirent.h>
#include "digraphs.h"

int display(struct digraphs * values, struct result * top)
{
    printf("Alphabetic characters: %ld\n", values->nchars);
    printf("Top diagraphs: \n");
    
    int success = 0;

    for(int i = 0; i < 10; ++i)
    {
        success++;
        printf("%s", top[i].digraph);
        printf(" %ld\n", top[i].count);
    }

    return success;
}
