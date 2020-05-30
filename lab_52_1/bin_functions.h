#ifndef _BIN_FUNCTIONS_H_
#define _BIN_FUNCTIONS_H_

#define EPS 1e-6F

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "student.h"
#include "errors.h"

void print_bin(FILE *file);
int get_struct_by_pos(FILE *file, student *students, int pos);
int put_struct_by_pos(FILE *file, student *students, int pos);
int sb_sort(FILE *file, int size);
int get_size(FILE *file, int *size);
int fb_print(FILE *file_in, FILE *file_out, int size, char *str);
int print_bin_above_avg(FILE *file, char *filename, int size);

#endif