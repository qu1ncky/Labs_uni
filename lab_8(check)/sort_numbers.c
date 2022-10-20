#include <stdio.h>

// N - кол-во входных чисел
#define N 100

int main()
{
    int a, countMinus = 0, countPlus = 0;
    int array[N] = {0};
    int positive_numbers[N] = {0};
    int negative_numbers[N] = {0};

    printf("Enter the value for programm: ");

    //Ввод значений
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a);
        if (a == 0)
        {
            break;
        }
        array[i] = a;
    }

    //Сортировка чисел

    for (int i = 0; i < N; i++)
    {
        if (array[i] < 0)
        {
            negative_numbers[i] = array[i];
            countMinus++;
        }

        if (array[i] > 0)
        {
            positive_numbers[i] = array[i];
            countPlus++;
        }
    }

    //Вывод массивов

    if (countMinus > 0)
    {
        printf("Negative number(s): ");
        for (int i = 0; i < N; i++)
        {
            if (negative_numbers[i] != 0)
            {
                printf("%d ", negative_numbers[i]);
            }
        }
    }

    if (countPlus > 0)
    {
        printf("Positive number(s): ");

        for (int i = 0; i < N; i++)
        {
            if (positive_numbers[i] != 0)
            {
                printf("%d ", positive_numbers[i]);
            }
        }
    }

    return 0;
}