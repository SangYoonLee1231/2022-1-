#include <stdio.h>

int main(void)
{
    float money;

    printf("Enter an amount: ");
    scanf("%f", &money);

    money = money * 1.05;

    printf("With tax added: %.2f", money);

    return 0;
}