#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystr.h"

int main(void)
{
    char line[MAX_STR_LEN + 1] = { 0 };
    char buffer[MAX_WORD_COUNT][MAX_WORD_LEN + 1] = { 0 };
    char *words[MAX_WORD_COUNT] = { 0 };

    size_t word_count = 0;

    transform(words, *buffer, MAX_WORD_COUNT, MAX_WORD_LEN + 1);

    int error = 0;
    error = str_in(line, sizeof(line));

    if (!error)
        error = line_to_array(words, line, &word_count);


    if (!error)
    {
        remove_duplicates(words, &word_count);
        sort_words(words, word_count);
        line_out(words, word_count);
    }

    return error;
}