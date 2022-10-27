#include <stdio.h>
#include <stdbool.h>

//ЛИНЕЙНЫЙ ПОИСК
int lin_finder(int array[], int N)
{
    int key;
    int index = -1;

    printf("Enter the value for finding: ");
    scanf("%d", &key);

    for (int i = 0; i < N; i++)
    {
        if (array[i] == key)
        {
            index = i;
        }
    }

    if (index == -1)
    {
        return printf("No key value in array\n");
    }

    else
    {
        return printf("The index of key is: %d\n", index);
    }
}

//БИНАРНЫЙ ПОИСК
int bin_fidner(int array[], int N)
{
    int key;
    printf("Enter the value for finding: ");
    scanf("%d", &key);

    int mid, left = 0, right = (N - 1);
    bool flag = false;

    while ((left <= right) && (flag != true))
    {
        mid = (left + right) / 2;

        if (array[mid] == key)
        {
            flag = true;
        }
        if (array[mid] > key)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    if (flag == true)
    {
        return printf("The index of key is: %d\n", mid);
    }
    else
    {
        return printf("No key value in array\n");
    }
}

//БАРЬЕРНЫЙ ПОИСК
int bar_finder(int array[], int N)
{
    int key;
    printf("Enter the value for finding: ");
    scanf("%d", &key);

    int i = 0;
    array[N + 1] = key;
    while (array[i] != key)
    {
        i++;
    }
    if (i == N + 1)
    {
        return printf("No key value in array");
    }
    else
    {
        return printf("The index of a key is: %d", i);
    }
}

int main()
{
    int a, size;

    printf("Enter the size of array: ");
    scanf("%d", &size);

    int array[size];

    printf("Enter the values for array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a);
        array[i] = a;
    }

    //линейный поиск
    lin_finder(array, size);

    //бинарный поиск
    bin_fidner(array, size);

    //барьерный поиск
    bar_finder(array, size);

    return 0;
}