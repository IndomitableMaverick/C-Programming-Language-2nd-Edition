static char daytab[2][13] = { 
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} 
}; 

/* day_of_year: set day of year from month & day */ 
int day_of_year(int year, int month, int day) 
{ 
    if(year <= 0 || month <= 0 || day <= 0)
        return -1;
    int i, leap; 
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0; 
    if(month > 12 || day > daytab[leap][month])
        return -1; // -1 represents invalid input
    for (i = 1; i < month; i++) 
        day += daytab[leap][i];
    return day; 
}

/* month_day: set month, day from day of year */ 
void month_day(int year, int yearday, int *pmonth, int *pday) 
{ 
    if(year <= 0 || yearday <= 0) {
        *pmonth = -1;
        *pday = -1;
        return;
    }
    int i, leap; 
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0; 
    for (i = 1; i < 13 && yearday > daytab[leap][i]; i++) 
        yearday -= daytab[leap][i]; 
    if(i == 13) {
        *pmonth = -1; 
        *pday = -1; 
    }
    else{
        *pmonth = i; 
        *pday = yearday; 
    }
    
}