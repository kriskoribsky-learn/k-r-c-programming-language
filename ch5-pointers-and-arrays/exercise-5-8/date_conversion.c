#include <stdio.h>

static char daytab[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                             {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main(void)
{
    {
        int day, month, year;

        printf("Convert date to the day of the year:\n");

        printf("year: ");
        scanf("%d", &year);

        printf("month: ");
        scanf("%d", &month);

        printf("day: ");
        scanf("%d", &day);

        printf("result: %d days of year %d\n", day_of_year(year, month, day), year);
    }
    printf("\n");
    {
        int day, month, year, yearday;

        printf("Convert day of the year to date:\n");

        printf("year: ");
        scanf("%d", &year);

        printf("day of the year: ");
        scanf("%d", &yearday);

        month_day(year, yearday, &month, &day);
        printf("result: %d/%d/%d\n", day, month, year);
    }
}

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    if (month <= 0 || month > 12)
    {
        fprintf(stderr, "error: invalid month\n");
        return -1;
    }

    if (day <= 0 || day > daytab[leap][month])
    {
        fprintf(stderr, "error: invalid day\n");
        return -2;
    }

    for (i = 1; i < month; i++)
    {
        day += daytab[leap][i];
    }

    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    if (yearday <= 0 || yearday > (leap ? 366 : 365))
    {
        printf("error: invalid yearday");
        return;
    }

    for (i = 1; yearday > daytab[leap][i]; i++)
    {
        yearday -= daytab[leap][i];
    }
    *pday = yearday;
    *pmonth = i;
}
