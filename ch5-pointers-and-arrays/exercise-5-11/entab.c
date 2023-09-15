#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_TAB_SIZE 4 /* Number of spaces the tab '\t' character should represent */

/* this routine will take only tab size as optional argument instead of list of tab stops */
int main(int argc, char **argv)
{
    int tab_size = argc == 2 ? atoi(argv[1]) : DEFAULT_TAB_SIZE; /* in case of argument error tabs will be deleted */
    int current_blank = 0;

    int c;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            current_blank++;
        }
        else
        {
            int tabs = current_blank / tab_size;
            int spaces = current_blank % tab_size;

            for (int i = 0; i < tabs; i++)
            {
                putchar('\t');
            }
            for (int i = 0; i < spaces; i++)
            {
                putchar(' ');
            }
            current_blank = 0;

            putchar(c); /* put back the last non-blank character */
        }
    }
    return EXIT_SUCCESS;
}
