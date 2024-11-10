#include <stdio.h>

int main()
{
    int strend(char *s, char *t);
    
    char *s = "hello world";
    char *t1 = "world";
    char *t2 = "e world";
    char *t3 = " hello world";
    printf("%d\n", strend(s, t1));
    printf("%d\n", strend(s, t2));
    printf("%d\n", strend(s, t3));
    
    return 0;
}