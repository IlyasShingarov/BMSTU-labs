#include "functions.h"

int process(FILE *file, int *count)
{
    if(!file)
        return NULL_PTR_ERROR;
    
    int elem;
    int error = 0;

    if (fscanf(file, "%d", &elem) != 1)
        error = FILE_ERROR;
    else
    {
        int state = elem >= 0 ? POSITIVE : NEGATIVE;
    
        while (fscanf(file, "%d", &elem) == 1)
        {
            if (elem < 0 && state == POSITIVE)
            {
                (*count)++; 
                state = NEGATIVE;
            }
            else if (elem >= 0 && state == NEGATIVE)
            {
                (*count)++;
                state = POSITIVE;
            }           
        }
    }

    return error;
}