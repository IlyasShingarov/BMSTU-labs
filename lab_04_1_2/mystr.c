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

size_t delete_word(size_t index, char **words, size_t word_counter)
{
    words[index] = words[word_counter - 1];

    return word_counter - 1;
}

void line_out(char **words, size_t word_count)
{
    printf("Result: ");
    for (size_t i = 0; i < word_count; i++)
    {
        printf("%s", words[i]);
        if (i != word_count - 1)
            printf(" ");
    }
}

void remove_duplicates(char **words, size_t *word_count)
{
    for (size_t i = 0; i < *word_count; i++)
        for (size_t j = i + 1; j < *word_count; j++)
        {
            if (strncmp(words[i], words[j], MAX_WORD_LEN) == 0)
                *word_count = delete_word(j, words, *word_count);
        }
}

void swap(char *xp, char *yp)
{
    char temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}

void sort_words(char **words, size_t word_count) 
{ 
    size_t swapped; 
    for (size_t i = 0; i < word_count - 1; i++) 
    { 
        swapped = 0; 
        for (size_t j = 0; j < word_count - i - 1; j++)  
            if (strncmp(words[j], words[j + 1], MAX_WORD_LEN) > 0) 
            { 
                swap(words[j], words[j + 1]); 
                swapped = 1; 
            }
        if (swapped == 0) 
            break;
    } 
} 
