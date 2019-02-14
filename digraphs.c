//#ifndef _DEFAULT_SOURCE
#define _DEFAULT_SOURCE

#include <stdio.h>
#include <dirent.h>
#include "digraphs.h"


int main(int argc, char **argv)
{

    //checks if there is the correct amount of arguments
    //there should be the filename, flag, and either
    //a file or directory, if not exit program.
    if(argc != 3)
    {
        fprintf(stderr, "Digraphs: invalid amount of arguments\n");
        return -1;
    }

    struct digraphs * values;

    //to check if main has been passed the flag for
    //a textfile
    if((argv[1][0] == '-') && (argv[1][1] == 't'))
    {
         values = digraphs_text(argv[2]);

    }//checks if theflag for a file directory has been passed
    else if((argv[1][0] == '-') && (argv[1][1] == 'p'))
    {
        values = digraphs_fs(argv[2]);
    }//if not the wrong flag has been passed, exit program.
    else
    {
        fprintf(stderr, "Digraphs: invalid flag\n");
        return -1;
    }

    return 0;
}
