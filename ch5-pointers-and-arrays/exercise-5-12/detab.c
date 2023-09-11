#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_TAB_SIZE 8  /* Number of spaces the tab '\t' character should represent */
#define DEFAULT_TAB_START 0 /* Number of spaces to skip before starting replacing '\t' */

int main(int argc, char **argv)
{
    long tab_size = DEFAULT_TAB_SIZE;
    long tab_start = DEFAULT_TAB_START;

    /* read command-line arguments */
    long val;
    char *valptr;
    char *endptr;

    while (--argc)
    {
        switch ((*++argv)[0])
        {
        case '-': /* tab size */
            valptr = *argv + 1;
            val = strtol(valptr, &endptr, 10);

            if (endptr == valptr) /* there were no digits at all */
            {
                fprintf(stderr, "Error: please provide a numberic argument value for tab stop\n");
                exit(EXIT_FAILURE);
            }

            tab_start = val;
            break;

        case '+': /* tab start */
            valptr = *argv + 1;
            val = strtol(valptr, &endptr, 10);

            if (endptr == valptr) /* there were no digits at all */
            {
                fprintf(stderr, "Error: please provide a numberic argument value for tab size\n");
                exit(EXIT_FAILURE);
            }

            tab_size = val;
            break;
        }
    }

    /* replace tabs with appropriate number of spaces per line */
    int c;
    long line_pos = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            putchar('\n');
            line_pos = 0;
        }
        else if (c == '\t' && line_pos >= tab_start)
        {
            for (int i = 0; i < tab_size; i++)
            {
                putchar(' ');
            }
        }
        else
        {
            putchar(c);
            line_pos++;
        }
    }

    return EXIT_SUCCESS;
}
