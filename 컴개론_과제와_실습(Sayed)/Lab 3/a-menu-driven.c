#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int cmd;
    int num;

    while(1)
    {
    printf("Enter Command : ");
    scanf("%d", &cmd);
    
        switch(cmd)
        {
            case 1:
            {
                int i = 1;
                while (i < 1000) {
                    if (i % 2 == 0)
                        printf("%d\n", i);
                    i++;
                }
                break;
            }

            case 2:
            {
                int i = 1;
                while (i < 1000) {
                    if (i % 2 == 1)
                        printf("%d\n", i);
                    i++;
                }
                break;
            }

            case 3:
            {
                int n;
                int i = 2;
                bool is_prime = true;

                printf("Enter n : ");
                scanf("%d", &n);

                if(n == 1) {
                    printf("n is NOT a prime number.\n");
                    break;
                }
                if(n == 2) {
                    printf("n is a prime number.\n");
                    break;
                }
                while(i < n) {
                    if (n % i == 0) {
                        is_prime = false;
                        break;
                    }
                    i++;
                }

                if(is_prime)
                    printf("n is a prime number.\n");
                else
                    printf("n is NOT a prime number.\n");
                break;
            }

            case 4:
            {
                int n, m;
                int i;
                bool is_prime;

                printf("Enter n : ");
                scanf("%d", &n);
                printf("Enter m : ");
                scanf("%d", &m);

                while (n <= m)
                {
                    is_prime = true;
                    i = 2;

                    if(n == 1) {
                        n++;
                        break;
                    }

                    if(n == 2) {
                        n++;
                        break;
                    }

                    while(i < n)
                    {
                        if (n % i == 0)
                        {
                            is_prime = false;
                            break;
                        }
                        i++;
                    }

                    if(is_prime)
                        printf("%d\n", n);

                    n++;
                }
                break;
            }

            case 5:
            {
                int n;
                int i = 1;
                float fact = 1.0;

                printf("Enter n : ");
                scanf("%d", &n);

                while(i <= n)
                {
                    fact *= i;
                    i++;
                }

                printf("%.2f", fact);
                break;
            }

            case 6:
            {
                int n, m;
                int i;
                float fact;

                printf("Enter n : ");
                scanf("%d", &n);
                printf("Enter m : ");
                scanf("%d", &m);
                
                while (n <= m)
                {
                    i = 1;
                    fact = 1.0;

                    while(i <= n)
                    {
                        fact *= i;
                        i++;
                    }
                    printf("%.2f\n", fact);
                    n++;
                }
                break;
            }

            case 7:
            {
                int n;
                int n1 = 1;
                int n2 = 1;
                int n3;
                int i = 3;

                printf("Enter n : ");
                scanf("%d", &n);
                
                if (n == 1)
                    printf("1");
                    break;
                if (n == 2)
                    printf("1");
                    break;

                while(i <= n)
                {
                    n3 = n1 + n2;
                    n1 = n2;
                    n2 = n3;
                    i++;
                }

                printf("%d", n2);

                break;
            }

            default:
                printf("Wrong number!\n");
                break;
        }

        printf("Do you want to continue? yes = 1, no = 0 : ");
        scanf("%d", &num);
        if (num == 0)
            break;
    }

    return 0;
}