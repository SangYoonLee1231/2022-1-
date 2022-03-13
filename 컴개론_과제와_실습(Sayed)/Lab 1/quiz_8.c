#include <stdio.h>

int main(void)
{
    float loan, rate, payment;
    float monthly_rate;
    float first_pay, second_pay, third_pay;

    printf("Enter amount of loan: ");
    scanf("%f", &loan);

    printf("Enter interest rate: ");
    scanf("%f", &rate);

    printf("Enter monthly payment: ");
    scanf("%f", &payment);

    monthly_rate = rate / 12.0f / 100.0f;

    first_pay = payment;
    second_pay = first_pay * (monthly_rate + 1);
    third_pay = second_pay * (monthly_rate + 1);

    printf("Balance remaining after first payment: %.2f\n", (loan - first_pay));
    printf("Balance remaining after first payment: %.2f\n", (loan - first_pay- second_pay));
    printf("Balance remaining after first payment: %.2f\n", (loan - first_pay - second_pay- third_pay));
}