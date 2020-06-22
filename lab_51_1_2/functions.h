#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <stdio.h>

#define NULL_PTR_ERROR -1
#define FILE_ERROR -2
#define ARG_COUNT_ERROR -3

int process(FILE *file, int *count);

#endif