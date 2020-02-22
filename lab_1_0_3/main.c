#include <stdio.h>

float mass(float h, float t);
int mass_index(float m, float h);

int main()
{
    float h, t;
    printf("Input height:\n");
    scanf("%f", &h);
    if (h <= 0)
        return 1;

    printf("Input chest diameter:\n");
    scanf("%f", &t);
    if (t <= 0)
        return 1;
    
    float m = mass(h, t);

    int imt = mass_index(m, h);

    printf("Mass: %f\n", m);
    printf("Body mass index: %d\n", imt);

    return 0;
}

float mass(float h, float t)
{
    float m;
    m = h * t / 240;

    return m;
}

int mass_index(float m, float h)
{
    int imt;

    h = h / 100;
    imt = m / (h * h);

    return imt;
}