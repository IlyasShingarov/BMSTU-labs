#ifndef _BIN_FUNCTIONS_H_
#define _BIN_FUNCTIONS_H_

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "student.h"
#include "errors.h"

void print_bin(FILE *file);
int get_struct_by_pos(FILE *file, student *students, int pos);
int put_struct_by_pos(FILE *file, student *students, int pos);
int sort_structs(FILE *file, int size);
int get_file_size(FILE *file, int *size);
int put_where_surname_starts_with(FILE *fin, FILE *fout, int size_in, const char *str);
int set_only_lower_avg(FILE *file, const char *filename, int size);

#endif