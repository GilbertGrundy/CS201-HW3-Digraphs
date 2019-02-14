//#ifndef _DEFAULT_SOURCE
#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "digraphs.h"


struct digraphs * digraphs_text(char * filename)
{
    static struct digraphs file_values;
    char char_pair[2];
    FILE * diagraph_file;
    int index1 = 0;
    int index2 = 0;

    diagraph_file = fopen(filename, "r");

    if(!diagraph_file) 
    {
        fprintf(stderr, "Diagraphs: File didn't open.\n");
        return NULL;
    }

    while(!feof(diagraph_file))
    {
        index1 = mapping(char_pair[0]);
        index2 = mapping(char_pair[1]);

        if((index1 > 0) && (index2 > 0))
        {    
            file_values.counts[index1][index2]++;
            file_values.nchars++;
        }

        char_pair[0] = char_pair[1];
        char_pair[1] = fgetc(diagraph_file); 
    }

    qsort(file_values.counts, 2704, 8, &compare_counts);

    return &file_values;
}
