#include <stdio.h>
/* Сначала размер массива -- макс 10
Элементы -- целочисл
*/

int arr_in(int *a, int n);
int odd_product(int *a, int n);

int main(void)
{
    int err = 0;

    setbuf(stdout, NULL);

    int n;
    printf("Input amount of elements: ");
    if (scanf("%d", &n) != 1 || n > 10 || n < 1)
    {
        printf("Icorrect data");
        return 1;
    }

    int a[n];
    if (arr_in(a, n) == 0)
    {
        if (odd_product(a, n) == 0)
        {
            printf("There's no odd elements");
            err = 1;
        }
    }

    return err;
}


int arr_in(int *a, int n)
{   
    printf("Input array elements:\n");

    for (int i = 1; i <= n; i++)
    {   
        if (scanf("%d", &*(a + i)) != 1)
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
    for (int i = 0; i <= n; i++)
    {
        if (a[i] % 2 != 0)
        {
            prod *= a[i];
            counter++;
        }
    }
    
    if (counter > 0)
        printf("Result: %d", prod);

    return counter;
}