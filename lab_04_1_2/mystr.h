#ifndef _MYSTR_H_
#define _MYSTR_H_

#define MAX_STR_LEN 256
#define MAX_WORD_LEN 16
#define MAX_WORD_COUNT 128

int str_in(char *line, size_t line_size);

void transform(char **a, char *buffer, size_t n, size_t m);

size_t is_divider(char character);

int line_to_array(char **words, const char *line, size_t *word_counter);

size_t my_strcmp(char *word1, char *word2);

size_t delete_word(size_t index, char **words, size_t word_counter);

void line_out(char **words, size_t word_count);

void remove_duplicates(char **words, size_t *word_count);

void sort_words(char **words, size_t word_count);

void swap(char **words, size_t ind1, size_t ind2);


#endif //_MYSTR_H_