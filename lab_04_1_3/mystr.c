#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystr.h"

int str_in(char *line, size_t line_size)
{
    int chr;
    size_t i = 0;

    while ((chr = getchar()) != '\n' && chr != EOF)
    {
        if (i < line_size - 1)
            *(line + i) = chr;
        
        i++;
    }
    
    if (i > line_size)
        *(line + i) = '\0';
    
    return i == 0 || i >= line_size;
}

void transform(char **a, char *buffer, size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
        *(a + i) = buffer + i * m;
}

size_t is_divider(char character)
{
    char dividers[] = { ' ', ',', ';', ':', '-', '.', '!', '?' };
    size_t result = 0;

    for (size_t i = 0; i < sizeof(dividers) && result == 0; i++)
        result = character == *(dividers + i);
    
    return result;
}

int line_to_array(char **words, const char *line, size_t *word_counter)
{
    int error = 0;
    size_t word_length = 0; *word_counter = 0;

    while (*line && !error)
    {
        if (word_length)
        {
            words[*word_counter][word_length] = '\0';
            (*word_counter)++;
            error = *word_counter > MAX_WORD_COUNT;
        }

        word_length = 0;

        while (is_divider(*line) && *line && !error)
            line++;

        while (!is_divider(*line) && *line && !error)
        {
            words[*word_counter][word_length] = *line;
            line++; word_length++;
            error = word_length > MAX_WORD_LEN;
        }
    }

    if (!error && word_length)
    {
        words[*word_counter][word_length] = '\0';
        (*word_counter)++;
        error = *word_counter > MAX_WORD_COUNT;
    }

    return error;
}

void remove_word(char **words, char *word, size_t *word_count)
{
    for (size_t i = 0; i < *word_count; i++)
        if (!strncmp(words[i], word, MAX_WORD_LEN))
        {
            delete_element(words, i, word_count);
            i--;
        }
}

void delete_element(char **words, size_t index, size_t *word_count)
{
    for (size_t i = index + 1; i < *word_count; i++)
        words[i - 1] = words[i];

    (*word_count)--;
}

void make_string(char *str, char **words, size_t word_count)
{
    *str = '\0';
    for (size_t i = word_count; i; --i)
    {
        modify_word(words[i]);
        strncat(str, words[i], MAX_STR_LEN);
        if (i > 1)
            strncat(str, " ", MAX_STR_LEN);
    }
}

void modify_word(char *word)
{
    for (char *i = word; *i; i++)
        for (char *j = i + 1; *j; j++)
            if (*i == *j)
            {
                delete_letter(word, j - word);
                j--;
            }
}

void delete_letter(char *word, size_t index)
{
    for (char *i = word + index; *i; i++)
        *i = *(i + 1);
}


