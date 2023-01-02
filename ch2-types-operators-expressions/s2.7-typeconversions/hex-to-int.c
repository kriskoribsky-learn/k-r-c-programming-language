#include <stdlib.h>
#include <stdio.h>

int htoi(char *s);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Wrong number of arguments!\nUsage: ./hex-to-int <hex value>\n");
        return EXIT_FAILURE;
    }

    printf("%d\n", htoi(argv[1]));
    return EXIT_SUCCESS;
}

int htoi(char *s)rm 
{
    int n, i;

    n = 0;
    for (i = (s[1] == 'x' || s[1] == 'X' ? 2 : 0); (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f') || (s[i] >= 'A' && s[i] <= 'F'); i++)
    {
        int x;

        if (s[i] >= '0' && s[i] <= '9')
            x = s[i] - '0';
        else if (s[i] >= 'a' && s[i] <= 'f')
            x = 10 + s[i] - 'a';
        else
        {
            x = 10 + s[i] - 'A';
        }

        n = n * 16 + x;
    }
    return n;
}
