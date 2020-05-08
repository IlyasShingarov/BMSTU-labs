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
    
    return i == 0 || i <= line_size;
    
}

void transform(char **a ,  char *buffer, size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
        *(a + i) = buffer + i * m;
}



