#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_TAB_SIZE 4  /* Number of spaces the tab '\t' character should represent */
#define DEFAULT_TAB_START 0 /* Number of spaces to skip before starting replacing '\t' */

int main(int argc, char **argv)
{
    long space_size = DEFAULT_TAB_SIZE;
    long column_start = DEFAULT_TAB_START;

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
                fprintf(stderr, "Error: please provide a valid numberic value for start column\n");
                exit(EXIT_FAILURE);
            }

            column_start = val;
            break;

        case '+': /* tab start */
            valptr = *argv + 1;
            val = strtol(valptr, &endptr, 10);

            if (endptr == valptr) /* there were no digits at all */
            {
                fprintf(stderr, "Error: please provide a valid numberic value for space size\n");
                exit(EXIT_FAILURE);
            }

            space_size = val;
            break;
        }
    }

    /* replace appropriate number of spaces with tabs */
    for (int c, column_pos = 0, space_pos = 0; (c = getchar()) != EOF; column_pos++)
    {
        if (c == '\n')
        {
            column_pos = space_pos = 0;
            putchar('\n');
        }
        else if (c == ' ')
        {
            if (column_pos >= column_start) /* convert spaces only after start column */
            {
                space_pos++;
            }
            else
            {
                putchar(c);
            }
        }
        else
        {
            if (column_pos >= column_start)
            {
                int tabs = space_pos / space_size;
                int spaces = space_pos % space_size;

                for (int i = 0; i < tabs; i++)
                {
                    putchar('\t');
                }
                for (int i = 0; i < spaces; i++)
                {
                    putchar(' ');
                }
                space_pos = 0;
            }
            putchar(c);
        }
    }

    return EXIT_SUCCESS;
}
