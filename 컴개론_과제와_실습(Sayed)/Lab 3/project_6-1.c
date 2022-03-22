#include <stdio.h>

int main(void)
{
    double num;
    double largest_num = 0;

    do
    {
        printf("Enter a number: ");
        scanf("%f", &num);

        if(largest_num < num)
            largest_num = num;
    } while(num > 0);

    printf("The largest number enter was %f", largest_num);

    return 0;
}