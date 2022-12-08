#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <string.h>

#define MAX 100

int length(char *line)
{
    int res;
    for (res = 0; *line != '\0'; line++)
        res++;
    return res;
}
int compare(char *size1, char *size2)
{
    if (size1 < size2)
        return -1;
    else if (size1 > size2)
        return 1;
    else
        return 0;
}
int bigger(char *str1, char *str2)
{
    while (*str1 != '\0' || *str2 != '\0')
    {
        if (*str1 > *str2)
            return -1;
        else if (*str1 < *str2)
            return 1;
        else if (*str1 = *str2)
        {
            str1++;
            str2++;
        }
    }
    return 0;
}

main()
{

    int size1, size2, res;
    char str1[MAX];
    char str2[MAX];
    while (1)
    {
        printf("Enter the first string: ");
        gets(str1);
        printf("\n");
        printf("Enter the second string: ");
        gets(str2);
        size1 = length(str1);
        size2 = length(str2);
        printf("%d %d\n", size1, size2);
        res = bigger(str1, str2);
        if (res == -1)
            printf("The first line is larger than the second\n");
        else if (res == 1)
            printf("The second line is larger than the first\n");
        else
            printf("The lines are the same\n");
    }
    return 0;
}
