#include <stdio.h>

int input_array(long long *array, long long **end);
int process_array(long long *array, long long *end, long long *result);
void print_result(long long result);

int main(void)
{
    int err = 0;

    long long array[10] = { 0 };
    long long *end = 0;
    long long result = 0;

    if (!err)
        err = input_array(array, &end);
    
    if (!err)
        err = process_array(array, end, &result);
    
    if (!err)
        print_result(result);
    else
        printf("error\n");
    
    return err;
}

int input_array(long long *array, long long **end)
{
    if (!array || !end)
        return -2;
    
    int err = -1;

    int lenght = 0;

    printf("Input array length: ");

    if (scanf("%d", &lenght) != 1 || lenght <= 0 || lenght > 10)
        err = -1;
    
    if (!err)
        printf("Input array elements: ");
    
    *end = array + lenght;
    
    for (long long *i = array; i != *end && !err; i++)
    {
        if (scanf("%lld", i) != 1)
            err = -1; 
    }
    
    return err;
}

int process_array(long long *array, long long *end, long long *result)
{
    if (!array || !end || !result)
        return -2;
    
    *result = 0;

    long long *i = array;
    long long *j = end - 1;

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

void print_result(long long result)
{
    printf("Result is %lld\n", result);
}
