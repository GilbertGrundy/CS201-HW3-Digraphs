#define _DEFAULT_SOURCE

#include <stdio.h>
#include <dirent.h>
#include "digraphs.h"

//sorts results of the digraph counter into the top results
//of length MAX(10), returns a count of the amount of times
//a digraph was added to the top 10. If no digraphs added
//then zero returned.
int sort_results(struct result * top, struct digraphs * values)
{
    int success = 0;

    for(int i = 0; i < 52; ++i)
    {
        for(int j = 0; j < 52; ++j)
        {
            for(int k = 0; k < MAX; ++k)
            {
                //new digraph found with value greater than
                //an entry in the current top results
                if(values->counts[i][j] > top[k].count)
                {
                    ++success;
                    int s = 9; //an index to shift current results

                    //shift the top 10 down to fit new entry
                    //when s = k, we have shifted enough
                    while(s != k)
                    {   //shift entry down the list, deleting MAX entry
                        top[s].count = top[s - 1].count;
                        top[s].digraph[0] = top[s - 1].digraph[0];
                        top[s].digraph[1] = top[s - 1].digraph[1];

                        s--;
                    }
                    //add new entry
                    top[k].count = values->counts[i][j];
                    
                    //takes the value of the index's, then
                    //adds the characters of the digraph to
                    //the results
                    if(i < 26) top[k].digraph[0] = (i + 97);
                    else top[k].digraph[0] = (i + 39);

                    if(j < 26) top[k].digraph[1] = (j + 97);
                    else top[k].digraph[1] = (j + 39);

                    k = 10; //sets k to 10, to exit while loop
                }
            }
        }
    }

    return success;
}
