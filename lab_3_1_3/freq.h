#ifndef __FREQ__H__

#define __FREQ__H__

#define MAX_ROWS 10 
#define MAX_COLS 11

int array_in(int *arr, int len);
void array_out(const int *array, int len);
int find_max(int *array, int n);

void transform(int **a, int *buffer, int n, int m);
int mat_in(int **a, int *n, int *m);
void mat_out(int **matrix, int rows, int cols);

void swap(int *xp, int *yp);

#endif