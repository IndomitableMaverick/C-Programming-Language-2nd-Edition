#include <stdio.h>

#define BUFSIZE 100 

static char buf[BUFSIZE]; /* buffer for ungetch */ 
static char *bufp = buf;/* next free position in buf */ 

int getch(void) /* get a (possibly pushed-back) character */ 
{ 
    return (bufp > buf) ? *--bufp : getchar(); 
} 

void ungetch(int c) /* push character back on input */ 
{ 
    if (bufp - buf >= BUFSIZE) 
        printf("ungetch: too many characters\n"); 
    else 
        *bufp++ = c; 
}