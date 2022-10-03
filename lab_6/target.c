#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int R, x, y, countHit = 0, tryCount = 0;
    int repeat = 1;

    while (repeat == 1)
    {

        do
        {
            printf("Enter the radius: ");
            scanf("%d", &R);
        } while (R < 1);

        for (int i = 0; i < 5; i++)
        {
            printf("Enter the X and Y positions: ");
            scanf("%d %d", &x, &y);

            if ((pow(x, 2) + pow(y, 2)) <= pow(R, 2))
            {
                printf("You got it!\n");
                countHit++;
            }
            else
                printf("You missed!\n");
        }
        printf("You've been hit %d time(s). Try again? Yes - 1; No - 0\n", countHit++);
        printf("Answer: ");
        scanf("%d", &repeat);

        if (repeat == 0)
        {
            printf("Thanks for game!");
        }
    }
}
