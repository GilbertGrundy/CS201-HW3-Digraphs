#include "digraphs.h"


//Maps a alphabetic character to a number between 0-51
//if not alphabetic, returns -1.
int mapping(char alpha)
{
    //if alpha is uppercase, map to index 26 - 51
    if((alpha > 64) && (alpha < 91)) return (alpha - 39);
    
    //if alpha is lowercase, map to index 0 - 25
    if((alpha > 96) && (alpha < 123)) return (alpha - 97);

    //otherwise, give a negative number.
    return -1;
}
