#include <stdio.h>

int main()
{
    // program for counting blanks, tabs and newlines
    int blanks, tabs, newlines;

    int c;
    while ( (c = getchar()) != EOF)
        if (c == ' ')
            blanks++;
        else if (c == '\t')
            tabs++;
        else if (c == '\n')
            newlines++;
    
    printf("blanks: %d, tabs: %d, newlines: %d\n", blanks, tabs, newlines);
}