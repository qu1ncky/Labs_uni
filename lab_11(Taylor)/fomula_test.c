#include <stdio.h>
#include <math.h>

int main()
{
    double a = 10.4;
    if (a > 2 * M_PI)
    {
        printf("JOPA");
        while (a > 3.1459)
        {
            a = -2 * M_PI;
        }
    }

    printf("result is: %lf", a);
    return 0;
}