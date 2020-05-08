#ifndef _MYSTR_H_
#define _MYSTR_H_

#define MAX_STR_LEN 256
#define MAX_WORD_LEN 16
#define MAX_WORD_COUNT 128

int str_in(char *line, size_t line_size);

void transform(char **a ,  char *buffer, size_t n, size_t m);


#endif //_MYSTR_H_