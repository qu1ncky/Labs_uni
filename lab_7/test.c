#include <stdio.h>
#include <stdlib.h>

#define N 3

int main()
{
    int mod3[N] = {0};

    for (int i = 0; i < N; i++)
    {
        if (mod3[i] == 0)
        {
            mod3[i] = -1;
        }
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d", mod3[i]);
    }
    return 0;
}