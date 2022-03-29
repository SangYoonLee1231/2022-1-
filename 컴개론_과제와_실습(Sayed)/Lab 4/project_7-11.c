#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int vowel = 0;
    char ch;
    char first_init;
    bool is_last_name = false;

    printf("Enter a first and last name : ");
    first_init = getchar();

    while (ch != '\n') {
        ch = getchar();
        
        if (ch == ' ')
            is_last_name = true;

        if (is_last_name)
            printf("%c", ch);
    }

    printf(", %c.", first_init);
    return 0;
}