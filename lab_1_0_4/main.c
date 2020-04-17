#include <stdio.h>

int get_amount(void);
int count_bottles(int s);
int print_bottles(n);

int main(void)
{   
    int s = get_amount();
    int bottle_count = count_bottles(s);

    return print_bottles(bottle_count);
}

int get_amount(void)
{
    int s;
    printf("Input an amount of money:\n");
    scanf("%d", &s);

    return s;
}

int count_bottles(int s)
{
    return (s - 20) / 25;
}

int print_bottles(n)
{
    printf("Amount of bought bottles will be: %d", n);
    
    return 0;
}