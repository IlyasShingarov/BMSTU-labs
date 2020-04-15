#ifndef __FREQ__H__

#define __FREQ__H__

#define MAX_ROWS 10 
#define MAX_COLS 11

int array_in(int *arr, int len);
int array_out(const int *array, int len);
int find_max(int *array, int n);

int mat_size_in(int *rows, int *columns);
int mat_in(int (*mat)[MAX_COLS], int rows, int columns);
int mat_out(int (*matrix)[MAX_COLS], int rows, int cols);

void swap(int *xp, int *yp);



#endif