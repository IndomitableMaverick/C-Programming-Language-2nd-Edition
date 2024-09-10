#include <stdio.h>
#define MAX_LENGTH 127
#define HISTOGRAM_CHAR '#'
/* print a histogram of the lengths of words in its input with the bars horizontal */
main()
{
    int c, length, maxLength;
    int count[MAX_LENGTH + 1];/* Assume that the maximum length of a word is 127 */

    length = maxLength = 0;
    for(int i = 0; i <= MAX_LENGTH; ++i)
        count[i] = 0;
    do
    {
        c = getchar();
        if(c == ' ' || c == '\t' || c == '\n' || c == EOF)/* c == EOF is used to deal with a word followed by an End of File (EOF) */
        {
            if(length <= MAX_LENGTH)/* Words longer than MAX_LENGTH are not counted */
            {
                ++count[length];
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
    for(int i = 1; i <= maxLength; ++i)
    {
        printf("%3d: ", i);
        for(int j = 0; j < count[i]; ++j)
            printf("%c", HISTOGRAM_CHAR);
        printf("\n");
    }
}