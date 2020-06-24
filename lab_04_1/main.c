#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_string.h"

int main(void)
{
	printf("%zu\n", my_strspn("123456789", "123"));
	printf("%zu\n", strspn("123456789", "123"));
	
	printf("\n%zu\n", my_strspn("123456789", "321"));
	printf("%zu\n", strspn("123456789", "321"));

	printf("\n%zu\n", my_strspn("0123456", "321"));
	printf("%zu\n", strspn("0123456", "321"));

	printf("\n%zu\n", my_strspn("1254231", "23"));
	printf("%zu\n", strspn("1254231", "23"));

	printf("\n%zu\n", my_strspn("", "23"));
	printf("%zu\n", strspn("", "23"));

	printf("\n%zu\n", my_strspn("1254231", ""));
	printf("%zu\n", strspn("1254231", ""));

	printf("\n%zu\n", my_strspn("\0", "123"));
	printf("%zu\n", strspn("\0", "123"));

	printf("\n%zu\n", my_strspn("125", "\0"));
	printf("%zu\n", strspn("125", "\0"));

	printf("\n%zu\n", my_strspn("", ""));
	printf("%zu\n", strspn("", ""));

	printf("\n%zu\n", my_strspn("\0", "\0"));
	printf("%zu\n", strspn("\0", "\0"));

	return 0;
}
