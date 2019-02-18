/* 
 * Gilbert Grundy
 * Digraphs Frequencies
 * HW3
 *
 * File holds main() for the program
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "digraphs.h"


int main(int argc, char **argv)
{

    //checks if there is the correct amount of arguments
    //there should be the filename, flag, and either
    //a file or directory, if not exit program.
    if(argc != 3)
    {
        fprintf(stderr, "Digraphs: Invalid amount of arguments.\n");
        return -1;
    }

    struct digraphs * values = NULL;
    struct result * top = result_constructor(MAX);
   
    //checks if main has been passed the flag for a textfile -t
    if((argv[1][0] == '-') && (argv[1][1] == 't'))
    {
         values = digraphs_text(argv[2]);

    }//checks if the flag for a file directory has been passed -p
    else if((argv[1][0] == '-') && (argv[1][1] == 'p'))
    {
        values = digraphs_fs(argv[2]);
    }//if not, the wrong flag has been passed, exit program.
    else
    {
        fprintf(stderr, "Digraphs: Invalid flag.\n");
        return -1;
    }

    //find the top MAX(10) most common digraphs
    //and place in the result struct
    sort_results(top, values);

    //display the character count, and the top MAX(10)
    //digraphs. if nchars is 0, then no digraphs are counted
    //so don't bother with display function
    if(values->nchars) display(values, top);
    else printf("\n");

    //free memory, if allocated
    if(values) free(values);
    if(top) free(top);


    return 0;
}

