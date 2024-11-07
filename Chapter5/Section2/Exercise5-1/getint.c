#include <stdio.h>
#include <ctype.h>

#define NUMBER_NOT_FOUND EOF
#define NUMBER_FOUND 1

int getch(void); 
void ungetch(int); 

/* getint: get next integer from input into *pn */ 
int getint(int *pn) 
{ 
    int c, sign, flag;
    flag = NUMBER_NOT_FOUND;

    while (isspace(c = getch())) /* skip white space */ 
        ; 
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') { 
        ungetch(c); /* it is not a number */ 
        return 0; 
    } 
    sign = (c == '-') ? -1 : 1; 
    if (c == '+' || c == '-') 
        if(!isdigit(c = getch())){ // + or - not followed by a digit
            ungetch(c);
            ungetch(sign == 1 ? '+' : '-');
            return 0; 
        }
    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0'); 
        flag = NUMBER_FOUND;
    }
    *pn *= sign; 
    if (c != EOF)
        ungetch(c); 
    else /* This ensures that if a number is followed by EOF, it is still processed correctly. */
        return flag;
}