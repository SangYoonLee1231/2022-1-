#include <stdio.h>

int main(void)
{
    int num, digit;
    printf("Enter a number: ");
    scanf("%d", &num);

    // Use 'if' statement and logical AND operator '&&'.

    // 0 <= num <= 9 : 1 digit
    if (0 <= num && num <= 9) {
        digit = 1;
    }
    // 10 <= num <= 99 : 2 digits
    else if (10 <= num && num <= 99) {
        digit = 2;
    }
    // 100 <= num <= 999 : 3 digits
    else if (100 <= num && num <= 999) {
        digit = 3;
    }
    // 1000 <= num <= 9999 : 4 digits
    else {
        digit = 4;
    }

    printf("The number %d has %d digits", num, digit);

    return 0;
}