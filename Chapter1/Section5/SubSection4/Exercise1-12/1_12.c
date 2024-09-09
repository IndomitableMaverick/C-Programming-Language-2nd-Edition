#include <stdio.h>
#define NEWLINE 1 /* can newline */
#define NONEWLINE 0 /* cannot newline */
/* prints its input one word per line. */
main()
{
    int c, state;
    state = NONEWLINE;
    while ((c = getchar()) != EOF) 
        if (c == ' ' || c == '\n' || c == '\t')
        {
            if(state == NEWLINE)
                putchar('\n');
            state = NONEWLINE;
        }
        else
        {
            putchar(c);
            state = NEWLINE;
        }
}