#include <stdio.h>
#include <stdlib.h>
#define N 3

int main()
{
    int a, countZero = 0;

    int mod3[N] = {0};
    int index = -1;

    //заполнили массив своими числами
    printf("Enter the values: ");

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a);
        if (a == 0)
        {
            countZero++;
        }
        if (abs(a) % 3 == 0)
        {
            mod3[i] = a;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (mod3[i] == 0)
        {
            mod3[i] = -1;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (abs(mod3[i]) % 3 == 0)
        {
            if (index == -1)
            {
                index = i;
            }
            else
            {
                if (mod3[i] > mod3[index])
                {
                    index = i;
                }
            }
        }
    }

    if (countZero > 0 && mod3[index] < 0)
    {
        printf("Max mod3 number is: 0");
    }

    else if (index > -1)
    {
        printf("Max mod3 nubmer is: %d", mod3[index]);
    }
    else
    {
        printf("Max mod3 number is not found");
    }

    return 0;
}
