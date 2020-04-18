#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define SIZE_1 10
#define SIZE_2 100
#define SIZE_3 500
#define SIZE_4 1000
#define SIZE_5 10000
#define SIZE_6 100000
#define TIME_CONVERT 1000000LL


int copy_array(long *arrout, const long *arrin, const int len);
void random_array(long *array, long len);
void print_table(long repeats, long size, long time_1, long time_2, long time_3);

long elapsed_time(struct timeval time_start, struct timeval time_stop);

int process(long *array, long *end, long *result);
int process_1(long *array, int len, long *result);
int process_2(long *array, int len, long *result);

int test1(long *array, int size, long *time);
int test2(long *array, int size, long *time);
int test3(long *array, int size, long *time);

void main_test(long *array1, long *array2, long *array3 ,long size, long repeats, long *final_time_1, long *final_time_2, long *final_time_3);

int main(void)
{
    int err = 0;

    long iter_count[] = {10, 100, 500, 1000, 10000, 100000};
    long sizes[] = {SIZE_1, SIZE_2, SIZE_3, SIZE_4, SIZE_5, SIZE_6};
    
    long array1[SIZE_6] = { 0 };
    long array2[SIZE_6] = { 0 };
    long array3[SIZE_6] = { 0 };

    struct timeval time = { 0 };
    gettimeofday(&time, 0);
    srand(time.tv_sec);


    printf("|%7s|%7s|%7s|%7s|%7s|\n", "Repeats", "Size", "a[i]", "*(a+i)", "Pointer");

    for (unsigned long i = 0; i < sizeof(iter_count) / sizeof(*iter_count) && !err; i++)
        for (unsigned long j = 0; j < sizeof(sizes) / sizeof(*sizes) && !err; j++)
        {  
            long repeats = iter_count[i];
            long size = sizes[j];
            long final_time_1 = 0, final_time_2 = 0, final_time_3 = 0;

            main_test(array1, array2, array3, size, repeats, &final_time_1, &final_time_2, &final_time_3);

            print_table(repeats, size, final_time_1, final_time_2, final_time_3);
        }
                
    return err;
}

int process(long *array, long *end, long *result)
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

int process_1(long *array, int len, long *result)
{   
    *result = 0;

    long i = 0;
    long j = len - 1;

    while (i < len && j >= 0)
    {        
        while (array[i] >= 0 && i < len) 
            i++;
        while (array[j] <= 0 && j >= 0) 
            j--;
        
        if (i < len && j >= 0)
            *result += array[i] * array[j];

        i++;
        j--;
    }
    
    return *result == 0;
}

int process_2(long *array, int len, long *result)
{   
    *result = 0;

    long i = 0;
    long j = len - 1;

    while (i < len && j >= 0)
    {        
        while (*(array + i) >= 0 && i < len) 
            i++;
        while (*(array + j) <= 0 && j >= 0) 
            j--;
        
        if (i < len && j >= 0)
            *result += *(array + i) * *(array + j);
            
        i++;
        j--;
    }
    
    return *result == 0;
}

int copy_array(long *arrout, const long *arrin, const int len)
{
    for (int i = 0; i < len; i++)
        arrout[i] = arrin[i];
    
    return 0;
}

void random_array(long *array, long len)
{
    for (long i = 0; i < len; i++)
        array[i] = rand(); 
}

long elapsed_time(struct timeval time_start, struct timeval time_stop)
{
    return 
        (time_stop.tv_sec - time_start.tv_sec) * TIME_CONVERT +
        (time_stop.tv_usec - time_start.tv_usec);
}

int test1(long *array, int lenght, long *time)
{
    struct timeval time_start, time_end;
    gettimeofday(&time_start, 0);

    long result = 0;
    process_1(array, lenght, &result);

    gettimeofday(&time_end, 0);
    *time = elapsed_time(time_start, time_end);

    return 0;  
}

int test2(long *array, int lenght, long *time)
{
    struct timeval time_start, time_end;
    gettimeofday(&time_start, 0);

    long result = 0;
    process_2(array, lenght, &result);

    gettimeofday(&time_end, 0);
    *time = elapsed_time(time_start, time_end);

    return 0;
}

int test3(long *array, int size, long *time)
{
    struct timeval time_start, time_end;
    long *end = array + size;

    gettimeofday(&time_start, 0);
    
    long result = 0;
    process(array, end, &result);

    gettimeofday(&time_end, 0);
    *time = elapsed_time(time_start, time_end);

    return 0;
}

void print_table(long repeats, long size, long time_1, long time_2, long time_3)
{
    printf("|%7ld|%7ld|%7ld|%7ld|%7ld|\n", repeats, size, time_1, time_2, time_3);
}

void main_test(long *array1, long *array2, long *array3, long size, long repeats, long *final_time_1, long *final_time_2, long *final_time_3)
{
    for (long k = 0; k < repeats ; k++)
    {
        random_array(array1, size);
        copy_array(array2, array1, size);
        copy_array(array3, array1, size); 
        
        long time_1 = 0, time_2 = 0, time_3 = 0;
        
        test1(array1, size, &time_1);
        test2(array2, size, &time_2);
        test3(array3, size, &time_3);
        
        *final_time_1 += time_1;
        *final_time_2 += time_2;
        *final_time_3 += time_3;
    }
}