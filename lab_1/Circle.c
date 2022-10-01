#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    float x1, y1, r1, x2, y2, r2;
    float dist;

    //параметры окружностей
    scanf_s("%f,%f,%f,%f,%f,%f", &x1, &y1, &r1, &x2, &y2, &r2);
    // формула расстояния между центрами окружностей
    dist = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
    printf("Distance is: %.2f\n", dist);

    if (dist == r1 + r2)
    {
        printf("The circles touch at one point (outside)");
        return 0;
    }

    else if (dist > r1 + r2)
    {
        printf("The circles do not touch");
        return 0;
    }

    else if ((x1 != x2 || y1 != y2) && (dist == abs(r1 - r2)))
    {
        printf("The circles touch from the inside");
        return 0;
    }

    else if (dist < abs(r1 - r2))
    {
        printf("The circle lies in another circle (the centers are different)");
        return 0;
    }

    else if ((dist > abs(r1 - r2)) && (dist < r1 + r2))
    {
        printf("The circles intersect at two points");
        return 0;
    }

    else if (dist == 0 && r1 != r2)
    {
        printf("Circles with the same center and different radii");
        return 0;
    }

    else
    {
        printf("The circles are the same");
        return 0;
    }

    return 0;
}

/// coommiit;