#include <stdio.h>
#include <string.h>

#define MAX_LEN 100
#define CMP_LEN 100

int strncmp(const char *s1, const char *s2, size_t n);

int main(void)
{
    char s1[2 * MAX_LEN];
    char s2[MAX_LEN];

    printf("First string: ");
    scanf("%s", s1);

    printf("Second string: ");
    scanf("%s", s2);

    printf("Result of comparison of first %d chatacters: '%d'\n", CMP_LEN, strncmp(s1, s2, CMP_LEN));
}

int strncmp(const char *s1, const char *s2, size_t n)
{
    while (n-- > 0 && *s1 != '\0' && *s1++ == *s2++)
        ;

    return *--s1 - *--s2;
}
