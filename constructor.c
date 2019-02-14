#define _DEFAULT_SOURCE

#include <stdio.h>
#include <dirent.h>
#include "digraphs.h"

int diagraph_constructor(struct digraphs * values)
{
    int success = 0;
    values->nchars = 0;

    for(int i = 0; i < 52; ++i)
    {
        for(int j = 0; j < 52; ++j)
        {
            values->counts[i][j] = 0;
            ++success;
        }
    }

    return success;
}


int result_constructor(struct result * top)
{
    int success = 0;
    for(int i = 0; i < 10; ++i)
    {
        ++success;
        top[i].count = 0;
        top[i].digraph[2] = '\0';
    }
    return success;
}
