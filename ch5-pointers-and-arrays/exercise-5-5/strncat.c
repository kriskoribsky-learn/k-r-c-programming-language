#include <stdio.h>

#define MAX_LEN 100
#define CONCAT_LEN 2

char *strncat(char *restrict dest, const char *restrict src, size_t n);

int main(void)
{
    char s1[2 * MAX_LEN];
    char s2[MAX_LEN];

    printf("First string: ");
    scanf("%s", s1);

    printf("Second string: ");
    scanf("%s", s2);

    printf("First %d chatacters of concatenation result: '%s'\n", CONCAT_LEN, strncat(s1, s2, CONCAT_LEN));
}

char *strncat(char *restrict dest, const char *restrict src, size_t n)
{
    char *start = dest;

    while (*dest++) /* find end of dest */
        ;

    --dest;

    while (n-- > 0 && (*dest++ = *src++)) /* concatenate src to dest */
        ;

    *dest = '\0';

    return start;
}
