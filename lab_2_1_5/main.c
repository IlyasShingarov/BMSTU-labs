#include <stdio.h>

int array_in(long *array, long **end);
int process_array(long *array, long *end, long *result);
void print_result(long result);

int main(void)
{
    int err = 0;

    long array[10] = { 0 };
    long *end = 0;
    long result = 0;

    if (!err)
        err = array_in(array, &end);
    
    if (!err)
        err = process_array(array, end, &result);
    
    if (!err)
        print_result(result);   
    else
        printf("error\n");
    
    return err;
}

int array_in(long *array, long **end)
{   
    int err = 0;

    int length;
    printf("Input array length: ");

    if (scanf("%d", &length) != 1 || length <= 0 || length > 10)
        err = -1;
    
    if (!err)
        printf("Input array elements: ");
    
    *end = array + length;
    
    for (long *i = array; i != *end && !err; i++)
    {
        if (scanf("%ld", i) != 1)
            err = -1; 
    }
    
    return err;
}

int process_array(long *array, long *end, long *result)
{   
    *result = 0;

    long *i = array;
    long *j = end - 1;

    while (i < end && j > array)
    {        
        while (*i >= 0 && i < end) 
            i++;
        while (*j <= 0 && j > array) 
            j--;
        
        if (i < end && j > array)
            *result += (*i) * (*j);
        
        i++;
        j--;
    }
    
    return *result == 0;
}

void print_result(long result)
{
    printf("Result is %ld\n", result);
}
