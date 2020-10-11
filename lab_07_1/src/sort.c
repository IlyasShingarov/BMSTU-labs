#include <string.h>
#include <stdio.h>

#include "sort.h"

int int_cmp(const void *a, const void *b)
{
    return (*(int*)a < *(int*)b) ? -1 : (*(int*)a > *(int*)b);
}

void mysort(void *first, size_t number, size_t size, int (*comparator) (const void*, const void*))
{
    char *p_end = (char*)first + number * size;
    char cur_elem[size];

    for (char *p_cur = first; p_cur != p_end; p_cur = p_cur + size)
    {
        memcpy(cur_elem, p_cur, size);
        char *left = first, *right = p_cur - size;

        while (left <= right)
        {
            // Наверняка есть какой-то более изящный подход, но не сегодня, не сейчас.
            int mid_i = (right - left) / size;
            char *mid = left + size * (mid_i / 2);
            if (comparator(cur_elem, mid) < 0)
                right = mid - size;
            else
                left = mid + size;
        }

        for (char *cur = p_cur; cur >= left; cur = cur - size)
            memmove(cur, cur - size, size);

        memcpy(left, cur_elem, size);
    }
}