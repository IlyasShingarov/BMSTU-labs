#include <stdio.h>

int array_input(int *a);
int odd_product(int *a);

int main(void)
{
    int a[10];
    array_input(a);

    int result = odd_product(a);

    if (result == 0)
        printf("There's no odd elements");
    else
        printf("Product of all uneven: %d", result);

    return 0;
}

int array_input(int *a)
{
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
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