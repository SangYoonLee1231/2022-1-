#include <stdio.h>

int main(void) 
{
    int n;
    int n1, n2;

    printf("Enter a two-digit number: ");
    scanf("%d", &n);

    n1 = n / 10;
    n2 = n % 10;

    n = n2 * 10 + n1;

    printf("The reversal is: %d", n);

    return 0;
}