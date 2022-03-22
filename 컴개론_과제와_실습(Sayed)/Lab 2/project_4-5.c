#include <stdio.h>

int main(void)
{
  int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11;
  int first_sum, second_sum, total, check_digit;

  printf("Enter the first 11 digits of a UPC: ");
  scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9, &n10, &n11);

  // Add the first, third, fifth, seventh, ninth, and eleventh digits to compute the first sum.
  first_sum = n1 + n3 + n5 + n7 + n9 + n11;
  // Add the second, fourth, sixth, eighth, and tenth digits to compute the second sum
  second_sum = n2 + n4 + n6 + n8 + n10;

  // Multiply the first sum by 3 and add it to the second sum.
  total = (first_sum * 3) + second_sum;
  // Subtract 1 from the total and compute the remainder (when the adjudted total is divided by ten).
  // Then, subtract the remainder from 9.
  check_digit = 9 - ((total - 1) % 10);

  printf("Check digit: %d", check_digit);

  return 0;
}
