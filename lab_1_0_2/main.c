#include <stdio.h>
#include <math.h>

float c_side(float a, float b, float h);
float perimeter(float a, float b, float c);

int main(void)
{
    float a, b, h;
    printf("Input base 1:\n"); scanf("%f", &a);
    printf("Input base 2:\n"); scanf("%f", &b);
    printf("Input height:\n"); scanf("%f", &h);

    float c = c_side(a, b, h);
    float p = perimeter(a, b, c);

    printf("Trapezoid perimeter: %f", p);

    return 0;
}

float c_side(float a, float b, float h)
{
    if (b < a)
    {
        float temp = b; b = a; a = temp;
    }
    
    return sqrt(0.25 * (b * b - 2 * a * b + a * a) + h * h);
}

float perimeter(float a, float b, float c)
    return 2 * c + a + b;