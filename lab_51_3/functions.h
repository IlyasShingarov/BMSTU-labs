#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NULL_PTR_ERROR -1
#define FILE_ERROR -2
#define ARG_COUNT_ERROR -3
#define MODE_ERROR -4
#define NUM_COUNT_ERROR -5

#define CREATE_MODE 1
#define PRINT_MODE 2
#define SORT_MODE 3 

int create(const char *dir, size_t num_count);
int print(const char *dir);
int sort(const char *dir);

int get_number_by_pos(FILE *file, size_t pos, int *number);
int put_number_by_pos(FILE *file, size_t pos, int number);

#endif