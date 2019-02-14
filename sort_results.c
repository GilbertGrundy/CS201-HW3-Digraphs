#define _DEFAULT_SOURCE

#include <stdio.h>
#include <dirent.h>
#include "digraphs.h"


int sort_results(struct result * top, struct digraphs * values)
{
    int success = 0;

    for(int i = 0; i < 52; ++i)
    {
        for(int j = 0; j < 52; ++j)
        {
            for(int k = 0; k < 10; ++k)
            {
                if(values->counts[i][j] > top[k].count)
                {
                    ++success;
                    int s = k+1;
                    while(s < 10)
                    {
                        top[s].count = top[s-1].count;
                        top[s].digraph[0] = top[s-1].digraph[0];
                        top[s].digraph[1] = top[s-1].digraph[1];
                        s++;
                    }
                    top[k].count = values->counts[i][j];
                    
                    if(i < 26) top[k].digraph[0] = (i + 97);
                    else top[k].digraph[0] = (i + 39);

                    if(j < 26) top[k].digraph[1] = (j + 97);
                    else top[k].digraph[1] = (j + 39);

                    k = 10;
                }
            }
        }
    }

    return success;
}
