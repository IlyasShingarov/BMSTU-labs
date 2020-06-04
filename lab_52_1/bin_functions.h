#ifndef _BIN_FUNCTIONS_H_
#define _BIN_FUNCTIONS_H_

#define EPS 1e-6F

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include "student.h"
#include "errors.h"

void print_bin(FILE *file);
int get_struct_by_pos(FILE *file, student *students, int pos);
int put_struct_by_pos(FILE *file, student *students, int pos);
void sb_sort(FILE *file, int size);
int cmp_by_pos(FILE *file , int pos1, int pos2);
int exchange(FILE *file, int pos1, int pos2);
int get_size(FILE *file, int *size);
int fb_print(FILE *file_in, FILE *file_out, int size, const char *str);
int print_bin_above_avg(FILE *file, const char *filename, int size);

#endif