#include <stdio.h>

int main(void)
{
    int income;
    float tax_due;

    printf("Enter the amount of taxable income: ");
    scanf("%d", &income);

    if(income < 750) {
        tax_due = income * 0.01;
    }
    else if(income >= 750 && income <= 2250) {
        tax_due = (income - 750) * 0.02 + 7.50;
    }
    else if(income >= 2250 && income <= 3750) {
        tax_due = (income - 2250) * 0.03 + 37.50;
    }
    else if(income >= 3750 && income <= 5250) {
        tax_due = (income - 3750) * 0.04 + 82.50;
    }
    else if(income >= 5250 && income <= 7000) {
        tax_due = (income - 3750) * 0.05 + 142.50;
    }
    else {
        tax_due = (income - 7000) * 0.06 + 230.00;
    }

    printf("Your tax is %.2f", tax_due);

    return 0;
}