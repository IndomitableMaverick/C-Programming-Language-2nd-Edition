#include <stdio.h>
#include "calc.h"

#define MAXVAL 100 /* maximum depth of val stack */ 

static double val[MAXVAL]; /* value stack */ 
static double *sp = val; /* next free stack position */ 

/* push: push f onto value stack */ 
void push(double f) 
{ 
    if (sp - val < MAXVAL) 
        *sp++ = f; 
    else 
        printf("error: stack full, can't push %g\n", f); 
} 

/* pop: pop and return top value from stack */ 
double pop(void) 
{ 
    if (sp > val) 
        return *--sp; 
    else { 
        printf("error: stack empty\n"); 
        return 0.0; 
    } 
}

/* top: return top value from stack without pop it */
double top(void)
{
    if (sp > val) 
        return *(sp - 1); 
    else { 
        printf("error: stack empty\n"); 
        return 0.0; 
    } 
}

/* clear: clear the stack */
void clear(void)
{
    sp = val;
}