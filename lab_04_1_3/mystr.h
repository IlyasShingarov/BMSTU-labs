#ifndef _MYSTR_H_
#define _MYSTR_H_

#define MAX_STR_LEN 256
#define MAX_WORD_LEN 16
#define MAX_WORD_COUNT 128

int str_in(char *line, size_t line_size);

void transform(char **a, char *buffer, size_t n, size_t m);

size_t is_divider(char character);

int line_to_array(char **words, const char *line, size_t *word_counter);

void remove_word(char **words, char *word, size_t *word_count);

void delete_element(char **words, size_t index, size_t *word_count);




#endif //_MYSTR_H_