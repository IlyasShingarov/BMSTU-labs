#include <stdio.h>
#include <math.h>

float external_product(float x1, float y1, float x2, float y2);

int main(void)
{
    float x1, x2, y1, y2, xa, ya;
    int state;

    printf("Input x1:\n");
    if (scanf("%f", &x1) != 1)
    {
        printf("Incorrect data");
        return 1;
    }

    printf("Input y1:\n");
    if (scanf("%f", &y1) != 1)
    {
        printf("Incorrect data");
        return 1;
    }

    printf("Input x2:\n");
    if (scanf("%f", &x2) != 1)
    {
        printf("Incorrect data");
        return 1;
    }

    printf("Input y2:\n");
    if (scanf("%f", &y2) != 1)
    {
        printf("Incorrect data");
        return 1;
    }

    printf("Input xA:\n");
    if (scanf("%f", &xa) != 1)
    {
        printf("Incorrect data");
        return 1;
    }

    printf("Input yA:\n");
    if (scanf("%f", &ya) != 1)
    {
        printf("Incorrect data");
        return 1;
    }

    float linex, liney, pointx, pointy;
    linex = x2 - x1; liney = y2 - y1;
    if (fabsf(linex) <= 1e-7 && fabsf(linex) <= 1e-7)
    {
        printf("Error");
        return 2;
    }

    pointx = xa - x1; pointy = ya - y1;

    if (external_product(linex, liney, pointx, pointy) > 0)
    {
        state = 0;
    }
    else if (fabsf(external_product(linex, liney, pointx, pointy)) <= 1e-7)
    {
        state = 1;
    }
    else
    {
        state = 2;
    }

    printf("State: %d", state);

    return 0;
}

float external_product(float x1, float y1, float x2, float y2)
{
    float product;

    product = x1 * y2 - x2 * y1;

    return product;
}