#include <stdio.h>

int n_input(void);
int arr_in(int *a, int n);
int odd_product(int *a, int n);

int main(void)
{
    int err = 1;

    setbuf(stdout, NULL);

    int n = n_input();

    int a[10];
    if (arr_in(a, n) == 0)
    {
        if (odd_product(a, n) < 1)
            printf("There's no odd elements");
        else
            err = 0;
    }

    return err;
}


int arr_in(int *a, int n)
{   
    printf("Input array elements:\n");

    for (int i = 0; i < n; i++)
    {   
        if (scanf("%d", &a[i]) != 1)
        {
            printf("Incorrect data");
            return 1;
        }
    }

    return 0;
}


int odd_product(int *a, int n)
{
    int prod = 1;
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
        {
            prod *= a[i];
            counter++;
        }
    }
    
    if (counter > 0)
    {
        printf("Result: %d", prod);
    }

    return counter;
}


int n_input(void)
{
    int n;
    printf("Input amount of elements: ");
    if (scanf("%d", &n) != 1 || n > 10 || n < 1)
    {
        printf("Icorrect data");
        return -1;
    }

    return n;
}