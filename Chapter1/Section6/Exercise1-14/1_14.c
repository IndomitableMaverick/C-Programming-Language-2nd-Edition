#include <stdio.h>
#define HISTOGRAM_CHAR '#'
#define CHAR_SET_SIZE 128/* The size of the standard ASCII character set. */
/* print a histogram of the frequencies of different characters in its input. */
main()
{
    int c;
    int count[CHAR_SET_SIZE];

    for(int i = 0; i < CHAR_SET_SIZE; ++i)
        count[i] = 0;
    while ((c = getchar()) != EOF) 
        ++count[c];
    
    printf("Histogram:\n");
    for(int i = 0; i <= CHAR_SET_SIZE; ++i)
    {
        printf("%c(%d): ", i, i);
        for(int j = 0; j < count[i]; ++j)
            printf("%c", HISTOGRAM_CHAR);
        printf("\n");
    }
}