#include <stdio.h>

int main(void)
{
    // num : 분자, denom : 분모
    int num, denom, a, b;
    int temp, gcd;

    printf("Enter a fraction: ");
    scanf("%d/%d", &num, &denom);

    a = num;
    b = denom;

    while(b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    gcd = a;

    num = num / gcd;
    denom = denom / gcd;

    printf("In lowest terms: %d/%d", num, denom);

    return 0;
}