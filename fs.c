/* 
 * Gilbert Grundy
 * Digraphs Frequencies
 * HW3
 *
 * File holds function to search a
 * directory tree for digraphs
 *
 */
#define _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include "digraphs.h"


//Wrapper function, with its recursive counterpart,
//will take a directory address and count the number of 
//alphabetical characters, as well as the digraphs contained by the
//files and directories encountered insinde the directory tree.
//Will print out error messages if a file is given as argument
//or if the directory address does not exist.Always returns a 
//malloced struct digraphs, and so memory must be freed outside 
//of function.
struct digraphs * digraphs_fs(char * path)
{                                   //constructor invokes malloc()
    struct digraphs * directory_values = digraphs_constructor();

    //recursively go into the tree
    recursive_fs(directory_values, path);

    return directory_values;
}



//recursive function which travels through the direcotry tree
void recursive_fs(struct digraphs * directory_values, char * path)
{
    DIR * digraph_directory;
    struct dirent * digraph_file;
    char * directory = NULL;
    int index1 = 0;
    int index2 = 0;

    //open directory
    digraph_directory = opendir(path);

    //if the directory address can't be found, print error and exit.
    if(ENOENT == errno) 
    {
        fprintf(stderr, "Digraphs: Directory address does not exist.\n");
        closedir(digraph_directory);
        return;
    }
    
    //if not a directory, print error and exit.
    if(ENOTDIR == errno) 
    {
        fprintf(stderr, "Digraphs: Argument is not a directory.\n"); 
        closedir(digraph_directory);
        return;
    }

    //read first address
    digraph_file = readdir(digraph_directory);
    
    //while the address is not NULL
    while(digraph_file)
    {   
        //if the address is a directory, and not one which begins with .
        if((digraph_file->d_type & DT_DIR) && (digraph_file->d_name[0] != '.'))
        {
            //create a char array to hold the whole address of the directory
            int size = strlen(path) + strlen(digraph_file->d_name) + 2;
            directory = malloc(size * sizeof(char));
            strcpy(directory, path); //copy current directory address

            //make sure current address has a \ at the end.
            if(directory[strlen(directory) - 1] != 47)
            {
                directory[strlen(path)] = 47;
                directory[strlen(path) + 1] = '\0';
            }

            //append the directory name to the current directory
            strcat(directory, digraph_file->d_name);

            //call function recursively  with new directory path
            recursive_fs(directory_values, directory);

            //free memory of the path address
            if(directory) free(directory);
        }

        int i = 0; //index to retrieve chars from file/directory names
        
        //if address is greater than 2, the it's a useful file address
        //with potential digraphs
        if(strlen(digraph_file->d_name) > 2)
        {  
            //counts the opening character if it is alphabetic
            if(mapping(digraph_file->d_name[0]) > -1) directory_values->nchars++;
            
            while(digraph_file->d_name[i])
            {
                //map the characters to an index
                index1 = mapping(digraph_file->d_name[i]);
                ++i;
                index2 = mapping(digraph_file->d_name[i]);

                //counts if the new character is alphabetic
                if(index2 > -1) directory_values->nchars++;
                
                //if both index's are alphabetical then count the digraph                
                if((index1 > -1) && (index2 > -1))
                {        
                    directory_values->counts[index1][index2]++;
                }                
            }
        }

        //read next address
        digraph_file = readdir(digraph_directory);
    }

    //close directory
    closedir(digraph_directory);

    return;
}
