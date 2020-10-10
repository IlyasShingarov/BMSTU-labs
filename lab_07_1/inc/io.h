#ifndef _IO_H_
#define _IO_H_

#define OK 0
#define NULL_PTR_ERR -1
#define READ_ERR -2

int count_elements(char *directory);
int read_array(char *directory, int *p_beg, int *p_end);
int write_array(char *directory, int *p_beg, int *p_end);

#endif