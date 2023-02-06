#include <stdio.h>

#define MAX_BITS 8

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c\n"
#define BYTE_TO_BINARY(byte)     \
    (byte & 128 ? '1' : '0'),    \
        (byte & 64 ? '1' : '0'), \
        (byte & 32 ? '1' : '0'), \
        (byte & 16 ? '1' : '0'), \
        (byte & 8 ? '1' : '0'),  \
        (byte & 4 ? '1' : '0'),  \
        (byte & 2 ? '1' : '0'),  \
        (byte & 1 ? '1' : '0')

unsigned int rightrot(unsigned int x, int n);

int main(void)
{
    unsigned int x = 0b10001110;
    int n = 4;

    // expected result: 11101000
    printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(rightrot(x, n)));

    return 0;
}

unsigned int rightrot(unsigned int x, int n)
{
    unsigned int mask1 = x >> n;              // x shifted to the right by n bits (right bits fall out)
    unsigned int mask2 = x << (MAX_BITS - n); // x shifted to the left by max-n bits (right bits get to the correct pos)
    unsigned int result = mask1 | mask2;

    return result;
}