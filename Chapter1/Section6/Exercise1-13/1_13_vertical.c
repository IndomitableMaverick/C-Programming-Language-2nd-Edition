#include <stdio.h>
#define MAX_LENGTH 127
#define HISTOGRAM_CHAR '#'
/* print a histogram of the lengths of words in its input with the bars vertical */
main()
{
    int c, length, maxCount, maxLength;
    int count[MAX_LENGTH + 1];/* Assume that the maximum length of a word is 127 */

    length = maxCount = maxLength = 0;
    for(int i = 0; i <= MAX_LENGTH; ++i)
        count[i] = 0;
    do
    {
        c = getchar();
        if(c == ' ' || c == '\t' || c == '\n' || c == EOF)/* c == EOF is used to deal with a word followed by an End of File (EOF) */
        {
            if(length > 0 && length <= MAX_LENGTH)/* Words longer than MAX_LENGTH are not counted */
            {
                ++count[length];
                if(count[length] > maxCount)
                    maxCount = count[length];
                if(length > maxLength)
                    maxLength = length;
                length = 0;
            }
        }
        else
            ++length;
    }
    while(c != EOF);

    printf("Histogram:\n");
    for(int i = maxCount; i > 0; --i)
    {
        for(int j = 1; j <= maxLength; ++j)
            if(count[j] >= i)
                printf("  %c  ", HISTOGRAM_CHAR);
            else 
                printf("     ");
        printf("\n");
    }
    for(int i = 1; i <= maxLength; ++i)
        printf(" %3d ", i);
}