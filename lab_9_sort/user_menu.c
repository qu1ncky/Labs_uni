#include <stdio.h>

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

int main()
{
    user_menu();

    return 0;
}