# include <stdio.h>
# include <math.h>

double s_func(double x, double eps);
double abs_error(double s, double f);
double rel_error(double s, double f);
void output(double s, double f, double a, double r);

int main(void)
{
    setbuf(stdout, NULL);

    int error = 0;

    double x, eps;
    printf("Input x:\n");
    if (scanf("%lf", &x) != 1 || fabs(x) > 1)
    {
        printf("Wrong data\n");
        error = 1;
    }

    printf("Input eps:\n");
    if (scanf("%lf", &eps) != 1 || eps > 1 || eps < 0)
    {
        printf("Wrong data\n");
        error = 1;
    }

    if (error == 0)
    {
        double s = s_func(x, eps);
        double f = atan(x);
        double aerror = abs_error(s, f);

        double rerror;
        if (fabs(f) > 1e-7)
            rerror = rel_error(s, f);
        else
            rerror = 0;

        output(s, f, aerror, rerror);
    }

    return error;
}

double s_func(double x, double eps)
{
    double sprev, snext, numerator, s;
    int i = 1;

    sprev = numerator = s = x;
    
    while (fabs(sprev) > eps)
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
    return fabs(f - s);
}

double rel_error(double s, double f)
{
    return fabs((f - s) / f);
}

void output(double s, double f, double a, double r)
{
    printf("%lf\n", s);
    printf("%lf\n", f);
    printf("%lf\n", a);
    printf("%lf", r);
}
