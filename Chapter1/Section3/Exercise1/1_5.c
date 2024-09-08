#include <stdio.h>
 /* print Fahrenheit−Celsius table in reverse order */
main()
{
    int fahr;
    printf("%s %s\n", "fahr", "celsius");/* print a heading above the table */
    for (fahr = 300; fahr >= 0; fahr = fahr - 20)
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
}