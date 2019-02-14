//#ifndef _DEFAULT_SOURCE
#define _DEFAULT_SOURCE

#include <stdio.h>
#include <dirent.h>
#include "digraphs.h"


int main(int argc, char **argv)
{

    if(argc != 2)
    {
        fprintf(stderr, "Digraphs: invalid amount of arguments\n");
        return -1;
    }

    //to check if main has been passed the flag for
    //a textfile
    if((argv[1][0] == '-') && (argv[1][1] == 't'))
    {
        
    }
    else if((argv[1][0] == '-') && (argv[1][1] == 'p'))
    {

    }
    else
    {
        fprintf(stderr, "Digraphs: invalid flag\n");
        return -1;
    }


    return 0;
}
