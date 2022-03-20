#include <stdio.h>

int main(void) 
{
    int n;
    int n1, n2;

    printf("Enter a two-digit number: ");
    scanf("%d", &n);

    n1 = n / 10; // Compute the ten's digit in n
    n2 = n % 10; // Compute the unit digit in n

    // To reverse n's digits, calculate (ten's digit * 10) + first digit
    n = n2 * 10 + n1;

    printf("The reversal is: %d", n);

    return 0;
}