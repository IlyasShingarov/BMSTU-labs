#include <stdio.h>

int gcd(int a, int b);

int main(void)
{
    int a, b;

    printf("Input a:\n");
    if (scanf("%d", &a) != 1 || a < 1)
    {
        printf("Incorrect input data");
        return 1;    
    }
    
    printf("Input b:\n");
    if (scanf("%d", &b) != 1 || b < 1)
    {
        printf("Incorrect input data");
        return 1;
    }

    int common_divisor = gcd(a, b);

    printf("gcd: %d", common_divisor);

    return 0;
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