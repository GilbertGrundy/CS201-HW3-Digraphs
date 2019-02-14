//#ifndef _DEFAULT_SOURCE
#define _DEFAULT_SOURCE

#include <stdio.h>
#include <dirent.h>
#include "digraphs.h"


struct digraphs * digraphs_fs(char * path)
{
    static struct digraphs directory_values;

    return &directory_values;
}
