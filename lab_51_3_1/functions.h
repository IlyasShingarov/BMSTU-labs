#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <stdio.h>

#define POSITIVE 1
#define NEGATIVE -1

#define NULL_PTR_ERROR -1
#define FILE_ERROR -2
#define ELEM_COUNT_ERROR -3

int process(FILE *file, int *count);

#endif