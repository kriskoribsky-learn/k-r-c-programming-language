#include <stdio.h>

#define MAX_LEN 100

char *strncpy(char *restrict dest, const char *restrict src, size_t n);

int main(void)
{
    char s1[2 * MAX_LEN];
    char s2[MAX_LEN];

    printf("First string: ");
    scanf("%s", s1);

    printf("Second string: ");
    scanf("%s", s2);

    printf("Copied from second string to the first: '%s'\n", strncpy(s1, s2, MAX_LEN));
}

char *strncpy(char *restrict dest, const char *restrict src, size_t n)
{
    char *start = (char *)src;

    while ((*dest++ = *src++) && --n > 0)
        ;

    return start;
}
