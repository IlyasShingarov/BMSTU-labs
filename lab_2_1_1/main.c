#include <stdio.h>

#define MAX_ARRAY_SIZE 10

int n_input(void);
int arr_in(int *a, int n);
int odd_product(int *a, int n);

int main(void)
{
    int err = 1;

    setbuf(stdout, NULL);

    int n = n_input();

    int a[MAX_ARRAY_SIZE];
    if (arr_in(a, n) == 0)
    {
        int result = odd_product(a, n);
        if (!result)
            printf("There's no odd elements");
        else
        {
            printf("Result: %d", result);
            err = 0;
        }
    }

    return err;
}


int arr_in(int *a, int n)
{   
    int error = 0;

    printf("Input array elements:\n");

    for (int i = 0; i < n && !error; i++)
    {   
        if (scanf("%d", &a[i]) != 1)
        {
            printf("Incorrect data");
            error = 1;
        }
    }

    return error;
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

    if (counter == 0)
        prod = 0;

    return prod;
}


int n_input(void)
{
    int n;
    printf("Input amount of elements: ");
    if (scanf("%d", &n) != 1 || n > MAX_ARRAY_SIZE || n < 1)
    {
        printf("Icorrect data");
        n = -1;
    }

    return n;
}