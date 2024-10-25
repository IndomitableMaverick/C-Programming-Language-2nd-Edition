#include <math.h>
#include <stdio.h> 
#include <stdlib.h> /* for atof() */ 

#define MAXOP 100 /* max size of operand or operator */ 
#define NUMBER '0' /* signal that a number was found */ 
enum commands { ERROR = 128, TOP, DUPLICATE, SWAP, CLEAR,
                SIN, COS, TAN, ASIN, ACOS, ATAN,
                ATAN2, SINH, COSH, TANH, EXP, LOG,
                LOG10, POW, SQRT, CEIL, FLOOR, FABS,
                LDEXP, FMOD, ANS };

int getop(char []); 
void push(double); 
double pop(void); 
double top(void);
void clear(void);

/* reverse Polish calculator, add a variable(Ans) for the most recently printed value. */ 
int main() 
{ 
    int type; 
    double op1, op2, ans; 
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
    if (c == '*' || c == '/' || c == '%' || c == '\n' || c == EOF) 
        return c; /* operator or \n */ 
    i = 0; 
    if((c == '+' || c == '-'))
        if(!(isdigit(s[++i] = c = getch()) || c == '.')){
            // This block handles the '+' and '-' as operators.
            if (c != EOF) 
                ungetch(c); 
            return s[0];
        }
    if(isdigit(c) || c == '.'){
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
        while(isalpha(s[++i] = c = getch()) || isdigit(c))
            ;
        s[i] = '\0'; //handle '\n'
        if (c != EOF)
            ungetch(c); 
        return getCommand(s);
    }
}

/* getCommand: return command */
int getCommand(char s[])
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