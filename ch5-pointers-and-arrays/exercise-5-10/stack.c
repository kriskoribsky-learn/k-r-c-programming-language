#include <stdio.h>
#include <stdlib.h>

#include "calc.h"

#define STACKSIZE 100 /* maximum depth of val stack */

int sp = 0;              /* next free stack position */
double stack[STACKSIZE]; /* value stack */

void push(double val)
{
    if (sp >= STACKSIZE)
    {
        fprintf(stderr, "Error: stack full, can't push\n");
        exit(EXIT_FAILURE);
    }

    stack[sp++] = val;
}

double pop(void)
{
    if (sp <= 0)
    {
        fprintf(stderr, "Error: stack empty, can't pop\n");
        return (double)0;
    }

    return stack[--sp];
}
