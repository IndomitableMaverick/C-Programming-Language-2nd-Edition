#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int main()
{
    printf("Test getline:\n");
    int getline(char *s, int lim);
    char s1[MAXLINE];
    printf("%d\n", getline(s1, MAXLINE));
    printf("%s\n", s1); 

    printf("Test atoi:\n");
    int atoi(const char *s);
    char *s2 = "20241104";
    printf("%d\n", atoi(s2));

    printf("Test reverse:\n");
    void reverse(char s[]);
    char s3[MAXLINE] = "hello";
    reverse(s3);
    printf("%s\n", s3);

    printf("Test itoa:\n");
    void itoa(int n, char *s);
    char s4[MAXLINE];
    itoa(-20241114, s4);
    printf("%s\n", s4);

    printf("Test strindex:\n");
    int strindex(const char *s, const char *t);
    const char *s5 = "20241115";
    const char *t = "1115";
    printf("%d\n", strindex(s5, t));

    return 0;
}