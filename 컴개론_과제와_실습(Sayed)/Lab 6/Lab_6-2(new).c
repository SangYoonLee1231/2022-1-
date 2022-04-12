#include <stdio.h>
#include <stdbool.h>
# define N 100

int main(void)
{
    // 2: Write a C program to find union of two sets.
    char set_A[N];
    int len_A = 0;

    char set_B[N];
    int len_B = 0;

    char set_union[N*2];
    int len_union;

    // Enter the elements of set A and B and put them into the seperate sets.
    // Set A
    int num;

    printf("Enter the elements of Set A. Finish to enter -1\n(only number is available) : ");
    while(1)
    {
        scanf("%d", &num);
        if (num != -1) {
            set_A[len_A] = num;
            len_A++;
        }
        else {
            break;
        }         
    }

    // Set B
    printf("Enter the elements of Set B. Finish to enter -1'\n(only number is available) : ");
    while(1)
    {
        scanf("%d", &num);
        if (num != -1) {
            set_B[len_B] = num;
            len_B++;
        }
        else {
            break;
        }
    }

    // Find unions of A and B sets.

    // First, copy set A to union set.
    for (int i = 0; i < len_A; i++)
    {
        bool is_there = false;
        for (int j = 0; j < len_A; j++)
        {
            if(set_A[i] == set_A[j]) {
                if (i == j) {
                    continue;
                }
                is_there = true;
                break;
            }
        }
        
        if (is_there == false) {
            set_union[i] = set_A[i];
        }     
    }

    len_union = len_A;

    // Second, check the elemnts of set B. If it's unique, add to union set.
    
    for (int i = 0; i < len_B; i++)
    {
        bool is_there = false;
        for (int j = 0; j < len_A; j++)
        {
            if(set_B[i] == set_A[j]) {
                is_there = true;
                break;
            }
        }
        
        if (is_there == false) {
            set_union[len_union] = set_B[i];
            len_union++;
        }
    }


    // Print the union set.
    for (int i = 0; i < len_union; i++) {
        printf("No. %d, value : %d\n", i+1, set_union[i]);
    }


    return 0;
}