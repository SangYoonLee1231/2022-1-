#include <stdio.h>

int main(void)
{
    float x, ans;

    printf("Write a number : ");
    scanf("%f", &x);

    ans = 3*x*x*x*x*x + 2*x*x*x*x - 5*x*x*x - x*x + 7*x - 6;

    printf("Answer : %.2f", ans);

    return 0;
}