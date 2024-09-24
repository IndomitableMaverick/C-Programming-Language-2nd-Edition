#include <stdio.h>
#include <ctype.h>

void expand(char s1[], char s2[]);

main()
{
    char s1[] = "-a-c-eA-Z-0-9-";
    char s2[1024];
    expand(s1, s2);
    printf("%s", s2);
    return 0;
}

/* expands shorthand notations like a-z in the string s1 into the equivalent complete list abc...xyz in s2. 
Allow for letters of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. 
Arrange that a leading or trailing - is taken literally. */
void expand(char s1[], char s2[])
{
    int index1, index2;
    index1 = index2 = 0;
    while(s1[index1] != '\0')
    {
        char c = s1[index1];
        if(s1[index1 + 1] == '-' && 
        (isdigit(s1[index1]) && isdigit(s1[index1 + 2]) || 
        islower(s1[index1]) && islower(s1[index1 + 2]) || 
        isupper(s1[index1]) && isupper(s1[index1 + 2])) && 
        s1[index1] <= s1[index1 + 2])
        {
            for(; c < s1[index1 + 2]; ++c)
                s2[index2++] = c;
            index1 += 2;
        }
        else
        {
            s2[index2++] = c;
            ++index1;
        }
    }
}