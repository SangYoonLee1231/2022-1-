#include <stdio.h>

int main(void)
{
    int dollar, leftover;
    int twenty, ten, five, one;

    printf("Enter a dollar amount: ");
    scanf("%d", &dollar);

    twenty = dollar / 20;
    leftover = dollar % 20;
    
    ten = leftover / 10;
    leftover = leftover % 10;

    five = leftover / 5;
    leftover =  leftover % 5;

    one = leftover;

    printf("$20 bills: %d\n", twenty);
    printf("$10 bills: %d\n", ten);
    printf("$5 bills: %d\n", five);
    printf("$1 bills: %d", one);

    return 0;
}