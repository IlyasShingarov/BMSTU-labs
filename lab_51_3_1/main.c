#include "functions.h"

int main(void)
{
    int count = 0;
    
    int error = process(stdin, &count);

    if (!error)
        printf("\nResult: %d\n", count);
    else
        printf("\nError");

    return error;
}