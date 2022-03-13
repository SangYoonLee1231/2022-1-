#include <stdio.h>

#define PI 3.14

int main(void)
{
    float r;
    r = 10.0;

    float volume;
    volume = r*r*r*PI*(4.0f/3.0f);

    printf("The volume of a sphere with a 10-meter radius is %.2f", volume);

    return 0;
}