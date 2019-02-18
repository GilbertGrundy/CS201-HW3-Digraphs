/* 
 * Gilbert Grundy
 * Digraphs Frequencies
 * HW3
 *
 * File holds function to display
 * the most frequent digraphs
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "digraphs.h"


//Display function for the number of alphabetic characters
//read in, and for the top MAX(10) most frequent digraphs
//encountered. 
int display(struct digraphs * values, struct result * top)
{
    printf("\nAlphabetic characters: %ld\n", values->nchars);
    printf("Top diagraphs: \n");
    
    int success = 0;

    for(int i = 0; i < MAX; ++i)
    {
        success++;
        if(top[i].count)
        {
            printf("%s", top[i].digraph);
            printf(" %ld\n", top[i].count);
        }
    }

    printf("\n");

    return success;
}
