#include "functions.h"

int create(const char *dir, int num_count)
{
    int error = 0;

    FILE *file = fopen(dir, "wb");
    if (!file)
        error = NULL_PTR_ERROR;

    time_t t; 
    srand(time(&t));

    for (size_t i = 0; i < num_count && !error; i++)
    {
        int num = rand() % 100;
        if (fwrite(&num, sizeof(int), 1, file) != 1)
            error = FILE_ERROR;
    }

    if (file)
        fclose(file);

    return error;
}

int print(const char *dir)
{
    int error = 0, file_size;

    FILE *file = fopen(dir, "rb");
    if (!file)
        error = NULL_PTR_ERROR;
    
    if (!(fseek(file, 0, SEEK_END)))
        file_size = ftell(file);
    
    if (file_size < 1 || file_size % sizeof(int) != 0)
        error = FILE_ERROR;

    if (!error)
    {   
        int num;
        for (size_t i = 0; i < (file_size / sizeof(int)) && !error; i++)
        {
            if (fread(&num, sizeof(int), 1, file) == 1)
                printf("%d ", num);
            else
                error = FILE_ERROR;
        }

    }

    if (file)
        fclose(file);
    
    if(!error)
        printf("\n");
    else
        printf("Error");

    return error;
}