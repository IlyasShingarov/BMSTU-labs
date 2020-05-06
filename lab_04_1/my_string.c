#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my_string.h"




size_t my_strspn(const char *string, const char *chars)
{
	size_t n;
	const char *p;
	for (n = 0; *string; string++, n++)
	{
		for (p = chars; *p && *p != *string; p++)
			;
		if (!*p)
			break;
	}

	return n;
}

