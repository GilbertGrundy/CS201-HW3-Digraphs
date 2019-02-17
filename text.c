#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "digraphs.h"


struct digraphs * digraphs_text(char * filename)
{
    struct digraphs * file_values = digraphs_constructor();
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
        char_pair[0] = char_pair[1];
        char_pair[1] = fgetc(diagraph_file); 
        
        index1 = mapping(char_pair[0]);
        index2 = mapping(char_pair[1]);

        if(index2 > -1) file_values->nchars++;

        if((index1 > -1) && (index2 > -1))
        {    
            file_values->counts[index1][index2]++;
        }
    }

    return file_values;
}
