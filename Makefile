# Copyright © 2019 Bart Massey
# Makefile for digraph frequencies

CC = gcc
CFLAGS = -std=c11 -Wall -Werror -g
OBJS = digraphs.o text.o fs.o constructor.o display.o mapping.o sort_results.o

digraphs: $(OBJS)
	$(CC) $(CFLAGS) -o digraphs $(OBJS)

$(OBJS): digraphs.h

clean:
	-rm -f *.o digraphs
