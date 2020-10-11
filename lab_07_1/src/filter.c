#include <stdlib.h>
#include <string.h>

#include "filter.h"
#include "errors.h"

/*
void swap(void *a, void *b, size_t size)
{
    char* tmp = (char*) malloc(size);

    memcpy(tmp, a, size);
    memcpy(a, b, size);
    memcpy(b, tmp, size);

    free(tmp);
}
*/

void fill_arr(const int *pb_src, const int *pe_src, int *pb_dst)
{
    // Ну я до конца не понимаю насколько тут нужен этот обмен,
    // но я обязательно пойму...    
    int *pb_t = pb_dst;

    const int *beg = pb_src, *end = pe_src;
    if (beg > end)
    {
        const int *temp = beg;
        beg = end;
        end = temp;
    }

    beg++;

    for (;beg <= end; beg++, pb_t++)
        *pb_t = *beg;
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int error = OK;

    if (pe_src - pb_src < 3)
        error = ELEM_COUNT_ERR;
    
    if (!error)
    {
        // Подсчёт кол-ва подходящих элементов
        const int *max_p = pb_src, *min_p = pb_src;
        for (const int *p_cur = pb_src; p_cur != pe_src; p_cur++)
        {
            if (*p_cur > *max_p)
                max_p = p_cur;
            if (*p_cur < *min_p)
                min_p = p_cur;
        }
        
        int valid_count = 0;
        if (min_p > max_p)
            valid_count = (min_p - max_p) - 1;
        if (max_p > min_p)
            valid_count = (max_p - min_p) - 1;

        if (!valid_count)
            error = ELEM_COUNT_ERR;
        
        if (!error)
        {
            // Выделение памяти
            *pb_dst = malloc(valid_count * sizeof(int));
            if (!(*pb_dst))
                error = ALLOC_ERR;
            
            if (!error)
            {
                *pe_dst = *pb_dst + valid_count;
                // Копирование подходящих элементов в вспомогательный массив
                fill_arr(max_p, min_p, *pb_dst);
            }
        }
    }

    return error;
}