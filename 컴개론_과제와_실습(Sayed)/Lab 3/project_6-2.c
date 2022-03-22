#include <stdio.h>

int main(void)
{
    int a, b, temp;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    while(b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }

    printf("Greatest common divisor: %d", &a);

    return 0;
}