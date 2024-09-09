#include <stdio.h>
/* A program to copy its input to its output, replacing each string of one or more blanks by a single blank. */
main()
{
    int c;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            while((c = getchar()) != EOF && c == ' ')
                ;
            putchar(' ');
        }
        putchar(c);
    }
}