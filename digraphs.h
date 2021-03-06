#ifndef _DIGRAPH_H
#define _DIGRAPH_H

#include <stdint.h>
#include <stdlib.h>
#include <dirent.h>

//#ifndef MAX 10
#define MAX 10 

/* Digraph count information. */
struct digraphs 
{
    /* Number of alphabetic characters examined. */
    uint64_t nchars;
    /*
     * Digraph frequencies. The left (row) index
     * is the first character in the digraph; the right (column)
     * index is the second character. Indices 0..25 are the lowercase
     * characters in order; 26..51 are the uppercase characters.
     *
     * When you see a valid digraph, subtract 'a' or 'A' from each
     * of the characters as appropriate to get an index in the range
     * 0..51 for each position. Then increment the count at
     * the given position in the counts table.
     *
     * Example: You see "ea". 'e' - 'a' = 4. 'a' - 'a' = 0. So
     * do counts[4][0]++
     */
    uint64_t counts[52][52];
};

struct result 
{
    char digraph[2];
    uint64_t count;
};



/* text.c */

/*
 * Return a malloc-ed struct of counts
 * for the text in the file with the given name.
 * Return a null pointer on error.
 */
extern struct digraphs *
digraphs_text(char *filename);

/* fs.c */

/*
 * Return a malloc-ed struct of counts for the file and
 * directory names starting at the given path. Return a null
 * pointer on error.
 */
extern struct digraphs *
digraphs_fs(char *path);

extern int mapping(char alpha);
extern int compare_counts(const void *p, const void *q);
extern int sort_results(struct result * top, struct digraphs * values);
extern int display(struct digraphs * values, struct result * top);
extern struct digraphs * digraphs_constructor();
extern struct result * result_constructor(int size); 
extern void recursive_fs(struct digraphs * directory_values, char * path);

#endif
