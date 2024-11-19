#include <stdio.h>

int main()
{
    int day_of_year(int year, int month, int day);
    void month_day(int year, int yearday, int *pmonth, int *pday);

    int m, d;

    month_day(1988, 60, &m, &d);
    printf("month: %d, day: %d\n", m, d);

    month_day(2024, 366, &m, &d);
    printf("month: %d, day: %d\n", m, d);

    month_day(2025, 366, &m, &d);
    printf("month: %d, day: %d\n", m, d);

    printf("%d\n", day_of_year(2024, 2, 29));
    printf("%d\n", day_of_year(2025, 2, 29));

    return 0;
}