#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000

// ЛИНЕЙНЫЙ ПОИСК
int linear_search(int array[], int N)
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

// БИНАРНЫЙ ПОИСК
int binary_search(int array[], int N)
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

// БАРЬЕРНЫЙ ПОИСК
int barier_search(int array[], int N)
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

// ЛИНЕЙНАЯ СОРТИРОВКА
int linear_sort(int array[], int size)
{
    int count = 0;
    int min, temp;

    for (int i = 0; i < size - 1; i++)
    {
        min = i;
        count++;
        for (int j = i + 1; j < size; j++)
        {
            count++;

            if (array[j] < array[min])
            {
                min = j;
                count += 2;
            }
        }
        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
        count += 6;
    }
    return count;
}

// СОРТИРОВКА ПУЗЫРЬКОМ
int buble_sort(int array[], int size)
{
    int buble_iteration = 0;
    int temp;
    int count = 0;

    for (int i = 0; i < size - 1; i++)
    {

        for (int j = 0; j < size - i - 1; j++)
        {

            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                buble_iteration += 3;
            }
            else
            {
                count++;
            }
        }

        if (count >= size - i - 1)
        {
            break;
        }

        count = 0;
    }

    return buble_iteration;
}

// СОРТИРОВКА ВСТАВКОЙ
int insertion_sort(int array[], int size)
{
    int count = 0;

    for (int i = 1; i < size; i++)
    {
        int index = i;
        while (index > 0 && array[index - 1] > array[index])
        {
            int temp = array[index - 1];
            array[index - 1] = array[index];
            array[index] = temp;
            index--;
            count += 2;
        }
    }
    return count;
}

// ВЫВОД МЕНЮ
int user_menu()
{
    printf("                    USER MENU\n");
    printf("                    ___________  \n");
    printf("\n");
    printf("\n");
    printf("Below is a list of commands that you can call\n");
    printf("Enter the number of the function you want to run\n");
    printf("\n");
    printf("\n");
    printf("                    FUNCTIONS\n");
    printf("                    _________\n");
    printf("1.Creating array\n");
    printf("2.Output of the current array\n");
    printf("3.Linear search in current array \n");
    printf("4.Binary search in current array (work only with sorted array)\n");
    printf("5.Barier search in current array\n");
    printf("6.Linear sorting\n");
    printf("7.Bubble sorting\n");
    printf("8.Insertion sorting\n");
    printf("9.Complexity of all using sorts\n");
    printf("0.EXIT\n");
    return 0;
}

