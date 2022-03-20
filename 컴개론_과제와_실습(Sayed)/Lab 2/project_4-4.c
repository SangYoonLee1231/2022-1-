#include <stdio.h>

int main(void)
{
    int n;
    int num = 1;
    int digit, remainder;
    int ans = 0;

    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &n);
    
    while(n != 0) { 
        remainder = n % 8;  // First, divide the 'n' by 8.
        ans += num * remainder;  //  Then, add it to the answer, considering the position of its digit.
        num *= 10;
        n = n / 8;  // Lastly, divide the original 'n' by 8 and repeat all the process until the 'n' reaches to 0.
    }

    printf("In octal, your number is : %05d", ans);

    return 0;
}