#include <stdio.h>

int invert(int x, int p, int n);

main()
{
    printf("%o", invert(065, 3, 3));
    return 0;
}

/* returns x with the n bits that begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged. */
int invert(int x, int p, int n)
{
    int mask = ~(~0 << p + 1) & (~0 << p - n + 1);
    return x ^ mask;
}