#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// СИНУС
double sinx(double x, int n)
{
    while (x > 2 * M_PI && x > 0)
    {
        x -= 2 * M_PI;
    }
    printf("SINX RESULT\n");
    double a = x;
    double sum = a;
    printf("Step %d -- %f\n", 1, sum);

    for (int i = 1; i <= n; i++)
    {
        a = (a * (-1) * x * x) / (2 * i * (2 * i + 1));
        sum += a;
        printf("Step %d -- %lf\n", i + 1, sum);
    }
    return sum;
}

// КОСИНУС
double cosx(double x, int n)
{
    while (x > 2 * M_PI && x > 0)
    {
        x -= 2 * M_PI;
    }
    printf("COSX RESULT\n");
    double a = 1;
    double sum = a;
    printf("Step %d -- %f\n", 1, sum);

    for (int i = 1; i <= n; i++)
    {
        a = (a * (-1) * x * x) / (2 * i * (2 * i - 1));
        sum += a;
        printf("Step %d -- %lf\n", i + 1, sum);
    }

    return sum;
}

// ЭКСПОНЕНТА
double ex(double x, int n)
{
    printf("EXPONENTA RESULTS\n");
    double a = 1;
    double sum = a;
    printf("Step %d -- %lf\n", 1, sum);

    for (int i = 1; i <= n; i++)
    {
        a = (a * x) / i;
        sum += a;
        printf("Step %d -- %lf\n", i + 1, sum);
    }
    return sum;
}

int main()
{
    double point;
    int steps, answer;
    double sinSum, cosSum, expSum;
    double sinA, cosA, expA;
    bool sinFlag, cosFlag, expFlag;

    do
    {

        printf("\nTo open the menu, press 6\n");
        printf("\nChoose a fucntion: ");
        scanf("%d", &answer);
        switch (answer)
        {
        // ВВВОД ПАРАМЕТРОВ
        case 1:
            printf("Enter the X point: ");
            scanf("%lf", &point);

            printf("Enter the amount of steps for Taylor's formula: ");
            scanf("%d", &steps);

            sinA = sin(point);
            cosA = cos(point);
            expA = exp(point);

            sinFlag = false;
            cosFlag = false;
            expFlag = false;

            break;

        case 2:
            sinSum = sinx(point, steps);
            sinFlag = true;
            break;

        case 3:
            cosSum = cosx(point, steps);
            cosFlag = true;
            break;

        case 4:
            expSum = ex(point, steps);
            expFlag = true;
            break;

        case 5:
            if (sinFlag == true)
            {
                printf("\n\nSin function info:\n _________________\n");
                printf("Taylor 's Formula result: %lf\n Function in C result: %lf\n", sinSum, sinA);
            }
            if (cosFlag == true)
            {
                printf("\n\nCos function info:\n _________________\n");
                printf("Taylor 's Formula result: %lf\n Function in C result: %lf\n", cosSum, cosA);
            }
            if (expFlag == true)
            {
                printf("\n\nExponent function info:\n _________________\n");
                printf("Taylor 's Formula result: %lf\n Function in C result: %lf\n", expSum, expA);
            }
            break;

        case 6:
            printf("\n\nProgram commands\n________________________\n");
            printf("1. Parameters input\n");
            printf("2. Taylor's formula for SIN fucntion\n");
            printf("3. Taylor's formula for COS fucntion\n");
            printf("4. Taylor's formula for exponent fucntion\n");
            printf("5. Comparison of the results of the Taylor's formula and the function in C ");

        case 0:
            printf("Thanks for using program");
            break;

        default:
            printf("There is no such command. Check the command list\n");
            break;
        }

    } while (answer != 0);

    return 0;
}