#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my_string.h"

size_t my_strspn(const char *string, const char *chars)
{
	size_t n = 0;
	const char *p = chars;
	while (*string && *p)
	{
		for (p = chars; *p && *p != *string; p++);
		string++, n++;
	}
	
	return n ? --n : 0;
}

