#include <stdio.h>
#include <string.h>

#include "films.h"
#include "errors.h"
#include "wrap.h"

int main(int argc, char **argv)
{
	int error = ERR_OK;

	if (argc < 3)
		error = ERR_ARG;

	if (!error)
	{
		if (!strcmp(argv[2], "title"))
			error = title_mode(argv[1], argv[3]); // Тут будет поиск по полю названия
		else if (!strcmp(argv[2], "name"))
			error = name_mode(argv[1], argv[3]);//error = name_mode(argv[1]); // Тут будет поиск по имени режиссера
		else if (!strcmp(argv[2], "year"))
			error = year_mode(argv[1], argv[3]);//error = year_mode(argv[1]); // Тут будет поиск по году
		else
			error = ERR_ARG;
	}

	return error;
}
