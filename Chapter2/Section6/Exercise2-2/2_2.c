#include <stdio.h>
/*  a loop equivalent to the for loop above without using && or || */
main()
{
    int c, i, state = 1, lim = 16;
    char s[lim];

    for (i = 0; state; ++i)
    {
        state = 0;
        if(i < lim - 1)
            if((c = getchar()) != EOF)
                if(c != '\n')
                {
                    s[i] = c;
                    state = 1;
                }
    }
    s[i] = '\0';
    printf("%s", s);
}