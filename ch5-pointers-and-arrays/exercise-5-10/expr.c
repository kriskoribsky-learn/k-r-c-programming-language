#include <stdio.h>
#include <stdlib.h>

#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Wrong number of arguments!\nUsage: ./expr <expression>\n");
        return EXIT_FAILURE;
    }
}
