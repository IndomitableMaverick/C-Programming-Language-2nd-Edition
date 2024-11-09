#include <stdio.h>

int main()
{
    void my_strcat(char *s, char *t);

    char str1[32] = "hello ";
    char *str2 = "world";

    my_strcat(str1, str2);
    printf("%s", str1);

    return 0;
}