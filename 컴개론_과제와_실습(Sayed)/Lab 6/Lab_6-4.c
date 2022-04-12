#include <stdio.h>
# define N 100

int main(void)
{
    // 4: Write a C program to find smallest element in a list.

    // Enter a number in the list
    int list[N];
    int len = 0;
    int num;
    
    printf("Enter the intergers. Finish to enter -1 : ");
    while (1)
    {
        scanf("%d", &num);
        if(num != -1) {
            list[len] = num;
            len++;
        }
        else {
            break;
        }
    }

    // Find the smallest element
    int min = list[0];

    for (int i = 0; i < len; i++) {
        if (min > list[i])
            min = list[i];
    }
    
    printf("Smallest Number is %d.", min);

    return 0;
}