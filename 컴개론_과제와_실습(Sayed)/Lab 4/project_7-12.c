#include <stdio.h>

int main(void)
{
    float ans;
    char ch;
    char exp;

    printf("Enter an expression: ");
    
    ch = getchar;
    ans = (float)ch;

    while (ch != '\n') {
        ch = getchar();

        if (ch == '+' || ch == '-' || ch == '*' || ch =='/')
            exp = ch;
        else {
            if (exp == '+')
                ans += ch;
            else if (exp == '-')
                ans -= ch;
            else if (exp == '*')
                ans *= ch;
            else if (exp == '/')
                ans /= ch;
            else {}
        }
    }

    printf("Value of expression %f", ans);

    return 0;
}