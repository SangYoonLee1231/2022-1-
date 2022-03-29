#include <stdio.h>

int main(void)
{
    int vowel = 0;
    char ch;

    printf("Enter a sentence : ");
    do {
        ch = getchar();
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch =='o' || ch == 'u')
            vowel++;
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch =='O' || ch == 'U')
            vowel++;
    } while (ch != '\n');

    printf("Your sentence contains %d vowels.", vowel);
    return 0;
}