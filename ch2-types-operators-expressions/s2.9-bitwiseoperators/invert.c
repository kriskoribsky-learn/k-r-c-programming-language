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

unsigned int invert(unsigned int x, int p, int n);

int main(void)
{
    unsigned int x = 0b11010111;
    int p = 5;
    int n = 4;

    // expected result: 11101011
    printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(invert(x, p, n)));

    return 0;
}

unsigned int invert(unsigned int x, int p, int n)
{
    // we assume that bit position 0 is at the right end and that n and p are sensible positive values
    // inversion will be done using ~ one's complement operator

    p++; // starting index is 0, adjust it to be 1

    unsigned int mask1 = ~(~0 << n) << (p - n); // very good, fist create ones n positions on the right, then shift to correct pos
    unsigned int mask2 = ~mask1 & x;            // create mask with zeros at target range and x at other positions
    unsigned int result = mask2 | ~x;           // complement x, filling zeros at target range and not changing other bits

    return result;
}