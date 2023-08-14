#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000 /* max lines to be sorted */
#define MAXLEN 100    /* max length of any input line */

int readlines(char *lineptr[], char *linebuf, int maxlines);
void writelines(char *lineptr[], int nlines);

void my_qsort(char *lineptr[], int left, int right);

int my_getline(char *s, int lim);

/* sort input lines */
int main(void)
{
    int nlines;
    char linebuf[MAXLINES * MAXLEN]; /* storage of input lines */
    char *lineptr[MAXLINES];         /* pointers to input lines */

    if ((nlines = readlines(lineptr, linebuf, MAXLINES)) >= 0)
    {
        my_qsort(lineptr, 0, nlines - 1);
        printf("--------------------\n");
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
}

int readlines(char *lineptr[], char *linebuf, int maxlines) /* read input lines */
{
    int len, nlines;
    char buffer[MAXLEN];

    nlines = 0;
    while ((len = my_getline(buffer, MAXLEN)) > 0)
    {
        if (nlines >= maxlines)
        {
            return -1;
        }

        buffer[len - 1] = '\0'; /* delete '\n' */
        strcpy(linebuf, buffer);
        lineptr[nlines++] = linebuf;
        linebuf += len; /* shift buffer space */
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines) /* write ouput lines */
{
    while (nlines-- > 0)
    {
        printf("%s\n", *lineptr++);
    }
}

void my_qsort(char *v[], int left, int right) /* sort v[left]...v[right] into increasing order */
{
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)
    {
        return;
    }

    swap(v, left, left + (right - left) / 2);
    last = left;

    for (i = left + 1; i <= right; i++)
    {
        if (strcmp(v[i], v[left]) < 0)
        {
            swap(v, ++last, i);
        }
    }

    swap(v, left, last);

    my_qsort(v, left, last - 1);
    my_qsort(v, last + 1, right);
}

void swap(char *v[], int i, int j) /* interchange v[i] and v[j] */
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int my_getline(char *s, int lim) /* read a line into s, return length */
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        s[i] = c;
    }
    if (c == '\n')
    {
        s[i++] = c;
    }

    s[i] = '\0';
    return i;
}
