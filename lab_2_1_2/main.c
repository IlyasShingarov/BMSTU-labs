#include <stdio.h>
#include <math.h>

int n_input(void); // Input number of elements
int arr_in(int *a, int n); // Input array elements
int is_prime(int x); // Check if number is prime
int prime_array(int *in_array, int *out_array, int n); //Form new array with primes
int arr_print(int *array, int n); // Print an array

int main(void)
{
    int error = 1;
    
    int ni = n_input(); // Arraysize variable
    if (ni > 0)
    {
        int inarr[10]; // Initial array

        if (arr_in(inarr, ni) == 0)
        {
            int outarr[10]; // Output array
            int no = prime_array(inarr, outarr, ni); // Number of elems in output array
            if (no > 0)
                error = arr_print(outarr, no);
            else
                printf("There's no prime elements");
        }
    }
    
    return error;
}


int arr_print(int *array, int n)
{
    printf("Out:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    
    return 0;
}


int prime_array(int *in_array, int *out_array, int n)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (is_prime(in_array[i]) == 0)
        {
            out_array[j] = in_array[i];
            j++;
        }    
    }

    return j;
}


int is_prime(int x)
{
    int state = 0;
    if (x > 0)
    {
        for (int i = 2; i <= sqrt(x); i++)
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