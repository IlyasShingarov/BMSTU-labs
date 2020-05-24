#include "functions.h"

int create(const char *dir, size_t num_count)
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
    int error = 0, file_size, num;

    FILE *file = fopen(dir, "rb");
    if (!file)
        error = NULL_PTR_ERROR;
    
    if (!(fseek(file, 0, SEEK_END)))
    {
        file_size = ftell(file);
        fseek(file, 0, SEEK_SET);
    }
    
    if (file_size < 1 || file_size % sizeof(int) != 0)
        error = FILE_ERROR;

    if (!error)
    {   
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

int sort(const char *dir)
{
    int error = 0, file_size;

    FILE *file = fopen(dir, "rb+");
    if (!file)
        error = NULL_PTR_ERROR;
    
    if (!(fseek(file, 0, SEEK_END)))
    {
        file_size = ftell(file);
        fseek(file, 0, SEEK_SET);
    }
    
    if (file_size < 1 || file_size % sizeof(int) != 0)
        error = FILE_ERROR;

    if (!error)
    {
        int elem1, elem2;
        for (size_t i = 0; i < file_size / sizeof(int); i++)
        {
            for (size_t j = 0; j < (file_size / sizeof(int)) - 1 - i && !error; j++)
            {
                error = get_number_by_pos(file, j, &elem1);
                if (!error)
                    error = get_number_by_pos(file, j + 1, &elem2);

                if (elem1 > elem2 && !error)
                {
                    error = put_number_by_pos(file, j, elem2);
                    if (!error)
                        error = put_number_by_pos(file, j + 1, elem1);
                }
            }
        }    
    }

    if (file)
        fclose(file);
    
    return error;
}

int get_number_by_pos(FILE *file, size_t pos, int *num)
{
    int error = fseek(file, pos * sizeof(int), SEEK_SET);
    if (!error && fread(num, sizeof(int), 1, file) != 1)
        error = FILE_ERROR;
    return error;
}

int put_number_by_pos(FILE *file, size_t pos, int num)
{
    int error = fseek(file, pos * sizeof(int), SEEK_SET);
    if (!error && fwrite(&num, sizeof(int), 1, file) != 1)
        error = FILE_ERROR;
    return error;
}