#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

int main()
{
    char str[MAX];

    char mask[MAX];

    char array[MAX][MAX];

    int size = 0;

    printf("Enter the string: ");

    // ВВОД СТРОКИ
    fgets(str, MAX, stdin);

    for (int i = 0; i < strlen(str); i++)
    {

        if (str[i] == '\n')
        {

            str[i] = '\0';

            break;
        }
    }

    printf("Enter the mask: ");

    fgets(mask, MAX, stdin);

    for (int i = 0; i < strlen(mask); i++)
    {

        if (mask[i] == '\n')
        {

            mask[i] = '\0';

            break;
        }
    }

    for (int i = 0; str[i] != '\0'; i++)
    {

        int j, k;

        if (str[i] == ' ')
        {

            continue;
        }

        for (j = i, k = 0; str[j] != ' ' && str[j] != '\0'; j++, k++)
        {

            array[size][k] = str[j];
        }

        i = j;

        array[size][k] = '\0';

        size++;
    }

    printf("All words: %d\n", size);

    for (int i = 0; i < size; i++)
    {

        printf("%d word - %s\n", i + 1, array[i]);
    }

    printf("\n");

    for (int i = 0; i < size; i++)
    {

        bool flag = true;

        int k = 0;

        int m = 0;

        while (array[i][m] != '\0')
        {

            m += 1;
        }

        if (m == strlen(mask))
        {

            while (array[i][k] != '\0')
            {

                if (array[i][k] != mask[k] && mask[k] != '?')
                {

                    flag = false;
                }

                k += 1;
            }

            if (flag == true)
                printf("%d word in mask\n", i + 1);

            if (flag == false)
                printf("%d word NOT in mask\n", i + 1);
        }

        else
            printf("%d word NOT in mask\n", i + 1);
    }

    return 0;
}