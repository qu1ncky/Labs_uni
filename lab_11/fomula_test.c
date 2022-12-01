#include <stdio.h>
#include <math.h>

double sinx(double x, int n)
{
    double a = x;
    double sum = a;
    printf("%d %f\n", 0, sum);

    for (int i = 1; i <= n; i++)
    {
        a = (a * (-1) * x * x) / (2 * i * (2 * i + 1));
        sum += a;
        printf("%d -- %lf\n", i, sum);
    }
    return sum;
}

int main()
{
    double point = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;
    int steps = 100;
    sinx(point, steps);
    return 0;
}