# include <stdio.h>
# include <math.h>

float s_func(float x, float eps);
float abs_error(float s, float f);
float rel_error(float s, float f);

int main(void)
{
    float x, eps;
    printf("Input x:\n");
    if (scanf("%f", &x) != 1 || (-1 < x && x < 1))
    {
        printf("Wrong data");
        return 1;
    }

    printf("Input eps:\n");
    if (scanf("%f", &eps) != 1 || (0 < eps && eps < 1))
    {
        printf("Wrong data");
        return 1;
    }

    float s;
    s = s_func(x, eps);

    float f;
    f = atanf(x);

    float aerror;
    aerror = abs_error(s, f);

    float rerror;
    rerror = rel_error(s, f);


    printf("%f", s);
    printf("%f", f);
    printf("%f", aerror);
    printf("%f", rerror);

    return 0;
}

float s_func(float x, float eps)
{
    float sprev = x;
    float snext, s;

    s = sprev;

    for (int i = 3; sprev > eps ; i += 2)
    {
        snext = sprev * (-1) * x * x / i;
        s += snext;
        sprev = snext;
    }

    return s;
}

float abs_error(float s, float f)
{
    float result;

    result = fabsf(f - s);

    return result;
}

float rel_error(float s, float f)
{
    float result;

    result = fabsf((f - s) / f);

    return result;
}