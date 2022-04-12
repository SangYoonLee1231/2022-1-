#include <stdio.h>
#include <string.h>
# define N 100

int main(void)
{
    // 1: Write a C program to find intersection of two sets.
    int set_A[N];
    int len_A = 0;

    int set_B[N];
    int len_B = 0;

    int set_intersect[N*2];
    int len_intersect = 0;

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
    printf("Enter the elements of Set B. Finish to enter-1'\n(only number is available) : ");
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

    // Fine intersections of A and B sets.
    for (int i = 0; i < len_A; i++)
    {
        for (int j = 0; j < len_B; j++)
        {
            if (set_A[i] == set_B[j])
            {
                set_intersect[len_intersect] = set_A[i];
                len_intersect++;
            }
        }
    }

    // Print the intersection set.
    for (int i = 0; i < len_intersect; i++) {
        printf("index : %d, value : %d\n", i, set_intersect[i]);
    }

    return 0;
}