Gilbert Grundy
Homework 3 - Digraph counter

Fun project. First time I've made a program to take in flags
as arguments; and the first time I've had a program search
a directoy tree. Furthermore, I got more experience using 
Valgrind and GDB. 

I also used some new syntax. I played with calling a 
static struct inside a couple of my functions, and saw
that I could do that! I think it would have been a perfectly
fine implementation of this program, but decided to simply
malloc memory in a constructor, and free the memory at
the end of main().

I got some experience using bit masks and error flags,
not something I've done extensively before.

Still think with more time I could make a cleaner, and 
faster implementation of the program. The result sorting
looks expensive as it is.

I'm very happy with the error handling, I think the program
gives you useful information with wrong argument input.
