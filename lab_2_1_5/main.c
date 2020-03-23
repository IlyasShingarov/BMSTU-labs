#include <stdio.h>

int n_input(void);
int arr_in(long *a, int n);
int arr_print(long *array, int n);

int main(void)
{
    int error = 0;

    return error;
}

int arr_in(long *a, int n)
{
    printf("Input array elements:\n");

    for (int i = 0; i < n; i++)
    {
        if (scanf("%ld", &a[i]) != 1)
        {
            printf("Incorrect data");
            return 1;
        }
    }

    return 0;
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

int arr_print(long *array, int n)
{
    printf("\nOut:\n");

    for (int i = 0; i < n; i++)
        printf("%ld ", array[i]);

    return 0;
}

