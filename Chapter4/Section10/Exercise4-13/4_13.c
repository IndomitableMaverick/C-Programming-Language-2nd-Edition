#include <stdio.h>
#include <string.h>

int main()
{
    void reverse(char s[], int from, int to);
    char s[] = "20241101";
    reverse(s, 0, strlen(s) - 1);
    printf("%s", s);
}