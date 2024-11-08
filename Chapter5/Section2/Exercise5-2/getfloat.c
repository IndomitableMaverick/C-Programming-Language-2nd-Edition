#include <stdio.h>
#include <ctype.h>

#define NUMBER_NOT_FOUND EOF
#define NUMBER_FOUND 1

int getch(void); 
void ungetch(int); 

/* getint: get next integer from input into *pn */ 
int getfloat(float *pn) 
{ 
    int c, sign, flag, tempSign; 
    double power; 
    
    flag = NUMBER_NOT_FOUND;
    tempSign = -1;

    while (isspace(c = getch())) /* skip white space */ 
        ; 
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') { 
        ungetch(c); /* it is not a number */ 
        return 0; 
    } 
    sign = (c == '-') ? -1 : 1; 
    if ((c == '+' || c == '-')) { // + or - not followed by a digit
        tempSign = c; // store the '+' or '-' sign for further processing
        if(!isdigit(c = getch()) && c != '.'){
            ungetch(c);
            ungetch(sign == 1 ? '+' : '-');
            return 0; 
        }
    }
    if(c != '.') {
        for (*pn = 0.0; isdigit(c); c = getch()) {
            flag = NUMBER_FOUND;
            *pn = 10.0 * *pn + (c - '0'); 
        }
    }
    if (c == '.') 
        if(((c = getch()) == 'e' || c == 'E') && flag == NUMBER_NOT_FOUND
            || !isdigit(c) && c != 'e' && c != 'E') {
            ungetch(c);
            ungetch('.');
            if(tempSign != -1)
                ungetch(tempSign);
            return 0;
        }
    if(flag == NUMBER_NOT_FOUND)
        *pn = 0.0;
    for (power = 1.0; isdigit(c); c = getch()) 
    { 
        flag = NUMBER_FOUND;
        *pn = 10.0 * *pn + (c - '0'); 
        power *= 10; 
    }
    if(flag == NUMBER_FOUND && (c == 'e' || c == 'E'))
    {
        int expVal, expSign, expFlag, temp = c;
        expFlag = NUMBER_NOT_FOUND;
        expSign = ((c = getch()) == '-') ? -1 : 1;
        if (c == '+' || c == '-') 
            c = getch(); 
        for (expVal = 0; isdigit(c); c = getch()) {
            expFlag = NUMBER_FOUND;
            expVal = 10 * expVal + (c - '0');
        }
        if(expSign == 1)
            while(--expVal >= 0)
                power /= 10;
        else if(expSign == -1)
            while(--expVal >= 0)
                power *= 10;
        if(expFlag == NUMBER_NOT_FOUND)
            ungetch(temp);
    }
    *pn = sign * *pn / power;
    if(c != EOF)
        ungetch(c);
    return flag;  
}