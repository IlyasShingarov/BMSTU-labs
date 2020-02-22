#include <stdio.h>

float weight(float h, float t);
float mass_index(float m, float h);

int main()
{
    float h, t, m;
    printf("Input height:\n");
    scanf("%f", &h);
    printf("Input chest diameter:\n");
    scanf("%f", &t);
    printf("Input mass:\n");
    scanf("%f", &m);

    float w = weight(h, t);

    float imt = mass_index(m, h);

    printf("Weight: %f\n", w);
    printf("Body mass index: %f\n", imt);

    return 0;
}

float weight(float h, float t)
{
    float w;
    w = h * t / 240;

    return w;
}

float mass_index(float m, float h)
{
    float imt;

    h = h / 100;
    imt = m / (h * h);

    return imt;
}