#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int num;

    printf("");
    scanf("%d", &num);

    switch(num)
    {
        case 1:
            break;

        case 2:
            break;

        case 3:
            int n;
            int i = 2;
            bool is_prime = true;

            scanf("%d", &n);

            if(i == 1)
                printf("n is NOT a prime number.");
                break;
            if(i == 2)
                printf("n is a prime number.");
                break;
            
            while(i <= n) {
                if (n % i == 0) {
                    is_prime = false;
                    break;
                }
                i++;
            }

            if(is_prime)
                printf("n is a prime number.");
            else
                printf("n is NOT a prime number.");
            break;

        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        default:
            break;
    }

    return 0;
}