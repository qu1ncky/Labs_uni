#include <stdbool.h>
#include <stdio.h>

int main()
{

    int array[10];
    int a, countB = 0, countW = 0;
    for (int i = 0; i < sizeof(array) / sizeof(int); i++)
    {
        array[i] = 7;
    }

    printf("Put the a value: ");
    scanf("%d", &a);
    if (a != 1 && a != 0)
    {
        printf("Black - %d, White - %d", countB, countW);
        return 0;
    }
    array[0] = a;
    if (a == 1)
        countB++;
    if (a == 0)
        countW++;

    for (int i = 1; i < sizeof(array) / sizeof(int); i++)
    {
        printf("Put the a value: ");
        scanf("%d", &a);
        if (a == 0 || a == 1)
        {
            array[i] = a;
        }
        else
        {
            break;
        }
    }
    for (int i = 1; i < sizeof(array) / sizeof(int); i++)
    {
        if (array[i] != array[i - 1] && array[i] == 1)
        {
            countB++;
        }
        if (array[i] != array[i - 1] && array[i] == 0)
        {
            countW++;
        }
    }

    printf("Black lines: - %d, White lines: - %d", countB, countW);
    return 0;
}
