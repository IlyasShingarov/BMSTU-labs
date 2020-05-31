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
            error = sort_structs(file, size / SIZE_STUDENT);
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
        for (int i = 0; i < MAX_STUDENTS; i++)
        {
            for (size_t j = 0; j < SURN_LEN; j++)
                students[i].surname[j] = '\0';
            for (size_t j = 0; j < NAME_LEN; j++)
                students[i].name[j] = '\0';
            for (size_t j = 0; j < MARK_COUNT; j++)
                students[i].marks[j] = 0;
        }
        
        int size = st_readall(file, students, MAX_STUDENTS);

        if (size > 0)
        {
            student *students_t[MAX_STUDENTS];
            for (int i = 0; i < size; i++)
                students_t[i] = &students[i];
        
            sort_array(students_t, size);
            for (int i = 0; i < size; i++)
                print_to_console(students_t[i]);
        }

        if (file)
            fclose(file);
    }

    return error;
}

int fb_mode(const char *dir_in, const char *dir_out, const char *substr)
{
    int error = 0;
    FILE *file_in = fopen(dir_in, "rb");
    FILE *file_out = fopen(dir_out, "wb");
    if (!file_in || file_out)
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
    
    student students[MAX_STUDENTS];
    for (size_t i = 0; i < MAX_STUDENTS; i++)
    {
        for (size_t j = 0; j < SURN_LEN; j++)
            students[i].surname[j] = '\0';
        for (size_t j = 0; j < NAME_LEN; j++)
            students[i].name[j] = '\0';
        for (size_t j = 0; j < MARK_COUNT; j++)
            students[i].marks[j] = 0;
    }

    int size = st_readall(file_in, students, MAX_STUDENTS);

    if (size <= 0)
        error = FILE_ERROR;
    
    if (!error)
        error = ft_print(file_out, students, size, substr);
    
    if (file_in)
        fclose(file_in);
    
    if (file_out)
        fclose(file_out);

    return error;
}





















int db_mode();
int dt_mode();












