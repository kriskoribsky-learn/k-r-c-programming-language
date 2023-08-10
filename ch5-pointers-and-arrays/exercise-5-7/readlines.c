#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /* max lines to be sorted */

char *lineptr[MAXLINES]; /* pointers to input lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

/* sort input lines */
int main(void)
{
    int nlines;

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 100 /* max length of any input line */
int getline(char *, int);

int readlines(char *lineptr[], int maxlines) /* read input lines */
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || (p = malloc(len * sizeof(char))) == NULL)
        {
            return -1;
        }

        line[len - 1] = '\0'; /* delete newline */
        strcpy(p, line);
        lineptr[nlines++] = p;
    }
    return nlines;
}


