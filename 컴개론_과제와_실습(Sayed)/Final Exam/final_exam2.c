#include <stdio.h>

int main(void)
{
    int A[4], B[4];

    // Union Set
    int U[8] = {-1, -1, -1, -1, -1, -1, -1, -1};


    // Input
    for (int i = 0; i < 4; i++) {
        printf("Enter a single number (%d of 4 elements in set A) : ", i);          
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < 4; i++) {
        printf("Enter a single number (%d of 4 elements in set B) : ", i);
        scanf("%d", &B[i]);
    }


    // Function
    for (int i = 0; i < 4; i++) {
        U[i] = A[i];
    }

    int idx = 4;
    int flag = 0;

    for (int i = 0; i < 4; i++) {
        flag = 0;
        for (int j = 0; j < 4; j++) {
            if(B[i] == A[j]) {
                flag = 1;
            }            
        }
        if(flag == 0) {
            U[idx] = B[i];
            idx++;
        }
    }

    // Output : lists of Union Set
    idx = 0;

    printf("Lists of Union Set : ");

    while(U[idx] != -1)
    {
        printf("%d ", U[idx]);
        idx++;
    }

    // Ouput 2 : Find a list of prime nums in the union set
    idx = 0;

    printf("\nLists of prime nums in the union set : ");

    while(U[idx] != -1)
    {
        int n = U[idx];
        
        // Check if U[idx] is a prime number.
        int i = 2;
        int prime_flag = 1;
        
        if (n == 1)
            prime_flag = 0;

        if (n == 2)
            prime_flag = 1;

        while (i < n) {
            if (n % i == 0) {
                prime_flag = 0;
                break;
            }
            i++;
        }

        if (prime_flag == 1)
            printf("%d ", U[idx]);
        
        idx++;
    }

    return 0;
}