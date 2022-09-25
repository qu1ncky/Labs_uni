#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
        return b;
}

int main()
{

    int a, b, countAll = 0;
    bool flag = false;

    printf("Put value for a: ");
    scanf("%d", &a);
    printf("Put value for b: ");
    scanf("%d", &b);

    int array[max(a, b)][2];
    int size = (sizeof(array) / sizeof(array[0]));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            array[i][j] = 0;
        }
    }

    while (a <= 0 || b <= 0)
    {
        printf("Enter the correct values\n");

        printf("Put value for a: ");
        scanf("%d", &a);
        printf("Put value for b: ");
        scanf("%d", &b);
    }

    while (b > 0 && a > 0)
    {
        if (a > b)
        {
            a -= b;
            for (int i = 0; i < size; i++)
            {
                if (array[i][0] == b)
                {
                    array[i][1]++;
                    break;
                }
                else if (i == (size - 1))
                {
                    for (int j = 0; j < size; j++)
                    {
                        if (array[j][0] == 0)
                        {
                            array[j][0] = b;
                            array[j][1] = 1;
                            break;
                        }
                    }
                }
            }
        }
        else
        {
            b -= a;
            for (int i = 0; i < size; i++)
            {
                if (array[i][0] == a)
                {
                    array[i][1]++;
                    break;
                }
                else if (i == (size - 1))
                {
                    // printf("added\n");
                    for (int j = 0; j < size; j++)
                    {
                        if (array[j][0] == 0)
                        {
                            array[j][0] = a;
                            array[j][1] = 1;
                            break;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (array[i][0] != 0)
        {
            printf("Square %d x %d - %d\n", array[i][0], array[i][0], array[i][1]);
        }
    }

    for (int i = 0; i < size; i++)
    {
        if (array[i][0] != 0)
        {
            countAll += array[i][1];
        }
    }
    printf("Count of squares: %d\n", countAll);
    return 0;
}
