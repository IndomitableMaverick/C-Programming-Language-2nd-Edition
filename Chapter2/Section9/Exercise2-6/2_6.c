#include <stdio.h>

int setbits(int x, int p, int n, int y);

main()
{
    printf("%o", setbits(065, 3, 3, 013));
    return 0;
}

/* returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged. */
int setbits(int x, int p, int n, int y)
{
    int mask = ~(~0 << p + 1) & (~0 << p - n + 1);
    return ~mask & x | mask & y << n - p + 1;
}