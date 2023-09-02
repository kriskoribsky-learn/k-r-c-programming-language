#include <stdio.h>
#include <stdlib.h>

#include "calc.h"

#define BUFSIZE 100

int bufp = 0;      /* next free position in buf */
char buf[BUFSIZE]; /* buffer for ungetch */

int getch(void)
{
    return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
    {
        fprintf(stderr, "Error: buffer full, can't ungetch\n");
        exit(EXIT_FAILURE);
    }

    buf[bufp++] = c;
}
