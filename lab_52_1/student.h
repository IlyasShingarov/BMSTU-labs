#ifndef _STUDENT_H_
#define _STUDENT_H_

#define SURN_LEN 25
#define NAME_LEN 10
#define MARK_COUNT 4
#define SIZE_STUDENT 56

#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct student
{
    char surname[SURN_LEN + 1];
    char name[NAME_LEN + 1];
    uint32_t marks[MARK_COUNT];
} student;

void swap(student **st_1, student **st_2);
int stud_comp(student *st_1, student *st_2);
float avg_mark(student *st);
void stud_print(student *st);

#endif