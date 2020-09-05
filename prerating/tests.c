#include <stdio.h>
#include "lib.h"

int test_01()
{
	int dividend = 5, divisor = 2;
	int div, mod;
	int error = div_mod(dividend, divisor, &div, &mod);
	if (!error && div == 2 && mod == 1)
		printf("OK\n");
	else
		printf("Fail\n");

	return error;
}


int test_02()
{
	int dividend = 5, divisor = 0;
	int div, mod;
	int error = div_mod(dividend, divisor, &div, &mod);
	if (error)
		printf("OK\n");
	else
		printf("Fail\n");

	return error;
}

int test_03()
{
	int dividend = 0, divisor = 1;
	int div, mod;
	int error = div_mod(dividend, divisor, &div, &mod);
	if (!error && !div && !mod)
		printf("OK\n");
	else
		printf("Fail\n");

	return error;

}

int main(void)
{
	int error = 0;

	test_01();
	test_02();
	test_03();

	return error;
}
