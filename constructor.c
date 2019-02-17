#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "digraphs.h"

//constructor for struct digraphs. Memory must be freed
//outside of function.
struct digraphs * digraphs_constructor()
{
    struct digraphs * create = malloc(sizeof(struct digraphs));
    create->nchars = 0;
    for(int i = 0; i < 52; ++i)
    {
        for(int j = 0; j < 52; ++j)
        {
            create->counts[i][j] = 0;
        }
    }

    return create;
}

//constructor for struct result. Memory must be freed
//outside of function. Always making an array of struct result
//so taking in an int argument for size of array.
struct result * result_constructor(int size)
{
    struct result * create = malloc(size*sizeof(struct result));
    create->digraph[0] = '\0';
    create->digraph[1] = '\0';
    create->digraph[2] = '\0';
    create->count = 0;

    return create;
}
