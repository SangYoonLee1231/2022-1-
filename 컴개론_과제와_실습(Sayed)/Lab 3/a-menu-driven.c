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
                //  Display a list of even numbers between 1 to 1000.
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
                //  Display a list of odd numbers between 1 to 1000.
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
                // Check if n is a prime number.
                int n;
                int i = 2;
                bool is_prime = true;

                printf("Enter n : ");
                scanf("%d", &n);
                
                // If n is 1, n is not a prime number.
                if (n == 1) {
                    printf("n is NOT a prime number.\n");
                    break;
                }

                // If n is 2, n is a prime number.
                if (n == 2) {
                    printf("n is a prime number.\n");
                    break;
                }

                // If n is more than 2, divide n by 2 to n and compute the remainder
                // If the remainder is 0 (just for once), n is not a prime number.
                while (i < n) {
                    if (n % i == 0) {
                        is_prime = false;
                        break;
                    }
                    i++;
                }

                if (is_prime)
                    printf("n is a prime number.\n");
                else
                    printf("n is NOT a prime number.\n");
                break;
            }

            case 4:
            {
                // Display a list of prime numbers between numbers n and m.
                int n, m;
                int i;
                bool is_prime;

                printf("Enter n : ");
                scanf("%d", &n);
                printf("Enter m : ");
                scanf("%d", &m);

                // Check if n is a prime number until n reaches to m.
                while (n <= m)
                {
                    is_prime = true;
                    i = 2;

                    if (n == 1) {
                        is_prime = false;
                    }

                    if (n == 2) {
                        printf("%d\n", n);
                        n++;
                        continue;
                    }

                    while (i < n)
                    {
                        if (n % i == 0)
                        {
                            is_prime = false;
                            break;
                        }
                        i++;
                    }

                    if (is_prime)
                        printf("%d\n", n);

                    n++;
                }
                break;
            }

            case 5:
            {
                // Display a factorial of a given number n.
                int n;
                int i = 1;
                long long fact = 1;

                printf("Enter n : ");
                scanf("%d", &n);

                while (i <= n)
                {
                    fact *= i;
                    i++;
                }

                printf("%d\n", fact);
                break;
            }

            case 6:
            {
                // Find factorial of all numbers between numbers n and m.
                int n, m;
                int i;
                long long fact;

                printf("Enter n : ");
                scanf("%d", &n);
                printf("Enter m : ");
                scanf("%d", &m);
                
                while (n <= m)
                {
                    i = 1;
                    fact = 1.0;

                    while (i <= n)
                    {
                        fact *= i;
                        i++;
                    }
                    printf("%d\n", fact);
                    n++;
                }
                break;
            }

            case 7:
            {
                // Generate the Fibonacci sequence up to a number n.
                int n;
                int n1 = 1;
                int n2 = 1;
                int n3 = 1;

                printf("Enter n : ");
                scanf("%d", &n);

                if (n <= 0) {
                    break;
                }

                printf("1 1 ");

                while(n3 < n)
                {
                    n3 = n1 + n2;  // n3 = next fibonacci number of n1 and n2.
                    n1 = n2;
                    n2 = n3;
                    if (n3 < n)
                        printf("%d ", n2);
                }

                printf("\n");

                break;
            }

            default:
                printf("Wrong number!\n");
                break;
        }

        // Check if user wants to continue program.
        // yes = 1, no = 0, other number = ask again
        do {
            printf("Do you want to continue? yes = 1, no = 0 : ");
            scanf("%d", &num);

            if (num == 0) {
                return 0;
            }
            else if (num == 1) {}
            else {
                printf("Wrong number! Try again.\n");
            }

        } while (num != 0 && num != 1);

    }

    return 0;
}