#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Wrong number of arguments!\nUsage: ./expr <expression>\n");
        return EXIT_FAILURE;
    }
}
