#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "digraphs.h"

int mapping(char alpha)
{
    if((alpha > 64) && (alpha < 91)) return (alpha - 39);
    if((alpha > 96) && (alpha < 123)) return (alpha - 97);
    return -1;
}

int compare_counts(const void *p, const void *q)
{
    int x = *(const int *)p;
    int y = *(const int *)q;

    if(x < y) return 1;
    else return -1;
}

//https://en.wikipedia.org/wiki/Qsort
