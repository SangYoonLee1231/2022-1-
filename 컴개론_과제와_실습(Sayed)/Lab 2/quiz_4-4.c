#include <stdio.h>

int main(void)
{
    int n;
    int digit, remainder;
    int ans;

    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &n);

    remainder = n % 8;
    ans += remainder;
    digit = n / 8;

    return 0;
}