#include <stdio.h>

#define MAX_LEN 100

char *strcat(char *dest, const char *restrict src);

int main(void)
{
    char s1[2 * MAX_LEN];
    char s2[MAX_LEN];

    printf("First string: ");
    scanf("%s", s1);

    printf("Second string: ");
    scanf("%s", s2);

    printf("Concatenation result: '%s'\n", strcat(s1, s2));
}

char *strcat(char *dest, const char *restrict src)
{
    char *start = dest;

    while (*dest++) /* find end of dest */
        ;

    --dest;

    while (*dest++ = *src++) /* concatenate src to dest */
        ;

    return start;
}
