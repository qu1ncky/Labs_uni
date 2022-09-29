#include <stdio.h>

//на вход 2 значения , 1 = вин; 0 = луз

int main()
{

    int N, count = 0, maxCount = 0, a;
    printf("Put N value: ");
    scanf("%d", &N);
    int array[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a);
        array[i] = a;
    }
    for (int i = 0; i < N; i++)
    {
        if (array[i] == 1)
        {
            count++;
        }
        else
        {
            if (count >= maxCount)
            {
                maxCount = count;
            }
            count = 0;
        }
    }
    if (count >= maxCount)
    {
        printf("Winstreak: %d", count);
    }
    else
    {
        printf("Winstreak: %d", maxCount);
    }
    return 0;
}
