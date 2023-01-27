#include <stdio.h>

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

unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{
    p++; // first position is 0

    unsigned int maskX = x;

    unsigned int nY = y & ~(~0 << n); // rightmost n-bits of y
    unsigned int maskY_right = nY << (p-n) | ~(~0 << (p-n)); // pad with 1s after nY
    unsigned int maskY_left = ~0 << p;  // pad with 1s before p

    return maskX & (maskY_right | maskY_left);
}

int main(void)
{

    unsigned int x = 0b11111111;
    unsigned int y = 0b0010;

    printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(x));
    printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(setbits(x, 4, 4, y)));

    return 0;
}