#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int creating_array(void)
{
    int a, size;
    srand(time(NULL));

    do
    {
        printf("Enter the size of array: \n");
        scanf("%d", &size);
        if (size < 1)
        {
            printf("Is not correct value for size of array\n");
        }
    } while (size < 1);

    int array[size];

    if ((size <= 20) && (size > 0))
    {
        printf("Array sucsesfully create! Enter your values: ");
        for (int i = 0; i < size; i++)
        {
            scanf("%d", &a);
            array[i] = a;
        }
    }

    if (size > 20)
    {
        printf("Array sucsesfully create! it will be filled with random numbers.\n");
        for (int i = 0; i < size; i++)
        {
            array[i] = rand() % 1000;
        }
    }
}

int main()
{
    creating_array();

    return 0;
}
