/*
Выбран целочисленный тип int
Алгоритм сортировки - пузырьковая
Упорядочивание по возрастанию
*/

#include <string.h>
#include "functions.h"


int main(int argc, char **argv)
{
    int error = 0;
    if (argc < 3 || argc > 4)
        error = ARG_COUNT_ERROR;
    
    size_t mode;
    if (!error)
    {
        if (!strcmp(argv[1], "c"))
            mode = CREATE_MODE;
        else if (!strcmp(argv[1], "p"))
            mode = PRINT_MODE;
        else if (!strcmp(argv[1], "s"))
            mode = SORT_MODE;
    }

    if (!error && mode)
    {
        size_t num_count;
        switch (mode)
        {
            case CREATE_MODE:
                if ((sscanf(argv[2], "%zu", &num_count) == 1))
                    error = create(argv[3], num_count);
                else
                    error = NUM_COUNT_ERROR;
                break;
            case PRINT_MODE:
                error = print(argv[2]);
                break;
            case SORT_MODE:
                error = sort(argv[2]);
                break;
        }
    }

    return error;
}