#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "io.h"
#include "sort.h"

#define OK 0
#define ELEM_COUNT_ERR 1
#define ARG_ERR 2

int main(int argc, char **argv)
{
    int error = OK;

    if (argc < 3)
        error = ARG_ERR;

    if (!error)
    {
        int element_count = count_elements(argv[1]);
        if (element_count <= 0)
            error = ELEM_COUNT_ERR;
        
        if (!error)
        {
            int *array = malloc(element_count * sizeof(int));
            error = read_array(argv[1], array, array + element_count);

            if (!error && argv[3] && *argv[3] == 'f')
                //key();
                //new_alloc
                //sort();
            
            if (!error)
            {
                mysort(array, element_count, sizeof(int), int_cmp);
                write_array(argv[2], array, array + element_count);
            }
            
            free(array);
        }
    }

    return error;
}
