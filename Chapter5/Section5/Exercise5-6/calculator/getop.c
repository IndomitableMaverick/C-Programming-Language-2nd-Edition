#include <ctype.h> 
#include <stdio.h>
#include <string.h>
#include "calc.h"

static int getCommand(char s[]);

/* getop: get next character or numeric operand or command */ 
int getop(char *s) 
{ 
    int c; 
    char *start_s = s;
    while ((*s = c = getch()) == ' ' || c == '\t') 
        ; 
    *++s = '\0'; 
    if (c == '*' || c == '/' || c == '%' || c == '\n' || c == EOF) 
        return c; /* operator or \n */ 
    s = start_s;
    if((c == '+' || c == '-'))
        if(!(isdigit(*++s = c = getch()) || c == '.')){
            // This block handles the '+' and '-' as operators.
            if (c != EOF) 
                ungetch(c); 
            return *start_s;
        }
    if(isdigit(c) || c == '.'){
        if (isdigit(c)) /* collect integer part */ 
            while (isdigit(*++s = c = getch())) 
                ; 
        if (c == '.') /* collect fraction part */ 
            while (isdigit(*++s = c = getch())) 
                ; 
        *s = '\0'; 
        if (c != EOF) 
            ungetch(c); 
        return NUMBER;
    }
    else{
        while(isalpha(*++s = c = getch()) || isdigit(c))
            ;
        *s = '\0'; //handle '\n'
        if (c != EOF)
            ungetch(c); 
        return getCommand(start_s);
    }
}

/* getCommand: return command */
static int getCommand(char s[])
{
    //so ugly, this will be refined later...
    char command1[] = "top"; 
    char command2[] = "duplicate";
    char command3[] = "swap"; 
    char command4[] = "clear";
    char command5[] = "sin";
    char command6[] = "cos";
    char command7[] = "tan";
    char command8[] = "asin";
    char command9[] = "acos";
    char command10[] = "atan";
    char command11[] = "atan2";
    char command12[] = "sinh";
    char command13[] = "cosh";
    char command14[] = "tanh";
    char command15[] = "exp";
    char command16[] = "log";
    char command17[] = "log10";
    char command18[] = "pow";
    char command19[] = "sqrt";
    char command20[] = "ceil";
    char command21[] = "floor";
    char command22[] = "fabs";
    char command23[] = "ldexp";
    char command24[] = "fmod";
    char command25[] = "Ans";
    switch (s[0]) {
    case 'a':
        if(strlen(s) == 1)
            return ERROR;
        switch (s[1]) {
        case 'c'://acos
            return strcmp(s, command9) == 0 ? ACOS : ERROR;
            break;
        case 's'://asin
            return strcmp(s, command8) == 0 ? ASIN : ERROR;;
            break;
        case 't'://atan & atan2
            if(strlen(s) < strlen(command10))
                return ERROR;
            for(int i = 2; i < strlen(command10); ++i)
                if(command10[i] != s[i])
                    return ERROR;
            if(s[strlen(command10)] == '\0')
                return ATAN;
            else if(s[strlen(command11) - 1] == '2' && s[strlen(command11)] == '\0')
                return ATAN2;
            else
                return ERROR;
            break;
        default:
            break;
        }
        break;
    case 'c':
        if(strlen(s) == 1)
            return ERROR;
        switch (s[1]) {
        case 'e'://ceil
            return strcmp(s, command20) == 0 ? CEIL : ERROR;
            break;
        case 'l'://clear
            return strcmp(s, command4) == 0 ? CLEAR : ERROR;
            break;
        case 'o'://cos & cosh
            if(strlen(s) < strlen(command6))
                return ERROR;
            for(int i = 2; i < strlen(command6); ++i)
                if(command6[i] != s[i])
                    return ERROR;
            if(s[strlen(command6)] == '\0')
                return COS;
            else if(s[strlen(command13) - 1] == 'h' && s[strlen(command13)] == '\0')
                return COSH;
            else
                return ERROR;
            break;
        default:
            break;
        }
        break;
    case 'd'://duplicate
        return strcmp(s, command2) == 0 ? DUPLICATE : ERROR;
        break;
    case 'e'://exp
        return strcmp(s, command15) == 0 ? EXP : ERROR;
        break;
    case 'f':
        if(strlen(s) == 1)
            return ERROR;
        switch (s[1]) {
        case 'a'://fabs
            return strcmp(s, command22) == 0 ? FABS : ERROR;
            break;
        case 'l'://floor
            return strcmp(s, command21) == 0 ? FLOOR : ERROR;
            break;
        case 'm'://fmod
            return strcmp(s, command24) == 0 ? FMOD : ERROR;
            break;
        default:
            break;
        }
        break;
    case 'l':
        if(strlen(s) == 1)
            return ERROR;
        switch (s[1]) {
        case 'd'://ldexp
            return strcmp(s, command23) == 0 ? LDEXP : ERROR;
            break;
        case 'o'://log & log10
            if(strlen(s) < strlen(command16))
                return ERROR;
            for(int i = 2; i < strlen(command16); ++i)
                if(command16[i] != s[i])
                    return ERROR;
            if(s[strlen(command16)] == '\0')
                return LOG;
            else{
                for(int i = strlen(command16); i < strlen(command17); ++i)
                    if(command17[i] != s[i])
                        return ERROR;
                return s[strlen(command17)] == '\0' ? LOG10 : ERROR;
            }
            break;
        default:
            break;
        }
        break;
    case 'p'://pow
        return strcmp(s, command18) == 0 ? POW : ERROR;
        break;
    case 's':
        if(strlen(s) == 1)
            return ERROR;
        switch (s[1]) {
        case 'i'://sin & sinh
            if(strlen(s) < strlen(command5))
                return ERROR;
            for(int i = 2; i < strlen(command5); ++i)
                if(command5[i] != s[i])
                    return ERROR;
            if(s[strlen(command5)] == '\0')
                return SIN;
            else{
                for(int i = strlen(command5); i < strlen(command12); ++i)
                    if(command12[i] != s[i])
                        return ERROR;
                return s[strlen(command12)] == '\0' ? SINH : ERROR;
            }
            break;
        case 'q'://sqrt
            return strcmp(s, command19) == 0 ? SQRT : ERROR;
            break;
        case 'w'://swap
            return strcmp(s, command3) == 0 ? SWAP : ERROR;
            break;
        default:
            break;
        }
        break;
    case 't':
        if(strlen(s) == 1)
            return ERROR;
        switch (s[1]) {
        case 'a'://tan & tanh
            if(strlen(s) < strlen(command7))
                return ERROR;
            for(int i = 2; i < strlen(command7); ++i)
                if(command7[i] != s[i])
                    return ERROR;
            if(s[strlen(command7)] == '\0')
                return TAN;
            else{
                for(int i = strlen(command7); i < strlen(command14); ++i)
                    if(command14[i] != s[i])
                        return ERROR;
                return s[strlen(command14)] == '\0' ? TANH : ERROR;
            }
            break;
        case 'o'://top
            return strcmp(s, command1) == 0 ? TOP : ERROR;
            break;
        default:
            break;
        }
        break;
    case 'A'://Ans(a variable for the most recently printed value).
        return strcmp(s, command25) == 0 ? ANS : ERROR;
        break;
    default:
        break;
    }
    return ERROR;
}