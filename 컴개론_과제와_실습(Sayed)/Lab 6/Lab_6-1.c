#include <stdio.h>
#include <string.h>
# define N 100

int main(void)
{
    // 1: Write a C program to find intersection of two sets.
    char set_A[N];
    int len_A = 0;

    char set_B[N];
    int len_B = 0;

    char set_intersect[N*2];
    int len_intersect = 0;

    // Enter the elements of set A and B and put them into the seperate sets.
    // Set A
    char ch;

    printf("Enter the elements of Set A. Finish to enter '.'\n(only 1 letter is available) : ");
    while(1)
    {
        ch = getchar();
        if (ch != '.') {
            set_A[len_A] = ch;
            len_A++;

            /*
            if (48 <= ch <= 57) {
                set_A[len_A] = (int)ch;
            }  // ASCII Code
            */
        }
        else {
            break;
        }         
    }

    // Set B
    printf("Enter the elements of Set B. Finish to enter '.'\n(only 1 letter is available) : ");
    while(1)
    {
        ch = getchar();
        if (ch != '.') {
            set_B[len_B] = ch;
            len_B++;
            /*
            if (48 <= ch <= 57) {
                set_B[len_B] = (int)ch;
            }  // ASCII Code
            */
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
            if (strcmp(set_A[i], set_B[j]) != 0)
            {
                set_intersect[len_intersect] = set_A[i];
                len_intersect++;
            }
        }
    }

    // Print the intersection set.
    for (int i = 0; i < len_intersect; i++) {
        //printf("index : %d, value : %c\n", i, set_intersect[i]);
        putchar(set_intersect[i]);
    }

    return 0;
}