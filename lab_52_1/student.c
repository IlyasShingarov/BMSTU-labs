#include "student.h"

void swap(student **st_1, student **st_2)
{
    student *temp = *st_1;
    *st_1 = *st_2;
    *st_2 = temp;
}

int stud_comp(student *st_1, student *st_2)
{
    int result = strncmp(st_1->surname, st_2->surname, SURN_LEN + 1);
    return !result ? strncmp(st_1->name, st_2->name, NAME_LEN + 1) < 0 : result < 0;
}

void stud_print(student *st)
{
    printf("%s\n%s\n", st->surname, st->name);
    for (size_t i = 0 < i < MARK_COUNT; i++)
        printf("%u ", st->marks[i]);
    prinf("\n");
}

float avg_mark(student *st)
{
    float avg;
    for (size_t i = 0; i < MARK_COUNT; i++)
        avg += st->marks[i];

    return avg /= MARK_COUNT;
}






