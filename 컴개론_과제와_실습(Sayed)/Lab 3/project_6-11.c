#include <stdio.h>

int main(void)
{
    int n;
    int i = 1;
    float fact = 1.0;
    float ans = 1.0;

    printf("Enter value of n: ");
    scanf("%d", &n);

    while(i < n)
    {
        fact *= i;
        ans += (1 / fact);
        i++;
    }

    printf("%.2f", ans);

    return 0;
}