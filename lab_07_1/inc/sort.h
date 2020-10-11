#ifndef _SORT_H_
#define _SORT_H_

#include <stdlib.h>

int int_cmp(const void *a, const void *b);

void mysort(void *first, size_t number, size_t size, int (*comparator)(const void*, const void*));

#endif
