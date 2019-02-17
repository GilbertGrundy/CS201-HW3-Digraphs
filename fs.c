#define _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include "digraphs.h"




struct digraphs * digraphs_fs(char * path)
{
    struct digraphs * directory_values = digraphs_constructor();

    recursive_fs(directory_values, path);

    return directory_values;
}




void recursive_fs(struct digraphs * directory_values, char * path)
{
    DIR * digraph_directory;
    struct dirent * digraph_file;
    char * directory = NULL;
    int index1 = 0;
    int index2 = 0;

    digraph_directory = opendir(path);

    if(ENOENT == errno) 
    {
        fprintf(stderr, "Digraphs: Directory address does not exist.\n");
        closedir(digraph_directory);
        return;
    }
    
    if(ENOTDIR == errno) 
    {
        fprintf(stderr, "Digraphs: Argument is not a directory.\n"); 
        closedir(digraph_directory);
        return;
    }

    digraph_file = readdir(digraph_directory);

       
    while(digraph_file)
    {
        if((digraph_file->d_type & DT_DIR) && (digraph_file->d_name[0] != '.'))
        {
            int size = strlen(path) + strlen(digraph_file->d_name) + 2;
            directory = malloc(size * sizeof(char));
            strcpy(directory, path);

            if(directory[strlen(directory) - 1] != 47)
            {
                directory[strlen(path)] = 47;
                directory[strlen(path) + 1] = '\0';
            }

            strcat(directory, digraph_file->d_name);
            recursive_fs(directory_values, directory);    
            if(directory) free(directory);
        }

        int i = 0;
        
        if(strlen(digraph_file->d_name) > 2)
        {
            directory_values->nchars++;
            while(digraph_file->d_name[i])
            {
                index1 = mapping(digraph_file->d_name[i]);
                ++i;
                index2 = mapping(digraph_file->d_name[i]);

                if(index2 > -1) directory_values->nchars++;
                
                if((index1 > -1) && (index2 > -1))
                {        
                    directory_values->counts[index1][index2]++;
                }                
            }
            i = 0;
        }

        digraph_file = readdir(digraph_directory);
    }

    closedir(digraph_directory);

    return;
}
