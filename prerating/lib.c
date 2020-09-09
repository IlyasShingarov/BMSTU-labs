#include "lib.h"

int div_mod(int dividend, int divisor, int *div, int *mod)
{
	int error = ERR_OK;
	if (divisor != 0)
	{
		*div = dividend / divisor;
		*mod = dividend % divisor;
	}
	else
		error = ERR;

	return error;
}