int main()
{
    srand(time(NULL));
    double time_linear = 0.0, time_buble = 0.0, time_insertion = 0.0;
    int insertion_iteration = 0, buble_iteration = 0, linear_iteration = 0;
    bool array_exist = false;
    bool array_sorted = false;
    int answer, size = 0, a;
    int array_main[MAX], array_copy_1[MAX], array_copy_2[MAX], array_copy_3[MAX];

    do
    {
        user_menu();
        printf("\n Choose a function: ");
        scanf("%d", &answer);
        switch (answer)
        {
        case 1:
            do
            {
                printf("Enter the size of array: \n");
                scanf("%d", &size);
                if (size < 1)
                {
                    printf("Is not correct value for size of array. Try agagin.\n");
                    array_exist = false;
                }
                if ((size > 0) && (size <= 20))
                {
                    printf("Array sucsesfully create! Enter your values:\n");
                    for (int i = 0; i < size; i++)
                    {
                        scanf("%d", &a);
                        array_main[i] = a;
                        array_copy_1[i] = a;
                        array_copy_2[i] = a;
                        array_copy_3[i] = a;
                    }
                    array_exist = true;
                    array_sorted = false;
                    insertion_iteration = 0;
                    buble_iteration = 0;
                    linear_iteration = 0;
                    time_linear = 0.0;
                    time_buble = 0.0;
                    time_insertion = 0.0;
                }
                printf("\n");
                if (size > 20)
                {
                    printf(
                        "Array sucsesfully create! It was filled with random values\n");
                    for (int i = 0; i < size; i++)
                    {
                        array_main[i] = rand() % 1000;
                        array_copy_1[i] = rand() % 1000;
                        array_copy_2[i] = rand() % 1000;
                        array_copy_3[i] = rand() % 1000;
                    }
                    array_exist = true;
                    array_sorted = false;
                    insertion_iteration = 0;
                    buble_iteration = 0;
                    linear_iteration = 0;
                    time_linear = 0.0;
                    time_buble = 0.0;
                    time_insertion = 0.0;
                }
                printf("\n");

            } while (size < 1);
            break;

        case 2:
            if (array_exist == false)
            {
                printf("Array doesn't exist.\n");
            }
            if (array_exist == true)
            {
                printf("Current array is: ");
                for (int i = 0; i < size; i++)
                {
                    printf("%d ", array_main[i]);
                }
                printf("\n");
                printf("\n");
            }

            break;

        case 3:
            if (array_exist == true)
            {
                linear_search(array_main, size);
            }
            else
            {
                printf("Array doesn't exist\n");
            }
            break;
        case 4:
            if ((array_exist == true) && (array_sorted == true))
            {
                binary_search(array_main, size);
            }
            else
            {
                printf("Array doesn't exist or array doesn't sorted.\n");
            }
            break;
        case 5:
            if (array_exist == true)
            {
                barier_search(array_main, size);
            }
            else
            {
                printf("Array doesn't exist.\n");
            }
            break;
        case 6:
            if (array_exist == true)
            {
                linear_sort(array_main, size);

                clock_t begin_linear = clock();
                linear_iteration = linear_sort(array_copy_1, size);
                clock_t end_linear = clock();
                time_linear += (double)(end_linear - begin_linear) / CLOCKS_PER_SEC;

                array_sorted = true;
                printf("Sorting was completed successfully!\n");
            }
            else
            {
                printf("Array doesn't exist.\n");
            }
            break;
        case 7:
            if (array_exist == true)
            {
                buble_sort(array_main, size);

                clock_t begin_buble = clock();
                buble_iteration = buble_sort(array_copy_2, size);
                clock_t end_buble = clock();
                time_buble += (double)(end_buble - begin_buble) / CLOCKS_PER_SEC;

                array_sorted = true;
                printf("Sorting was completed successfully!\n");
            }
            else
            {
                printf("Array doesn't exist.\n");
            }
            break;
        case 8:
            if (array_exist == true)
            {
                insertion_sort(array_main, size);

                clock_t begin_insertion = clock();
                insertion_iteration = insertion_sort(array_copy_3, size);
                clock_t end_insertion = clock();
                time_insertion +=
                    (double)(end_insertion - begin_insertion) / CLOCKS_PER_SEC;
                array_sorted = true;
                printf("Sorting was completed successfully!\n");
            }
            else
            {
                printf("Array doesn't exist.\n");
            }
            break;
        case 9:
            if (array_exist == true)
            {
                printf("\n");
                printf("\n");
                printf("COMPLEXITY OF SORTING\n");
                printf("_________________\n");

                printf("Linear sort info:\n");
                printf("Iterations: %d \n", linear_iteration);
                printf("Time: %lf seconds\n", time_linear);
                printf("_________________\n");

                printf("Buble sort info:\n");
                printf("Iterations: %d \n", buble_iteration);
                printf("Time: %lf seconds\n", time_buble);
                printf("_________________\n");

                printf("Insertion sort info:\n");
                printf("Iterations: %d \n", insertion_iteration);
                printf("Time %lf seconds\n", time_insertion);
            }
        case 0:
            break;
        default:
            printf("Incorrect command input. Check the user menu.");
            printf("\n");
            printf("\n");
        }

    } while (answer != 0);
    if (answer == 0)
    {
        printf("_______________________________________\n");
        printf("Thanks for using programm!\n");
    }
}