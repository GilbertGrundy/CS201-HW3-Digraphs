/* 
 * Gilbert Grundy
 * Digraphs Frequencies
 * HW3
 *
 * File holds function
 * which searches a file
 * for digraphs
 *
 */
#define _DEFAULT_SOURCE
#define S_IFDIR
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include "digraphs.h"


//function will take a filename and count the number of alphabetical
//characters in the file, as well as the digraphs inside the file
//will print out error messages if a directory is given as argument
//or the file fails to open. Always returns a malloced struct digraphs,
//and so memory must be freed outside of function.
struct digraphs * digraphs_text(char * filename)
{
                                    //constructor invokes malloc()
    struct digraphs * file_values = digraphs_constructor();
    struct stat * check_for_dir = malloc(sizeof(struct stat));
    char char_pair[2];
    FILE * diagraph_file;
    int index1 = 0;
    int index2 = 0;

    //open file to read
    diagraph_file = fopen(filename, "r");

    //get status of the file
    lstat(filename, check_for_dir);


    //check if the file is in fact a directory, if so, print an error
    //message free memory to the struct stat and exit
    if((check_for_dir->st_mode & S_IFMT) == S_IFDIR)
    {
        fprintf(stderr, "Diagraphs: Argument is a directory. Try -p flag.\n");
        free(check_for_dir);
        return file_values;
    }
        
    free(check_for_dir); //free stat memory

    //if a NULL pointer returned, print error and  exit function
    if(!diagraph_file) 
    {
        fprintf(stderr, "Diagraphs: File didn't open.\n");
        return file_values;
    }

    //count alphabetic characters, and digraphs while the EOF
    //flag is not encountered
    while(!feof(diagraph_file))
    {
        //grab the digraph pairs, will waste a loop
        //until useful information is read, but
        //not bothered about optimizing out a single loop.
        char_pair[0] = char_pair[1];
        char_pair[1] = fgetc(diagraph_file); //read file
        
        //map the characters to an index
        index1 = mapping(char_pair[0]);
        index2 = mapping(char_pair[1]);

        //if index is -1, character was not alphabetical
        if(index2 > -1) file_values->nchars++;

        //if both index's are alphabetical then count the digraph
        if((index1 > -1) && (index2 > -1))
        {    
            file_values->counts[index1][index2]++;
        }
    }

    return file_values;
}
