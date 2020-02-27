# include <stdio.h>
# include <math.h>

double s_func(double x, double eps);
double abs_error(double s, double f);
double rel_error(double s, double f);

int main(void)
{
    setbuf(stdout ,NULL);

    double x, eps;
    printf("Input x:\n");
    if (scanf("%lf", &x) != 1 || fabs(x) > 1)
    {
        printf("Wrong data");
        return 1;
    }

    printf("Input eps:\n");
    if (scanf("%lf", &eps) != 1 || 0 > eps || eps > 1)
    {
        printf("Wrong data");
        return 1;
    }

    double s;
    s = s_func(x, eps);

    double f;
    f = atan(x);

    double aerror;
    aerror = abs_error(s, f);

    double rerror;
    rerror = rel_error(s, f);


    printf("%lf", s);
    printf("%lf", f);
    printf("%lf", aerror);
    printf("%lf", rerror);

    return 0;
}

double s_func(double x, double eps)
{
    double s, numerator;
    unsigned int i = 1;
    double sprev, snext;

    sprev = numerator = s = x;

    while (fabs(sprev) >= eps)
    {
        i += 2;
        numerator *= -1 * x * x;
        snext = numerator / i;
        s += snext;
        sprev = snext;
    }

    return s;
}

double abs_error(double s, double f)
{
    double result;

    result = fabs(f - s);

    return result;
}

double rel_error(double s, double f)
{
    double result;

    result = fabs((f - s) / f);

    return result;
}