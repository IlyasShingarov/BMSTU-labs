#include <stdio.h>
#include "lib.h"

int input_fraction(int *dividend, int *divisor);

int main(void)
{
	int dividend, divisor, div, mod;
	
	int error = input_fraction(&dividend, &divisor);
	error = div_mod(dividend, divisor, &div, &mod);

	if (!error)
		printf("%d\t%d\t%d", error, div, mod);
	else
		printf("Error");
	
	return error;
}

int input_fraction(int *dividend, int *divisor)
{
	int error = ERR_OK;

	if (scanf("%d%d", dividend, divisor) != 2)
		error = ERR;

	return error;
}
