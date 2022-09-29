#include <stdio.h>

int main()
{

    int N, maxCount = 0, count = 1, a, copy;
    float p;
    printf("Put N value: ");
    scanf("%d", &N);

    int array[N];
    for (int i = 0; i < sizeof(array) / sizeof(int); i++)
    {
        scanf("%d", &a);
        array[i] = a;
    }

    //ЕБАТЕЛЬСКАЯ СОРТИРОВКА (ЛУЧШЕ ЧЕМ ПУЗЫРЬКОМ...)
    for (int i = 1; i < N; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            if (array[j] <= array[j - 1])
            {
                copy = array[j];
                array[j] = array[j - 1];
                array[j - 1] = copy;
            }
            else
            {
                break;
            }
        }
    }

    for (int i = 1; i < N; i++)
    {
        if (array[i] == array[i - 1])
        {
            count++;
        }
        else
        {
            if (maxCount < count)
            {
                maxCount = count;
                count = 1;
            }
        }
    }
    if (count > maxCount)
    {
        maxCount = count;
    }
    p = (maxCount * 100 / N);
    printf("%.f%%", p);
    return 0;
}
