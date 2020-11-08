#ifndef _IO_H_
#define _IO_H_

int read_matrix(int ***matrix, int *rows, int *columns);

int** allocate_matrix(int n, int m);

void mat_out(int **matrix, int rows, int cols);

void free_matrix(int **data, int n);

#endif
