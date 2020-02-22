#include <stdio.h>

float mass(float h, float t);
float mass_index(float m, float h);

int main()
{
    float h, t;
    printf("Input mass:\n");
    scanf("%f", &h);
    printf("Input chest diameter:\n");
    scanf("%f", &t);
    
    float m = mass(h, t);

    float imt = mass_index(m, h);

    printf("Mass: %f\n", m);
    printf("Body mass index: %f\n", imt);

    return 0;
}

float mass(float h, float t)
{
    float m;
    m = h * t / 240;

    return m;
}

float mass_index(float m, float h)
{
    float imt;
    imt = 0.1 * m / (h * h);

    return imt;
}