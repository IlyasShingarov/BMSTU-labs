#include <stdio.h>

int gcd(int a, int b);

int main(void)
{
    int a, b, error = 0;

    printf("Input a, b:\n");
    if (scanf("%d%d", &a, &b) != 2 || a < 1 || b < 1)
    {
        printf("Incorrect input data");
        error = 1;    
    }

    if (error == 0)
    {
        int common_divisor = gcd(a, b);
        printf("gcd: %d", common_divisor);
    }

    return error;
}

int gcd(int a, int b)
{
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }

    return a;
}