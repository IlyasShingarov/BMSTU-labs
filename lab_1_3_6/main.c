#include <stdio.h>
#include <math.h>

#define ZERO 1e-7

float external_product(float x1, float y1, float x2, float y2);
int point_input(float *p1, float *p2);

int main(void)
{
    float x1, x2, y1, y2, xa, ya;
    int state, error = 0;

    error = point_input(&x1, &y1);

    if (!error)
        error = point_input(&x2, &y2);

    if (!error)
        error = point_input(&xa, &ya);

    if (!error)
    {
        float linex, liney, pointx, pointy;
        linex = x2 - x1; liney = y2 - y1;
        pointx = xa - x1; pointy = ya - y1;

        if (fabsf(linex) <= ZERO && fabsf(liney) <= ZERO)
            error = 1;
        else
        {
            if (external_product(linex, liney, pointx, pointy) > 0)
                state = 0;
            else if (fabsf(external_product(linex, liney, pointx, pointy)) <= ZERO)
                state = 1;
            else
                state = 2;

            printf("State: %d", state);
        }
    }

    if (error)
        printf("Incorrect data");
    
    return error;
}

float external_product(float x1, float y1, float x2, float y2)
{
    return x1 * y2 - x2 * y1;
}


int point_input(float *p1, float *p2)
{
    int error = 0;
    printf("Input x, y of the point:\n");
    if (scanf("%f%f", &p1, &p2) != 2)
        error = 1;
    
    return error;
}
