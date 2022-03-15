#include <stdio.h>

int main(void)
{
    int speed;
    printf("Enter a wind speed: ");
    scanf("%d", &speed);

    if(speed < 1) {
        printf("Calm");
    }
    else if(speed >= 1 && speed <= 3)
    {
        printf("Light air");
    }
    else if(speed >= 4 && speed <= 27)
    {
        printf("Breeze");
    }
    else if(speed >= 28 && speed <= 47) {
        printf("Gale");
    }
    else if(speed >= 48 && speed <= 63) {
        printf("Storm");
    }
    else {
        printf("Hurricane");
    }
    
    return 0;
}