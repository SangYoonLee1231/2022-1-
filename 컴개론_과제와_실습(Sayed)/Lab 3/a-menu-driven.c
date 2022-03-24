#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int num;

    printf("");
    scanf("%d", &num);

    while(1)
    {

    
        switch(num)
        {
            case 1:
                int i = 1;
                while (i < 1000) {
                    if (i % 2 == 0)
                        printf("%d\n", i);
                    i++;
                }
                break;


            case 2:
                int i = 1;
                while (i < 1000) {
                    if (i % 2 == 1)
                        printf("%d\n", i);
                    i++;
                }
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
                int n, m;
                int i;
                scanf("%d %d", &n, &m);

                while (n <= m)
                {
                    if(n == 1)
                    {
                        printf("n is NOT a prime number.");
                        n++;
                        continue;
                    }

                    if(n == 2)
                    {
                        printf("%d\n", n);
                        n++;
                        continue;
                    }

                    i = 2;
                    while(i <= n)
                    {
                        if (n % i == 0)
                        {
                            n++;
                            break;
                        }
                        i++;
                    }
                    printf("%d\n", n);
                    n++;
                }
                break;


            case 5:
                int n;
                int i = 1;
                float fact = 1.0;

                print("");
                scanf("%d", &n);

                while(i <= n)
                {
                    fact *= i;
                    i++;
                }

                print("%.2f", fact);
                break;


            case 6:
                int n, m;
                int i;
                float fact;

                print("");
                scanf("%d", &n);
                
                while (n <= m)
                {
                    i = 1;
                    fact = 1.0;

                    while(i <= n)
                    {
                        fact *= i;
                        i++;
                    }
                    print("%.2f\n", fact);
                    n++;
                }
                break;


            case 7:
                int n;
                int i = 1;

                print("");
                scanf("%d", &n);
                break;


            default:
                print("Wrong number!");
                break;
        }

        scanf("");
        if ( == 0)
            break;
    }

    return 0;
}