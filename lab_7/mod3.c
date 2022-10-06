#include <stdio.h>

#define N 5

int main()
{
    int a, count = 0;

    int mod3[N] = {0};
    int array[N] = {0};

    int max = array[0];

    //заполнили массив своими числами
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a);
        array[i] = a;
    }

    for (int i = 0; i < N; i++)
    {
        if (array[i] % 3 == 0)
        {
            mod3[i] = array[i];
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (max < mod3[i])
        {
            max = mod3[i];
        }
    }
    printf("Max mod3 number is: %d ", max);
}
