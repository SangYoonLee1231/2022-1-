#include <stdio.h>

int main(void)
{
    int income;
    float tax_due;

    printf("Enter the amount of taxable income: ");
    scanf("%d", &income);

    // Use 'if' statement and logical AND operator '&&'.

    // Income = not over $750 => 1% of income
    if(income < 750) {
        tax_due = income * 0.01;
    }
    // Income = $750-$2250 => 2% of (income - $750) + $7.50
    else if(income >= 750 && income <= 2250) {
        tax_due = (income - 750) * 0.02 + 7.50;
    }
    // Income = $2250-$3750 => 3% of (income - $2250) + $37.50
    else if(income >= 2250 && income <= 3750) {
        tax_due = (income - 2250) * 0.03 + 37.50;
    }
    // Income = $3750-$5250 => 4% of (income - $3750) + $82.50
    else if(income >= 3750 && income <= 5250) {
        tax_due = (income - 3750) * 0.04 + 82.50;
    }
    // Income = $5250-$7000 => 5% of (income - $3750) + $142.50
    else if(income >= 5250 && income <= 7000) {
        tax_due = (income - 3750) * 0.05 + 142.50;
    }
    // Income = Over $7000 => 6% of (income - $7000) + $230.00
    else {
        tax_due = (income - 7000) * 0.06 + 230.00;
    }

    printf("Your tax is %.2f", tax_due);

    return 0;
}