#ifndef _IO_H_
#define _IO_H_

int count_elements(char *directory);
int read_array(char *directory, int *p_beg, int *p_end);
int write_array(char *directory, int *p_beg, int *p_end);

#endif