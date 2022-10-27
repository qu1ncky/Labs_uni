#include <stdio.h>

int linSort(int array[], int size)
{
    int min, temp; // для поиска минимального элемента и для обмена
    for (int i = 0; i < size - 1; i++)
    {
        min = i; // запоминаем индекс текущего элемента
        // ищем минимальный элемент чтобы поместить на место i-ого
        for (int j = i + 1; j < size; j++) // для остальных элементов после i-ого
        {
            if (array[j] < array[min]) // если элемент меньше минимального,
                min = j;               // запоминаем его индекс в min
        }
        temp = array[i]; // меняем местами i-ый и минимальный элементы
        array[i] = array[min];
        array[min] = temp;
    }
}

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

int main()
{
    int size, a;
    printf("Eneter the size of array: ");
    scanf("%d", &size);

    int array_lin[size];
    int array_buble[size];
    int array_inser[size];

    printf("Enetr the vlaue(s) for array: ");

    //МАССИВ ДЛЯ ЛИНЕЙНОЙ
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a);
        array_lin[i] = a;
    }

    //МАССИВ ДЛЯ ПУЗЫРЬКА
    for (int i = 0; i < size; i++)
    {
        array_buble[i] = array_lin[i];
    }

    //МАССИВ ДЛЯ ВСТАВКИ
    for (int i = 0; i < size; i++)
    {
        array_inser[i] = array_lin[i];
    }

    //Вызов линейной сортировки
    linSort(array_lin, size);
    printf("Linear sort: ");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", array_lin[i]);
    }

    //Вызов  сортировки пузырьком
    bubleSort(array_buble, size);
    printf("  Buble sort: ");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", array_buble[i]);
    }

    //Вызов  сортировки вставкой
    inseretionSort(array_inser, size);
    printf("  Inseretion sort: ");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", array_inser[i]);
    }

    return 0;
}