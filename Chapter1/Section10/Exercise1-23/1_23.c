#include <stdio.h>
//STATE's meaning is in the 1_23.md
#define STATE0 0
#define STATE1 1
#define STATE2 2
#define STATE3 3
#define STATE4 4
#define STATE5 5
#define STATE6 6
/* remove all comments from a C program */
main()
{
    char c;
    int state;

    state = STATE0;
    while((c = getchar()) != EOF)
    {
        switch (state)
        {
            case STATE0:
                if(c == '/')
                    state = STATE1;
                else
                {
                    putchar(c);
                    if(c == '\'')
                        state = STATE5;
                    else if(c == '"')
                        state = STATE6;
                }
                break;
            case STATE1:
                if(c == '/')
                    state = STATE2;
                else if(c == '*')
                    state = STATE3;
                else
                {
                    putchar('/');
                    putchar(c);
                    if(c == '\'')
                        state = STATE5;
                    else if(c == '"')
                        state = STATE6;
                    else
                        state = STATE0;
                }
                break;
            case STATE2:
                if(c == '\n')
                {
                    putchar(c);
                    state = STATE0;
                }
                break;
            case STATE3:
                if(c == '*')
                    state = STATE4;
                break;
            case STATE4:
                if(c == '/')
                    state = STATE0;
                else if(c != '*')
                    state = STATE3;
                break;
            case STATE5:
                putchar(c);
                if(c == '\'')
                    state = STATE0;
                break;
            case STATE6:
                putchar(c);
                if(c == '"')
                    state = STATE0;
                break;
            default:
                break;
        }
    }
    return 0;
}