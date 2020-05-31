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
        error = fseek(file, 0, SEEK_SET);
    }
    else
        error = FILE_ERROR;

    return error;
}

int sb_sort(FILE *file, int size)
{
    student elem_1 = { { "" }, { "" }, { 0, 0, 0, 0 } }, elem_t = { { "" }, { "" }, { 0, 0, 0, 0 } };
    int pos = 0;
    int error = 0;

    for (int i = 1; i < size && !error; i++)
    {
        pos = i - 1;
        error = get_struct_by_pos(file, &elem_1, i);
        if (!error)
            error = get_struct_by_pos(file, &elem_t, pos);

        while (pos >= 0 && stud_comp(&elem_1, &elem_t) && !error)
        {
            error = put_struct_by_pos(file, &elem_t, pos + 1);
            pos--;
            if (!error)
                error = get_struct_by_pos(file, &elem_t, pos);
        }
        if (!error)
            error = put_struct_by_pos(file, &elem_1, pos + 1);
    }

    return error;
}                   


int fb_print(FILE *file_in, FILE *file_out, int size, const char *str)
{
    int error = 0, count = 0;
    student temp = { { "" }, { "" }, { 0, 0, 0, 0 } };
    for (int i = 0; i < size && !error; i++)
    {
        error = get_struct_by_pos(file_in, &temp, i);
        char *substr_pos = strstr(temp.surname, str);
        if (substr_pos && !(substr_pos - temp.surname) && !error)
        {
            error = put_struct_by_pos(file_out, &temp, count);
            count++;
        }
    }

    return !count;
}

int print_bin_above_avg(FILE *file, const char *filename, int size)
{
    int error = 0;
    float sum = 0;
    student temp = { { "" }, { "" }, { 0, 0, 0, 0 } };
    for (int i = 0; i < size && !error; i++)
    {
        error = get_struct_by_pos(file, &temp, i);
        if (!error)
            sum += avg_mark(&temp);
    }

    float avg = sum / size;

    int count = 0;
    for (int i = 0; i < size && !error; i++)
    {
        error = get_struct_by_pos(file, &temp, i);
        if (avg_mark(&temp) >= avg && !error)
        {
            error = put_struct_by_pos(file, &temp, count);
            count++;
        }
        else if (fabsf(avg_mark(&temp) - avg) <= EPS)
        {
            error = put_struct_by_pos(file, &temp, count);
            count++;
        }
    }
    if (!error)
        error = truncate(filename, count * sizeof(temp));
    
    return error;
}

void print_bin(FILE *file)
{
    student stud = { { "----" }, { "----" }, { 1, 1, 1, 1 } };
    int size;
    int error = get_size(file, &size);
    for (size_t i = 0; i < (size / sizeof(stud)) && !error; i++)
    {
        error = get_struct_by_pos(file, &stud, i);
        if (!error)
            stud_print(&stud);
    }
}