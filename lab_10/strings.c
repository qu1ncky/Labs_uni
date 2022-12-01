#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[100];

    printf("\nEnter your stroke: ");
    fgets(str, 100, stdin);
    char sep[100] = " ,.!;";

    char *istr;

    istr = strtok(str, sep);

    printf("\nWords in stroke: ");
    while (istr != NULL)
    {
        printf("%s ", istr);
        istr = strtok(NULL, sep);
    }

    return 0;
}