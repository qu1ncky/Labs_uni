#include <stdio.h>

int Summa(x)
{
    int sum = 0;
    while (x > 0)
    {
        sum = sum + (x % 10);
        x = x / 10;
    }
    return sum;
}

int main()
{
    int a, sum;
    printf("Enter the number: ");
    scanf("%d", &a);

    sum = Summa(a);
    printf("Sum of digits: %d", sum);
    return 0;
}