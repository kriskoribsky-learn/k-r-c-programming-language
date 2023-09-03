#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_TAB_SIZE 8 /* Number of spaces the tab '\t' character should represent */

/* this routine will take only tab size as optional argument instead of list of tab stops */
int main(int argc, char **argv)
{
    int tab_size = argc == 2 ? atoi(argv[1]) : DEFAULT_TAB_SIZE; /* in case of argument error tabs will be deleted */

    int c;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            for (int i = 0; i < tab_size; i++)
            {
                putchar(' ');
            }
        }
        else
        {
            putchar(c);
        }
    }
    return EXIT_SUCCESS;
}
