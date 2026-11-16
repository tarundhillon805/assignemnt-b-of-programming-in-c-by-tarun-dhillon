#include <stdio.h>

enum Day
{
    SUNDAY = 1,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

int main()
{
    int number;
    enum Day day;

    printf("Enter a number from 1 to 7: ");
    scanf("%d", &number);

    if (number < 1 || number > 7)
    {
        printf("Invalid number. Please enter a number between 1 and 7.\n");
        return 0;
    }

    day = (enum Day)number;

    switch (day)
    {
        case SUNDAY:
            printf("SUNDAY\n");
            break;

        case MONDAY:
            printf("MONDAY\n");
            break;

        case TUESDAY:
            printf("TUESDAY\n");
            break;

        case WEDNESDAY:
            printf("WEDNESDAY\n");
            break;

        case THURSDAY:
            printf("THURSDAY\n");
            break;

        case FRIDAY:
            printf("FRIDAY\n");
            break;

        case SATURDAY:
            printf("SATURDAY\n");
            break;
    }

    return 0;
}