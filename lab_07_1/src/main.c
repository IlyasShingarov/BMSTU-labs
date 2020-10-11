#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "errors.h"
#include "io.h"
#include "sort.h"
#include "filter.h"

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
            if (!array)
                error = ALLOC_ERR;
            
            if (!error)
                error = read_array(argv[1], array, array + element_count);

            if (!error && argv[3] && *argv[3] == 'f')
            {
                int *t_beg = NULL, *t_end = NULL;
                if (!key(array, array + element_count, &t_beg, &t_end))
                {
                    mysort(t_beg, t_end - t_beg, sizeof(int), int_cmp);
                    write_array(argv[2], t_beg, t_end);
                    free(t_beg);
                }
            }
            else if (argv[3])
                error = ARG_ERR;
            
            if (!error && !argv[3])
            {
                mysort(array, element_count, sizeof(int), int_cmp);
                write_array(argv[2], array, array + element_count);
            }
            free(array);
        }
    }

    return error;
}
