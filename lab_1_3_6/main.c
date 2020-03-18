#include <stdio.h>
#include <math.h>

float external_product(float x1, float y1, float x2, float y2);

int main(void)
{
    float x1, x2, y1, y2, xa, ya;
    int state, error = 0;

    printf("Input x1, y2:\n");
    if (scanf("%f%f", &x1, &y1) != 2)
        error = 1;

    printf("Input x2, y2:\n");
    if (scanf("%f%f", &x2, &y2) != 2)
        error = 1;

    printf("Input xA, yA:\n");
    if (scanf("%f%f", &xa, &ya) != 2)
        error = 1;

    float linex, liney, pointx, pointy;
    linex = x2 - x1; liney = y2 - y1;
    pointx = xa - x1; pointy = ya - y1;

    if (fabsf(linex) <= 1e-7 && fabsf(liney) <= 1e-7)
        error = 2;

    if (external_product(linex, liney, pointx, pointy) > 0)
        state = 0;
    else if (fabsf(external_product(linex, liney, pointx, pointy)) <= 1e-7)
        state = 1;
    else
        state = 2;

    printf("State: %d", state);

    return error;
}

float external_product(float x1, float y1, float x2, float y2)
{
    return x1 * y2 - x2 * y1;
}
