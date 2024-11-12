#include <stdio.h>

int main()
{
    char *my_strncpy(char *s, const char *ct, int n);
    char *my_strncat(char *s, const char *ct, int n);
    int my_strncmp(const char *cs, const char *ct, int n);

    char s[1024] = "123456789";
    const char *t = "987654321";
    printf("%s\n", my_strncpy(s, t, 3));
    printf("%s\n", my_strncat(s, t, 3));
    printf("%d\n", my_strncmp(s, t, 3));
    printf("%d\n", my_strncmp(s, t, 4));
    return 0;
}