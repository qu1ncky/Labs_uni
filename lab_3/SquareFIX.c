#include <stdio.h>
#include <locale.h>
int main()
{

    int a, b, max, k;
    int s = 0;
    do
    {
        printf("First side: ");
        scanf_s("%d", &a);
    } while (a <= 0);
    do
    {
        printf("Second side: ");
        scanf_s("%d", &b);
    } while (b <= 0);
    if (a > b)
    {
        max = a;
        a = b;
        b = max;
    }
    if (a % b == 0)
    {
        printf("%d x %d - %d squares\n", a, a, a / b);
        s += a / b;
        a = 0;
        b = 0;
    }
    while (a != b)
    {
        if (a < b)
        {
            printf("%d x %d - %d squares\n", a, a, b / a);
            s += b / a;
            b -= a * (b / a);
            if (b == 0)
            {
                break;
            }
        }
        else
        {
            printf("%d x %d - %d squares\n", b, b, a / b);
            s += a / b;
            a -= b * (a / b);
            if (a == 0)
            {
                break;
            }
        }
    }
    printf("Count of squares: %d", s);
    return 0;
}