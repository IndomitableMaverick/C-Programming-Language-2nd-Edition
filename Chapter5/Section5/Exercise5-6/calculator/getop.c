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
static int getCommand(char *s)
{
    static char *commands[] = {
        "error", "top", "duplicate", "swap", "clear", "sin", 
        "cos", "tan", "asin", "acos", "atan", "atan2", 
        "sinh", "cosh", "tanh", "exp", "log", "log10", 
        "pow", "sqrt", "ceil", "floor", "fabs", "ldexp", 
        "fmod", "Ans"
    };
    switch (s[0]) {
    case 'a':
        if(strlen(s) == 1)
            return ERROR;
        switch (s[1]) {
        case 'c'://acos
            return strcmp(s, *(commands + 9)) == 0 ? ACOS : ERROR;
            break;
        case 's'://asin
            return strcmp(s, *(commands + 8)) == 0 ? ASIN : ERROR;;
            break;
        case 't'://atan & atan2
            if(strlen(s) < strlen(*(commands + 10)))
                return ERROR;
            for(int i = 2; i < strlen(*(commands + 10)); ++i)
                if(*(*(commands + 10) + i) != s[i])
                    return ERROR;
            if(s[strlen(*(commands + 10))] == '\0')
                return ATAN;
            else if(s[strlen(*(commands + 11)) - 1] == '2' && s[strlen(*(commands + 11))] == '\0')
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
            return strcmp(s, *(commands + 20)) == 0 ? CEIL : ERROR;
            break;
        case 'l'://clear
            return strcmp(s, *(commands + 4)) == 0 ? CLEAR : ERROR;
            break;
        case 'o'://cos & cosh
            if(strlen(s) < strlen(*(commands + 6)))
                return ERROR;
            for(int i = 2; i < strlen(*(commands + 6)); ++i)
                if(*(*(commands + 6) + i) != s[i])
                    return ERROR;
            if(s[strlen(*(commands + 6))] == '\0')
                return COS;
            else if(s[strlen(*(commands + 13)) - 1] == 'h' && s[strlen(*(commands + 13))] == '\0')
                return COSH;
            else
                return ERROR;
            break;
        default:
            break;
        }
        break;
    case 'd'://duplicate
        return strcmp(s, *(commands + 2)) == 0 ? DUPLICATE : ERROR;
        break;
    case 'e'://exp
        return strcmp(s, *(commands + 15)) == 0 ? EXP : ERROR;
        break;
    case 'f':
        if(strlen(s) == 1)
            return ERROR;
        switch (s[1]) {
        case 'a'://fabs
            return strcmp(s, *(commands + 22)) == 0 ? FABS : ERROR;
            break;
        case 'l'://floor
            return strcmp(s, *(commands + 21)) == 0 ? FLOOR : ERROR;
            break;
        case 'm'://fmod
            return strcmp(s, *(commands + 24)) == 0 ? FMOD : ERROR;
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
            return strcmp(s, *(commands + 23)) == 0 ? LDEXP : ERROR;
            break;
        case 'o'://log & log10
            if(strlen(s) < strlen(*(commands + 16)))
                return ERROR;
            for(int i = 2; i < strlen(*(commands + 16)); ++i)
                if(*(*(commands + 16) + i) != s[i])
                    return ERROR;
            if(s[strlen(*(commands + 16))] == '\0')
                return LOG;
            else{
                for(int i = strlen(*(commands + 16)); i < strlen(*(commands + 17)); ++i)
                    if(*(*(commands + 17) + i) != s[i])
                        return ERROR;
                return s[strlen(*(commands + 17))] == '\0' ? LOG10 : ERROR;
            }
            break;
        default:
            break;
        }
        break;
    case 'p'://pow
        return strcmp(s, *(commands + 18)) == 0 ? POW : ERROR;
        break;
    case 's':
        if(strlen(s) == 1)
            return ERROR;
        switch (s[1]) {
        case 'i'://sin & sinh
            if(strlen(s) < strlen(*(commands + 5)))
                return ERROR;
            for(int i = 2; i < strlen(*(commands + 5)); ++i)
                if(*(*(commands + 5) + i) != s[i])
                    return ERROR;
            if(s[strlen(*(commands + 5))] == '\0')
                return SIN;
            else{
                for(int i = strlen(*(commands + 5)); i < strlen(*(commands + 12)); ++i)
                    if(*(*(commands + 12) + i) != s[i])
                        return ERROR;
                return s[strlen(*(commands + 12))] == '\0' ? SINH : ERROR;
            }
            break;
        case 'q'://sqrt
            return strcmp(s, *(commands + 19)) == 0 ? SQRT : ERROR;
            break;
        case 'w'://swap
            return strcmp(s, *(commands + 3)) == 0 ? SWAP : ERROR;
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
            if(strlen(s) < strlen(*(commands + 7)))
                return ERROR;
            for(int i = 2; i < strlen(*(commands + 7)); ++i)
                if(*(*(commands + 7) + i) != s[i])
                    return ERROR;
            if(s[strlen(*(commands + 7))] == '\0')
                return TAN;
            else{
                for(int i = strlen(*(commands + 7)); i < strlen(*(commands + 14)); ++i)
                    if(*(*(commands + 14) + i) != s[i])
                        return ERROR;
                return s[strlen(*(commands + 14))] == '\0' ? TANH : ERROR;
            }
            break;
        case 'o'://top
            return strcmp(s, *(commands + 1)) == 0 ? TOP : ERROR;
            break;
        default:
            break;
        }
        break;
    case 'A'://Ans(a variable for the most recently printed value).
        return strcmp(s, *(commands + 25)) == 0 ? ANS : ERROR;
        break;
    default:
        break;
    }
    return ERROR;
}