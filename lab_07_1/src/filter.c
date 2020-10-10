#include "filter.h"
#include <stdlib.h>

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int error = OK;

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
        valid_count = min_p - max_p;
    if (max_p > min_p)
        valid_count = max_p - min_p;

    *pb_dst = malloc(valid_count * sizeof(int));
    *pe_dst = *pb_dst + valid_count;

    return error;
}
