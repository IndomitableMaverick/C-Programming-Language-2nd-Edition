#include <math.h>
#include <stdio.h> 
#include <stdlib.h> /* for atof() */ 
#include "calc.h"

#define MAXOP 100 /* max size of operand or operator */ 

int main(int argc, char *argv[]) 
{ 
    void reverse(char *s);
    int type; 
    double op1, op2, ans; 
    char s[MAXOP], *arg; 
    ungetch(-1); /* Push -1(EOF) into the buffer as a termination signal */
    ungetch('\n');
    while (--argc > 0) {
        arg = *(argv + argc);
        reverse(arg);
        while(*arg)
            ungetch(*arg++);
        ungetch(' ');
    }
    while ((type = getop(s)) != EOF) { 
        switch (type) {
        case ERROR:
            printf("error: unknown command %s\n", s); 
            break;
        case TOP:
            printf("\t%.8g\n", top());
            break;
        case DUPLICATE:
            op1 = pop();
            push(op1);
            push(op1);
            break;
        case SWAP:
            op1 = pop();
            op2 = pop();
            push(op1);
            push(op2);
            break;
        case CLEAR:
            clear();
            break;
        case SIN:
            push(sin(pop())); 
            break;
        case COS:
            push(cos(pop())); 
            break;
        case TAN:
            push(tan(pop())); 
            break;
        case ASIN:
            push(asin(pop())); 
            break;
        case ACOS:
            push(acos(pop())); 
            break;
        case ATAN:
            push(atan(pop())); 
            break;
        case ATAN2:
            op2 = pop();
            push(atan2(pop(), op2));
            break;
        case SINH:
            push(sinh(pop())); 
            break;
        case COSH:
            push(cosh(pop())); 
            break;
        case TANH:
            push(tanh(pop())); 
            break;
        case EXP:
            push(exp(pop())); 
            break;
        case LOG:
            push(log(pop())); 
            break;
        case LOG10:
            push(log10(pop())); 
            break;
        case POW:
            op2 = pop();
            push(pow(pop(), op2));
            break;
        case SQRT:
            push(sqrt(pop())); 
            break;
        case CEIL:
            push(ceil(pop())); 
            break;
        case FLOOR:
            push(floor(pop())); 
            break;
        case FABS:
            push(fabs(pop())); 
            break;
        case LDEXP:
            op2 = pop();
            push(ldexp(pop(), op2));
            break;
        case FMOD:
            op2 = pop();
            push(fmod(pop(), op2));
            break;
        case ANS:
            push(ans);
            break;
        case NUMBER: 
            push(atof(s)); 
            break; 
        case '+': 
            push(pop() + pop()); 
            break; 
        case '*': 
            push(pop() * pop()); 
            break; 
        case '-': 
            op2 = pop(); 
            push(pop() - op2); 
            break; 
        case '/': 
            op2 = pop(); 
            if (op2 != 0.0) 
                push(pop() / op2); 
            else 
                printf("error: zero divisor\n"); 
            break; 
        case '%':
            op2 = pop();
            op1 = pop(); 
            if (op2 != 0.0) 
                push((int)(op1 - (int)(op1 / op2) * op2)); // always returns a positive result.
            else 
                printf("error: zero divisor\n"); 
            break; 
        case '\n': 
            ans = pop();
            printf("\t%.8g\n", ans); 
            break; 
        default: 
            printf("error: unknown command %s\n", s); 
            break; 
        } 
    } 
    return 0; 
}