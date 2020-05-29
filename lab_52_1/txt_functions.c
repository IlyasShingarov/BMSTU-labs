#include "txt_functions.h"

int st_add(FILE *file, student *student)
{
    int error = !fprintf(file, "%s\n", student->surname);
    if (!error)
        error = !fprintf(file, "%s\n", student->name);
    if (!error)
    {
        error = !fprintf(file, "%u", student->marks[0]);
        for (size_t i = 1; i < MARK_COUNT && !error; i++)
            error = !fprintf(file, " %u", student->marks[i]);
        fprintf(file, "\n");
    }

    return error;
}


int st_readall(FILE *file, student *students, int max_size)
{
    int error = 0, end_state = 0, size = 0;
    while (!error && !end_state && size < max_size)
    {
        end_state = fscanf(file, "%s", students[size].surname) != 1;
        if (!end_state)
        {
            error = fscanf(file, "%s", students[size].name) != 1;
            if (!error)
                error = fscanf(file, "%u %u %u %u", &(students[size].marks[0]), &(students[size].marks[1]), &(students[size].marks[2]), &(students[size].marks[3])) != MARK_COUNT;
            size++;
        }
    }
    if (!end_state)
        error = IO_ERROR;
    if (error)
        size = -1;
    
    return size;
}

void st_sort(student **st_arr, int size)
{
    student *elem;
    int pos;

    for (int i = 1; i < size; i++)
    {
        elem = st_arr[i];
        pos = i - 1;

        while (pos >= 0 && compare(elem, st_arr[pos]))
        {
            swap(st_arr + pos + 1, st_arr + pos);
            pos--;
        }
        swap(st_arr + pos + 1, &elem);
    }
}


int print_above_avg(FILE *file_out, student *students, int size)
{
    int error = 0;
    float sum = 0;
    for (int i = 0; i < size; i++)
        sum += avg_mark(students + i);

    float avg = sum / size;

    for (int i = 0; i < size && !error; i++)
        if (avg_mark(students + i ) >= avg)
            error = st_add(file_out, students + i);
        else if (fabs(avg_mark(students + i) - avg) <= EPS)
            error = st_add(file_out, students + i);

    return error;
}

int ft_print(FILE *file, student *students, int size, char *field)
{
    int error = 0, count = 0;
    for (size_t i = 0; i < size && !error; i++)
    {
        char *substr_pos = strstr(students[i].surname, field);
        if (substr_pos && !(substr_pos - students[i].surname))
        {
            error = st_add(file, students + i);
            count++;
        }
    }

    return !count;
}
