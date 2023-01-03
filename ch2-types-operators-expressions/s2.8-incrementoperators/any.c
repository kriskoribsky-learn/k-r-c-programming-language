#include <stdio.h>
#include <stdlib.h>

int any(char s1[], char s2[]);

int main (int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Wrong number of arguments!\nUsage: ./squeeze <original string> <string of values to find>\n");
        return EXIT_FAILURE;
    }

    printf("%d\n", any(argv[1], argv[2]));

    return EXIT_SUCCESS;
}

int any(char s1[], char s2[])
{
    int i, j;
    for (i = 0; s1[i] != '\0'; i++)
        for (j = 0; s2[j] != '\0'; j++)
            if (s1[i] == s2[j])
                return i;
    
    return -1;
}
