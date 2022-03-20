#include <stdio.h>

int main(void)
{
    int speed;
    printf("Enter a wind speed: ");
    scanf("%d", &speed);

    // Use 'if' statement and logical AND operator '&&'.

    // Speed : Less than 1 => Calm
    if(speed < 1) {
        printf("Calm");
    }
    // Speed : 1-3 => Light air
    else if(speed >= 1 && speed <= 3) {
        printf("Light air");
    }
    // Speed : 4-27 => Breeze
    else if(speed >= 4 && speed <= 27) {
        printf("Breeze");
    }
    // Speed : 28-47 => Gale
    else if(speed >= 28 && speed <= 47) {
        printf("Gale");
    }
    // Speed : 48-63 => Storm
    else if(speed >= 48 && speed <= 63) {
        printf("Storm");
    }
    // Speed : Above 63 => Hurricane
    else {
        printf("Hurricane");
    }
    
    return 0;
}