#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, x, x1, x2;
    double D;

    scanf("%f,%f,%f", &a, &b, &c);

    D = (((b) * (b)) - (4 * a * c));
    if (D > 0)
    {
        D = sqrt(D);
    }
    else if (D < 0)
    {
        printf("No roots");
        return 0;
    }

    if (a == 0 && b == 0 && c == 0)
    {
        printf("True for any X");
    }

    else if (a == 0 && b == 0 && c != 0)
    {
        printf("No roots");
    }

    else if ((D == 0) && (a != 0))
    {
        x = (-b) / 2 * a;
        printf("Answer: %.2f", x);
    }

    else if ((D < 0) && (a != 0))
        printf("No roots");

    else if ((D > 0) && (a != 0))
    {
        x1 = (-b + D) / 2 * a;
        x2 = (-b - D) / 2 * a;
        printf(" Answers: %.2f,%.2f", x1, x2);
    }

    else if (a == 0)
    {
        x = -c / b;
        printf("Answer: %.2f", x);
    }

    return 0;
}