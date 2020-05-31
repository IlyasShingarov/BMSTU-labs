#ifndef _WRAP_H_
#define _WRAP_H_

#define MAX_STUDENTS 1000

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include "bin_functions.h"
#include "txt_functions.h"
#include "student.h"

int sb_mode(const char *dir);
int st_mode(const char *dir);
int fb_mode(const char *dir_in, const char *dir_out, const char *substr);
int ft_mode(const char *dir_in, const char *dir_out, const char *substr);
int db_mode(const char *dir);
int dt_mode(const char *dir);





#endif