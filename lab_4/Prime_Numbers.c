#include <stdbool.h>
#include <stdio.h>

int main()
{

    int n, i = 2, reminder;

    do
    {
        printf("Put the value n: ");
        scanf("%d", &n);

        if (n <= 1)
        {
            if (n == 1)
            {
                printf("1 is uncorrect number\n");
                printf("_____________________________\n");
            }
            else if (n == 0)
            {
                printf("0 is uncorrect number\n");
                printf("_____________________________\n");
            }
            else if (n < 0)
            {
                reminder = n;
                printf("Put the correct values for n, %d is uncorrect, perhaps you meant %d\n", n, (-reminder));
                printf("_____________________________\n");
            }
        }
    } while (n <= 1);

    if (n > 1)
    {
        bool flag = true;
        while (i < n)
        {
            flag = true;
            int j = 2;
            while (j < i)
            {
                if (i % j == 0)
                {
                    flag = false;
                    break;
                }
                j++;
            }
            if (flag == true)
            {
                printf("%d\n", i);
            }
            i++;
        }
    }
    else
    {
        printf("Enter the correct values");
    }

    return 0;
}