#include "functions.h"

int main(int argc, char **argv)
{
    int error = 0, count = 0;
    FILE *file;

    if (argc != 2)
        error = ARG_COUNT_ERROR;
    
    if (!error)
    {
        file = fopen(argv[1], "r");
        if (!file)
            error = FILE_ERROR;
    }
    
    if (!error)
        error = process(file, &count);

    if (!error)
        printf("\nResult: %d\n", count);
    else
        printf("\nError\n");

    return error;
}