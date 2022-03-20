#include <stdio.h>

int main(void)
{
    int hour, min;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &min);

    // If time is 12:00, print 12:00 PM (not to print 0:00)
    if (hour == 12 && min == 0) {
        printf("Equivalent 12-hour time: 12:00 PM");
    }
    // If the hour of time is equal and greater than 12, it would be PM.
    // Subtract 12 from the value of hour.
    else if (hour >= 12) {
        printf("Equivalent 12-hour time: %d:%d PM", (hour - 12), min);
    }
    // if the hour of time is lower than 12, it would be AM.
    else {
        printf("Equivalent 12-hour time: %d:%d AM", hour, min);
    }

    return 0;
}