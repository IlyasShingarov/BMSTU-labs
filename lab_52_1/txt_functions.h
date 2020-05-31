#ifndef _TXT_FUNCTIONS_H_
#define _TXT_FUNCTIONS_H_

#define EPS 1e-6F

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "student.h"
#include "errors.h"

int st_add(FILE *file, student *student);
int st_readall(FILE *file, student *students, int max_size);
void st_sort(student **st_arr, int size);
int print_above_avg(FILE *file_out, student *students, int size);
int ft_print(FILE *file, student *students, int size, char *field);

#endif