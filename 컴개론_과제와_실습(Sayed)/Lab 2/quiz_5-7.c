#include <stdio.h>

int main(void)
{
    int a, b, c, d;

    printf("Enter four integers ");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    if (a >= b && a >= c && a >= d) {
        printf("Largest: %d\n", a);
    }
    else if (b >= a && b >= c && b >= d) {
        printf("Largest: %d\n", b);
    }
    else if (c >= a && c >= b && c >= d) {
        printf("Largest: %d\n", c);
    }
    else {
        printf("Largest: %d\n", d);
    }


    if (a <= b && a <= c && a <= d) {
        printf("Smallest: %d", a);
    }
    else if (b <= a && b <= c && b <= d) {
        printf("Smallest: %d", b);
    }
    else if (c <= a && c <= b && c <= d) {
        printf("Smallest: %d", c);
    }
    else {
        printf("Smallest: %d", d);
    }
    
    return 0;
}