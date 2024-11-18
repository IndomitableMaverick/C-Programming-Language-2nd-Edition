#include <stdio.h>

#undef LINE_OK
#define LINE_OK 0
#undef LINE_TOO_LONG
#define LINE_TOO_LONG 1

/* getline: read a line into s, return length */
int getline(char *s, int lim)
{
    int c, i, state;
    
    state = LINE_OK;
    for (i = 0; state == LINE_OK && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        *(s + i) = c;
        if(i == lim - 2)
            state = LINE_TOO_LONG;
    }
    if(c == '\n')
    {
        *(s + i) = '\n';
        ++i;
    }
    *(s + i) = '\0';

    if(state == LINE_TOO_LONG)
    {
        while((c = getchar()) != EOF && c != '\n')
            ++i;
        if(c == '\n')
            ++i;
    }

    return i;
}