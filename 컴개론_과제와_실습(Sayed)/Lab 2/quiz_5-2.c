#include <stdio.h>

int main(void)
{
    int hour, min;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &min);

    if (hour == 12 && min == 0) {
        printf("Equivalent 12-hour time: 12:00 PM");
    }
    else if (hour >= 12) {
        printf("Equivalent 12-hour time: %d:%d PM", (hour - 12), min);
    }
    else {
        printf("Equivalent 12-hour time: %d:%d AM", hour, min);
    }

    return 0;
}