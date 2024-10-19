#include <stdio.h> 
#include <stdlib.h> /* for atof() */ 

#define MAXOP 100 /* max size of operand or operator */ 
#define NUMBER '0' /* signal that a number was found */ 
#define ERROR 0 /* unknown command */
#define TOP 1 /* command: top */
#define DUPLICATE 2 /* command: duplicate */
#define SWAP 3 /* command: swap */
#define CLEAR 4 /* command: clear */

int getop(char []); 
void push(double); 
double pop(void); 
double top(void);
void duplicate(void);
void swap(void);
void clear(void);

/* reverse Polish calculator */ 
int main() 
{ 
    int type; 
    double op1, op2; 
    char s[MAXOP]; 
    while ((type = getop(s)) != EOF) { 
        switch (type) {
        case ERROR:
            printf("error: unknown command %s\n", s); 
            break;
        case TOP:
            printf("\t%.8g\n", top());
            break;
        case DUPLICATE:
            duplicate();
            break;
        case SWAP:
            swap();
            break;
        case CLEAR:
            clear();
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
            printf("\t%.8g\n", pop()); 
            break; 
        default: 
            printf("error: unknown command %s\n", s); 
            break; 
        } 
    } 
    return 0; 
}


#define MAXVAL 100 /* maximum depth of val stack */ 

int sp = 0; /* next free stack position */ 
double val[MAXVAL]; /* value stack */ 

/* push: push f onto value stack */ 
void push(double f) 
{ 
    if (sp < MAXVAL) 
        val[sp++] = f; 
    else 
        printf("error: stack full, can't push %g\n", f); 
} 

/* pop: pop and return top value from stack */ 
double pop(void) 
{ 
    if (sp > 0) 
        return val[--sp]; 
    else { 
        printf("error: stack empty\n"); 
        return 0.0; 
    } 
}

/* top: return top value from stack without pop it */
double top(void)
{
    if (sp > 0) 
        return val[sp - 1]; 
    else { 
        printf("error: stack empty\n"); 
        return 0.0; 
    } 
}

/* duplicate: duplicate top value */
void duplicate(void)
{
    if (sp > 0 && sp < MAXVAL) {
        val[sp] = val[sp - 1];
        ++sp;
    } 
    else { 
        if(sp <= 0)
            printf("error: stack empty\n"); 
        else
            printf("error: stack full\n");
    } 
}

/* swap: swap the top two elements */
void swap(void)
{
    if (sp > 1) {
        double temp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = temp;
    } 
    else 
        printf("error: not enough items on stack\n"); 
} 

/* clear: clear the stack */
void clear(void)
{
    sp = 0;
}   


#include <ctype.h> 
#include <string.h>

int getch(void); 
void ungetch(int); 
int getCommand(char s[]);

/* getop: get next character or numeric operand */ 
int getop(char s[]) 
{ 
    int i, c; 
    while ((s[0] = c = getch()) == ' ' || c == '\t') 
        ; 
    s[1] = '\0'; 
    if (c == '*' || c == '/' || c == '%' || c == '\n') 
        return c; /* operator or \n */ 
    i = 0; 
    if((c == '+' || c == '-')){
        if(!(isdigit(s[++i] = c = getch()) || c == '.')){
            // This block handles the '+' and '-' as operators.
            if (c != EOF) 
                ungetch(c); 
            return s[0];
        }
    }
    else if(isdigit(c) || c == '.'){
        if (isdigit(c)) /* collect integer part */ 
            while (isdigit(s[++i] = c = getch())) 
                ; 
        if (c == '.') /* collect fraction part */ 
            while (isdigit(s[++i] = c = getch())) 
                ; 
        s[i] = '\0'; 
        if (c != EOF) 
            ungetch(c); 
        return NUMBER;
    }
    else{
        if(c == EOF)
            return EOF;
        while(isalpha(s[++i] = c = getch()) || isdigit(c))
            ;
        if (c != EOF){
            s[strlen(s) - 1] = '\0'; //handle '\n'
            ungetch(c); 
        }
        return getCommand(s);
    }
}

/* getCommand: return command */
int getCommand(char s[])
{
    char command1[] = "top"; 
    char command2[] = "duplicate";
    char command3[] = "swap"; 
    char command4[] = "clear";  
    switch (s[0]) {
    case 't':
        for(int i = 0; i < strlen(command1); ++i)
            if(command1[i] != s[i])
                return ERROR;
        return s[strlen(command1)] == '\0' ? TOP : ERROR;
        break;
    case 'd':
        for(int i = 0; i < strlen(command2); ++i)
            if(command2[i] != s[i])
                return ERROR;
        return s[strlen(command2)] == '\0' ? DUPLICATE : ERROR;
        break;
    case 's':
        for(int i = 0; i < strlen(command3); ++i)
            if(command3[i] != s[i])
                return ERROR;
        return s[strlen(command3)] == '\0' ? SWAP : ERROR;
        break;
    case 'c':
        for(int i = 0; i < strlen(command4); ++i)
            if(command4[i] != s[i])
                return ERROR;
        return s[strlen(command4)] == '\0' ? CLEAR : ERROR;
        break;
    default:
        break;
    }
    return ERROR;
}


#define BUFSIZE 100 

char buf[BUFSIZE]; /* buffer for ungetch */ 
int bufp = 0; /* next free position in buf */ 

int getch(void) /* get a (possibly pushed-back) character */ 
{ 
    return (bufp > 0) ? buf[--bufp] : getchar(); 
} 

void ungetch(int c) /* push character back on input */ 
{ 
    if (bufp >= BUFSIZE) 
        printf("ungetch: too many characters\n"); 
    else 
        buf[bufp++] = c; 
}