#include <stdio.h>

int main(void)
{   
    printf("Size of..\n");
    printf("int: %d\nshort: %d\nlong: %d\nfloat: %d\ndouble: %d\nlong double: %d",
        sizeof(int),
        sizeof(short),
        sizeof(long),
        sizeof(float),
        sizeof(double),
        sizeof(long double)
    );

    return 0;
}