#include "wrap.h"

int sb_mode(const char *dir)
{
    int error = 0;
    FILE *file = fopen(dir, "r+b");
    
    if (!file)
        error = NULL_PTR_ERROR;

    if (!error)
    {
        int size;
        if (!get_size(file, &size) && size > 0 && size % SIZE_STUDENT == 0)
        {
            error = sb_sort(file, size / SIZE_STUDENT);
            if (!error)
                print_bin(file);
        }
        else
            error = FILE_ERROR;
        
        if (file)    
            fclose(file);
    }

    return error;
}

int st_mode(const char *dir)
{
    int error = 0;
    FILE *file = fopen(dir, "r");
    if (!file)
        error = NULL_PTR_ERROR;

    if (!error)
    {
        student students[MAX_STUDENTS];
        student_zero(students);
        
        int size = st_readall(file, students, MAX_STUDENTS);

        if (size > 0)
        {
            student *students_t[MAX_STUDENTS];
            for (int i = 0; i < size; i++)
                students_t[i] = &students[i];
        
            st_sort(students_t, size);
            for (int i = 0; i < size; i++)
                stud_print(students_t[i]);
        }
        else
            error = FILE_ERROR;
    }

    if (file)
        fclose(file);

    return error;
}

int fb_mode(const char *dir_in, const char *dir_out, const char *substr)
{
    int error = 0;
    FILE *file_in = fopen(dir_in, "rb");
    FILE *file_out = fopen(dir_out, "wb");
    if (!file_in || !file_out)
        error = NULL_PTR_ERROR;

    if (!error)
    {
        int size;
        if (!get_size(file_in, &size) && size > 0 && size % SIZE_STUDENT == 0)
            error = fb_print(file_in, file_out, size, substr);
        else
            error = FILE_ERROR;
    }

    if (file_in)
        fclose(file_in);
    if (file_out)
        fclose(file_out);

    return error;
}

int ft_mode(const char *dir_in, const char *dir_out, const char *substr)
{
    int error = 0;
    FILE *file_in = fopen(dir_in, "r");
    FILE *file_out = fopen(dir_out, "w");
    if (!file_in || !file_out)
        error = NULL_PTR_ERROR;
    
    if (!error)
    {
        student students[MAX_STUDENTS];
        student_zero(students);

        int size = st_readall(file_in, students, MAX_STUDENTS);

        if (size <= 0)
            error = FILE_ERROR;

        if (!error)
            error = ft_print(file_out, students, size, substr);
    }
    
    if (file_in)
        fclose(file_in);
    
    if (file_out)
        fclose(file_out);

    return error;
}

int db_mode(const char *dir)
{
    int error = 0;
    FILE *file = fopen(dir, "rb+");
    if (!file)
        error = NULL_PTR_ERROR;
    
    if (!error)
    {
        int size;
        if (!get_size(file, &size) && size > 0 && size % SIZE_STUDENT == 0)
            error = print_bin_above_avg(file, dir, size / SIZE_STUDENT);
        else
            error = FILE_ERROR;
    }

    if (file)
        fclose(file);

    return error;
}

int dt_mode(const char *dir)
{
    int error = 0;
    FILE *file = fopen(dir, "r");
    if (!file)
        error = NULL_PTR_ERROR;
    
    if (!error)
    {
        student students[MAX_STUDENTS];
        student_zero(students);

        int size = st_readall(file, students, MAX_STUDENTS);

        if (size <= 0)
            error = FILE_ERROR;
        
        if (!error)
        {
            if (file)
                fclose(file);
            file = fopen(dir, "w");
            if (!file)
                error = NULL_PTR_ERROR;
            
            error = print_above_avg(file, students, size);
        }
    }

    if (file)
        fclose(file);

    return error;
}

void student_zero(student *stud)
{
    for (size_t i = 0; i < MAX_STUDENTS; i++)
    {
        for (size_t j = 0; j < SURN_LEN; j++)
            stud[i].surname[j] = '\0';
        for (size_t j = 0; j < NAME_LEN; j++)
            stud[i].name[j] = '\0';
        for (size_t j = 0; j < MARK_COUNT; j++)
            stud[i].marks[j] = 0;
    }
}
