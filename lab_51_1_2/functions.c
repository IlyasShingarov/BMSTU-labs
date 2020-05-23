#include "functions.h"

int process(FILE *file, int *count)
{
    if (!file)
        return NULL_PTR_ERROR;

    float element;
    int error = 0;
    if (fscanf(file, "%f", &element) != 1)
        error = FILE_ERROR;
    else
    {
        float max = element, min = element;
        while (fscanf(file, "%f", &element) == 1)
        {
            if (element > max)
                max = element;
            if (element < min)
                min = element;
        }
        
        float arith_mean = 0.5 * (min + max);
        
        fseek(file, 0, SEEK_SET);

        while (fscanf(file, "%f", &element) == 1)
        {
            if (element > arith_mean)
                (*count)++;
        }
    }

    return error;
}