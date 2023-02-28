#include <stdio.h>
#include <stdlib.h>

struct date {
        int year;
        int month;
        int day;
    };
void printDate(struct date);
void readDate(struct date *);
struct date advanceDay(struct date);

int main()
{
    printf("Welcome to the program that calculates the next day!\n");
    printf("Please enter the date format as Day/Month/Year \nEx:1 January 1997--->01/01/1997\n");
    struct date today, tomorrow;
	readDate(&today);
	printDate(today);
	tomorrow = advanceDay(today);
	printDate(tomorrow);
    return 0;
}

void readDate(struct date *dat){

    printf("Day:");
    scanf("%d",&(*dat).day);   // scanf("%d",&dat->year);
    printf("Month:");
    scanf("%d",&(*dat).month);	// scanf("%d",&dat->month);
    printf("Year:");
    scanf("%d",&(*dat).year);	// scanf("%d",&dat->day);
}

void printDate(struct date dat){

    printf("%02d/%02d/%d\n",dat.day,dat.month,dat.year);

}

struct date advanceDay(struct date x){

struct date a = x;

    if(a.day==28 && a.month == 2 && (a.year%4 ==0))
    {
        a.day++;
    }

	else if(a.month == 1 || a.month == 3 || a.month == 5 || a.month == 7 || a.month == 8 || a.month == 10 || a.month == 12)
    {
        if(a.day < 31)
            {
                a.day++;
            }
        else
            {
            if(a.month == 12)
                {
                    a.month = 1;
                    a.day = 1;
                    a.year++;
                }
                else
                {
                a.month++;
                a.day = 1;
                }

            }
    }

    else if(a.month == 4 || a.month == 6 || a.month == 9 || a.month == 11)
    {
        if(a.day < 30)
            {
                a.day++;
            }
        else
            {
                a.day = 1;
                a.month++;
            }
    }
    return a;
}
