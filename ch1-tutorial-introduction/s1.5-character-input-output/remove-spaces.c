#include <stdio.h>

// replace multiple spaces with a single space character
int main ()
{
    int c;
    // iterate to the end of a stdin
    while ( (c = getchar()) != EOF) {
        int nl = -1;
        // iterate while space is present
        while ( (nl = getchar()) == '\n')
            ;
        if (nl == '\n')
            putchar('\n');

        putchar(c);
    }
}