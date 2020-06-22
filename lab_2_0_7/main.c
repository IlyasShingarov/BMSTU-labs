#include <stdio.h>

#define ARRAY_SIZE 100000

int n_input(void);
int arr_in(long *a, int n);
void arr_print(long *array, int n);
void bubble_sort(long *a, int n);
void swap(long *xp, long *yp);

int main(void)
{
    int error = 0;

    int n = n_input();

    if (n > 0)
    {   
        long array[ARRAY_SIZE];
        error = arr_in(array, n);
        if (error == 0)
        {
            bubble_sort(array, n);
            arr_print(array, n);
        }
    }
    else
        error = 1;

    return error;
}


void swap(long *xp, long *yp)
{
    long temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}


void bubble_sort(long *a, int n)
{ 
    for (int i = 0; i < n - 1; i++)       
        for (int j = 0; j < n - i - 1; j++)  
            if (a[j] > a[j + 1]) 
                swap(a + j, a + j + 1); 
} 


void arr_print(long *array, int n)
{
    printf("\nOut:\n");

    for (int i = 0; i < n; i++)
        printf("%ld ", array[i]);
}


int arr_in(long *a, int n)
{
    int error = 0;
    printf("Input array elements:\n");

    for (int i = 0; i < n && !error; i++)
    {
        if (scanf("%ld", &a[i]) != 1)
        {
            printf("Incorrect data");
            error = 1;
        }
    }

    return error;
}


int n_input(void)
{
    int n;
    printf("Input amount of elements: ");
    if (scanf("%d", &n) != 1 || n > ARRAY_SIZE || n < 1)
    {
        printf("Icorrect data");
        n = -1;
    }

    return n;
}