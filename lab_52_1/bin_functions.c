#include "bin_functions.h"

int get_struct_by_pos(FILE *file, student *students, int pos)
{
    int error = fseek(file, pos * sizeof(*students), SEEK_SET);
    if (!error && fread(students, sizeof(*students), 1, file) != 1)
        error = IO_ERROR;

    return error;
}

int put_struct_by_pos(FILE *file, student *students, int pos)
{
    int error = fseek(file, pos * sizeof(*students), SEEK_SET);
    if (!error && fwrite(students, sizeof(*students), 1, file) != 1)
        error = IO_ERROR;

    return error;
}

int get_size(FILE *file, int *size)
{
    int error = 0, s = 0;
    if (!fseek(file, 0, SEEK_END))
        s = ftell(file);
    if (s >= 0)
    {
        *size = s;
        error = fseek(file, 0L, SEEK_SET);
    }
    else
        error = FILE_ERROR;

    return error;
}







































void print_bin(FILE *file)
{
    student stud = { { "----" }, { "----" }, { 1, 1, 1, 1 } };
    int size;
    int error = get_file_size(file, &size);
    for (size_t i = 0; i < (size / sizeof(stud)) && !error; i++)
    {
        error = get_struct_by_pos(file, &stud, i);
        if (!error)
            stud_print(&stud);
    }
}