#include <stdio.h>

float weigh(float h, float t);
int mass_index(float m, float h);

int main()
{
    float h, t, m;
    printf("Input height:\n");
    scanf("%f", &h);
    printf("Input chest diameter:\n");
    scanf("%f", &t);
    printf("Input mass:\n");
    scanf("%f", &m);

    float w = weigh(h, t);

    int imt = mass_index(m, h);

    printf("Weight: %f\n", w);
    printf("Body mass index: %d\n", imt);

    return 0;
}

float weigh(float h, float t)
{
    float w;
    w = h * t / 240;

    return w;
}

int mass_index(float m, float h)
{
    int imt;

    h = h / 100;
    imt = m / (h * h);

    return imt;
}