#include <stdio.h>

int odd_product(int *a);

int main(void)
{
    int a[10];
    for (int i = 0; i < 10; i++)
    {
        if (scanf("%d", &a[i]) != 1)
        {
            printf("Invalid input");
            return 1;
        };
    }

    int result = odd_product(a);

    if (result == 0)
        printf("There's no odd elements => %d", result);
    else
        printf("Product of all uneven: %d", result);

    return 0;
}

int odd_product(int *a)
{
    int prod = 1;
    int counter = 0;
    for (int i = 0; i < 10; i++)
    {
        if (a[i] % 2 != 0)
        {
            prod *= a[i];
            counter++;
        }
    }
    if (counter == 0)
    {
        prod = 0;
    }
    return prod;
}