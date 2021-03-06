#include <stdio.h>
#include <math.h>

long n_input(void);                                        // Input number of elements
long arr_in(long *a, long n);                              // Input array elements
long is_prime(long x);                                     // Check if number is prime
long prime_array(long *in_array, long *out_array, long n); //Form new array with primes
long arr_print(long *array, long n);                       // printarr_print an array

int main(void)
{
    int error = 1;

    long ni = n_input(); // Arraysize variable
    if (ni > 0)
    {
        long inarr[10]; // Initial array

        if (arr_in(inarr, ni) == 0)
        {
            long outarr[10];                          // Output array
            long no = prime_array(inarr, outarr, ni); // Number of elems in output array
            if (no > 0)
                error = arr_print(outarr, no);
            else
                printf("There's no prime elements");
        }
    }
    
    return error;
}

long arr_print(long *array, long n)
{
    printf("Out:\n");

    for (long i = 0; i < n; i++)
        printf("%ld ", array[i]);

    return 0;
}

long prime_array(long *in_array, long *out_array, long n)
{
    long j = 0;
    for (long i = 0; i < n; i++)
    {
        if (is_prime(in_array[i]) == 0)
        {
            out_array[j] = in_array[i];
            j++;
        }
    }

    return j;
}

long is_prime(long x)
{
    long state = 0;
    if (x > 1)
    {
        for (long i = 2; i <= sqrt(x); i++)
            if (x % i == 0)
            {
                state = 1;
                i += x;
            }
    }
    else
    {
        state = 1;
    }

    return state;
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