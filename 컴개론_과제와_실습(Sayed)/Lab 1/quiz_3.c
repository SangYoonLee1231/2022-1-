#include <stdio.h>

#define PI 3.14

int main(void)
{
    float r;
    scanf("%f", &r);

    float volume;
    volume = r*r*r*PI*(4.0f/3.0f);

    printf("The volume of a sphere is %.2f", volume);

    return 0;
}