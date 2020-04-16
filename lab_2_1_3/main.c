#include <stdio.h>

#define MAX_ARRAY_SIZE 10

int n_input(void);
int arr_in(long *a, int n);
int arr_print(long *array, int n);
int shift(long *pstart, int n, int i);
int array_transform(long *a, int n);

int main(void)
{
    int error = 0;

    int n = n_input();
    
    if (n > 0)
    {   
        long array[MAX_ARRAY_SIZE * 2];
        error = arr_in(array, n);
        if (error == 0)
        {
            n = array_transform(array, n);
            error = arr_print(array, n);
        }
    }
    else
        error = 1;
    
    return error;
}


int array_transform(long *a, int n)
{
    int counter = 0;
    int fib1 = 0;
    int fib2 = 1;

    for (int i = 0; i < n; i++)
    {   
        if (a[i] % 3 == 0)
        {
            i++; counter++;
            n = shift((a + i), n, i);

            if (counter == 1)
                a[i] = 0;
            else if (counter == 2)
                a[i] = 1;
            else
            {   
                fib1 += fib2;
                a[i] = fib1;
                fib1 = fib2;
                fib2 = a[i];
            }
        }
    }

    return n;
}


int shift(long *pstart, int n, int i)
{
    for (long *pend = pstart + n - i; pend >= pstart; pend--)
    {
        *(pend + 1) = *pend;
    }

    return n + 1;
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
    if (scanf("%d", &n) != 1 || n > MAX_ARRAY_SIZE || n < 1)
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