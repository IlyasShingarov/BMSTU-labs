#include <stdio.h>

int buy(int s);
int sell(int bottles);

int main(void)
{   
    int s;
    
    printf("Input an amount of money:\n");
    scanf("%d", &s);

    int bottle_count = (s - 20) / 25;

    printf("Amount of bought bottles will be: %d", bottle_count);

    return 0;
}