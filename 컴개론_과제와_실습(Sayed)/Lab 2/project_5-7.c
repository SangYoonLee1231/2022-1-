#include <stdio.h>

int main(void)
{
    int a, b, c, d;

    printf("Enter four integers: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    // I couldn't solve this problem just to use only 4 if statements.

    // If the largest number is a
    if (a >= b && a >= c && a >= d) {
        printf("Largest: %d\n", a);
    }
    // If the largest number is b
    else if (b >= a && b >= c && b >= d) {
        printf("Largest: %d\n", b);
    }
    // If the largest number is c
    else if (c >= a && c >= b && c >= d) {
        printf("Largest: %d\n", c);
    }
    // If the largest number is d
    else {
        printf("Largest: %d\n", d);
    }

    // If the smallest number is a
    if (a <= b && a <= c && a <= d) {
        printf("Smallest: %d", a);
    }
    // If the smallest number is b
    else if (b <= a && b <= c && b <= d) {
        printf("Smallest: %d", b);
    }
    // If the smallest number is c
    else if (c <= a && c <= b && c <= d) {
        printf("Smallest: %d", c);
    }
    // If the smallest number is d
    else {
        printf("Smallest: %d", d);
    }
    
    return 0;
}