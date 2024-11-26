#define NUMBER '0'
enum commands { ERROR = 128, TOP, DUPLICATE, SWAP, CLEAR,
                SIN, COS, TAN, ASIN, ACOS, ATAN,
                ATAN2, SINH, COSH, TANH, EXP, LOG,
                LOG10, POW, SQRT, CEIL, FLOOR, FABS,
                LDEXP, FMOD, ANS };

void push(double); 
double pop(void); 
double top(void);
void clear(void);
int getop(char *);
int getch(void); 
void ungetch(int); 