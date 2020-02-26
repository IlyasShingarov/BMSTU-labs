#include <stdio.h>

int buy(int s);
int sell(int bottles);

int main(void)
{   
    int s;
    
    printf("Input an amount of money:\n");
    scanf("%d", &s);

    int bottles, bottle_count;

    bottle_count = 0;
    
    while (s >= 45)
    {
        bottles = buy(s);
        bottle_count += bottles;
        s -= bottles * 45;
        s += sell(bottles);
    }

    printf("Amount of bought bottles will be: %d", bottle_count);

    return 0;
}

int sell(int bottles)
{
    int s;

    s = bottles * 20;

    return s;
}

int buy(int s)
{
    int counter = 0;

    while (s >= 45)
    {
        s -= 45;
        counter += 1;
    }
    
    return counter;
}