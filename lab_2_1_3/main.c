#include <stdio.h>

long n_input(void);
long arr_in(long *a, long n);
long arr_print(long *array, long n);
int shift(long *pstart, long n);
int array_transform(long *a, long n);

int main(void)
{
    int error = 0;
    long array[20];

    int n = n_input();
    
    if (n > 0)
    {
        error = arr_in(array, n);
        if (error == 0)
        {
            n = array_transform(array, n);
            arr_print(array, n);
        }
    }

    return error;
}


int array_transform(long *a, long n)
{
    int counter = 0;
    int fib1 = 0;
    int fib2 = 1;

    for (int i = 0; i < n; i++)
    {   
        if (a[i] %  3 == 0)
        {
            i++; counter++;
            n = shift((a + i), n);
            if (counter == 1)
                a[i] = fib1;
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


int shift(long *pstart, long n)
{
    long* pend = pstart + n;

    for (; pend >= pstart; pend--)
    {
        *(pend + 1) = *pend;
    }

    return n + 1;
}

long arr_in(long *a, long n)
{
    printf("Input array elements:\n");

    for (long i = 0; i < n; i++)
    {
        if (scanf("%ld", &a[i]) != 1)
        {
            printf("Incorrect data");
            return 1;
        }
    }

    return 0;
}


long n_input(void)
{
    long n;
    printf("Input amount of elements: ");
    if (scanf("%ld", &n) != 1 || n > 10 || n < 1)
    {
        printf("Icorrect data");
        return -1;
    }

    return n;
}


long arr_print(long *array, long n)
{
    printf("\nOut:\n");

    for (long i = 0; i < n; i++)
        printf("%ld ", array[i]);

    return 0;
}