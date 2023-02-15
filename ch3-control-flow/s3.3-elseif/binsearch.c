#include <stdio.h>

int binsearch(int x, int v[], int n);

int main (void)
{
    int v[] = {1, 2, 3, 4, 5, 6, 5, 8, 9, 10};

    printf("%d\n", binsearch(8, v, 10));

    return 0;
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n-1;
    while (low <= high) {
        mid = (low+high) / 2;

        if (x < v[mid])
            high = mid-1;
        else
            low = mid+1;
    }
    return x == v[low - 1] ? low - 1 : -1;
}
