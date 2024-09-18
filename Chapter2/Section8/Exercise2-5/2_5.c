#include <stdio.h>

int any(char s1[], char s2[]);

main()
{
    printf("%d\n", any("aabbcaabaacba", "aacb"));
    printf("%d\n", any("aaabaaaaab", "aaaab"));
    printf("%d\n", any("aabaabaabaac", "aabaac"));
}

/* returns the first location in a string s1 where any character from the string s2 occurs, or -1 if s1 contains no characters from s2. */
int any(char s1[], char s2[])
{
    int len1, len2;
    len1 = len2 = 0;
    while(s1[len1++] != '\0')
        ;
    while(s2[len2++] != '\0')
        ;
    --len1;
    --len2;
    int index1, index2, next[len2];
    index1 = next[0] = 0;
    index2 = 1;
    while(index2 < len2)
    {
        if(s2[index1] == s2[index2])
        {
            next[index2] = next[index2 - 1] + 1;
            ++index1;
        }
        else
        {
            next[index2] = 0;
            index1 = 0;
        }
        ++index2;
    }
    while(--index2 > 0)
        next[index2] = next[index2 - 1];
    while(index2 < len2)
    {
        while(next[index2] != 0 && s2[next[index2]] == s2[index2])
            next[index2] = next[next[index2]];
        ++index2;
    }

    index1 = index2 = 0;
    while(index1 < len1)
        if(s1[index1] == s2[index2])
        {
            if(++index2 == len2)
                return index1 - len2 + 1;
            ++index1;
        }
        else
            if(index2 == 0)
                ++index1;
            else
                index2 = next[index2];
    return -1;
}