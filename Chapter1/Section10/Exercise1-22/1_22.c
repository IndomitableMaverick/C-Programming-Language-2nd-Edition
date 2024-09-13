#include <stdio.h>
#define N 64
#define PREV_WORD 1    
#define NO_PREV_WORD 0 
/* ''fold'' long input lines into two or more shorter lines after the last non-blank character that occurs before the n-th column of input. 
   To make the output more beautiful, you can use program detab before */
main()
{
    char c;
    int col, state;
    char buffer[N + 1];/* buffer[N] for case that the n-th character is followed by '\n' */

    col = 0;
    state = NO_PREV_WORD;
    buffer[N] = '\0';
    while((c = getchar()) != EOF)
    {
        if(c == '\n')
        {
            for(int i = 0; i < col; ++i)
                putchar(buffer[i]);
            putchar('\n');
            col = 0;
            state = NO_PREV_WORD;
        }
        else
        {
            if(c != ' ' && c != '\t' || state == PREV_WORD)/* eliminate the leading ' ' or '\t' */
            {
                buffer[col++] = c;
                state = PREV_WORD;
            }
            if(col == N + 1)
            {
                while(--col >= 0 && buffer[col] != ' ' && buffer[col] != '\t')
                    ;
                if(col == -1)
                {
                    for(int i = 0; i < N - 1; ++i)
                        putchar(buffer[i]);
                    putchar('-');/* use '-' to divide too long word */
                    col = 0;
                    buffer[col++] = buffer[N - 1];
                    buffer[col++] = buffer[N];
                }
                else
                {
                    for(int i = 0; i < col; ++i)
                        putchar(buffer[i]);
                    int end = col;
                    col = 0;
                    while(++end <= N && (buffer[end] == ' ' || buffer[end] == '\t'))
                        ;/* avoid situations where the endings are all ' ' or '\t */
                    if(end <= N)
                        while(end <= N)
                            buffer[col++] = buffer[end++];
                    else
                        state = NO_PREV_WORD;
                }
                putchar('\n');
            }
        }
    }
    return 0;
}