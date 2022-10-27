#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

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

//ЛИНЕЙНАЯ СОРТИРОВКА
int linSort(int array[], int size)
{
    int min, temp;
    for (int i = 0; i < size - 1; i++)
    {
        min = i;

        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[min])
                min = j;
        }
        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

//СОРТИРОВКА ПУЗЫРЬКОМ
int bubleSort(int array[], int size)
{
    int temp;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

//СОРТИРОВКА ВСТАВКОЙ
int inseretionSort(int array[], int size)
{
    int temp;

    for (int i = 0; i < size; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
            else
                break;
        }
    }
}

//ВЫВОД МЕНЮ
int user_menu(void)
{
    printf("                    USER MENU\n");
    printf("                    ___________  \n");
    printf("Below is a list of commands that you can call\n");
    printf("Enter the number of the function you want to run\n");
    printf("                    FUNCTIONS\n");
    printf("                    _________\n");
    printf("1.Creating array\n");
    printf("2.Output of the current array\n");
    printf("3.Linear array search\n");
    printf("4.Binary array search (work only with sorted array)\n");
    printf("5.Search with a barrier in the array\n");
    printf("6.Linear sorting\n");
    printf("7.Bubble sorting\n");
    printf("8.inseretion sort\n");
    printf("9.EXIT\n");
}

//СОЗДАНИЕ МАССИВА
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

    int array_1[size];
    int array_2[size];
    int array_3[size];

    if ((size <= 20) && (size > 0))
    {
        printf("Array sucsesfully create! Enter your values: ");
        for (int i = 0; i < size; i++)
        {
            scanf("%d", &a);
            array_1[i] = a;
            array_2[i] = a;
            array_3[i] = a;
        }
    }

    if (size > 20)
    {
        printf("Array sucsesfully create! It was filled with random values\n");
        for (int i = 0; i < size; i++)
        {
            array_1[i] = rand() % 1000;
            array_2[i] = rand() % 1000;
            array_3[i] = rand() % 1000;
        }
    }
}

int main()
{
    int answer;
    int array_1[6] = {3, 6, 8, 11, 65, 41};
    int array_2[6] = {65, 3, 17, 54, 635, -41};
    int array_3[6] = {0, -14, -64, 11, 655, 411};

    do
    {
        user_menu();

        printf("Choose function: ");
        scanf("%d", &answer);
        switch (answer)
        {
        case 1:
            linSort(array_1, 6);
            break;

        case 2:
            bubleSort(array_2, 6);
            break;

        case 3:
            inseretionSort(array_3, 6);
            break;
        }

        printf("Linear sort: ");
        for (int i = 0; i < 6; i++)
        {
            printf("%d ", array_1[i]);
        }

        printf("Bubble sort: ");
        for (int i = 0; i < 6; i++)
        {
            printf("%d ", array_2[i]);
        }

        printf("Inseretion sort: ");
        for (int i = 0; i < 6; i++)
        {
            printf("%d ", array_3[i]);
        }

    } while (answer != 9);

    return 0;
}