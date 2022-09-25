// #include <stdio.h>

// int main()
// {

//     int countAll = 0, a, b, countA, countB;

//     printf("Put value for a: ");
//     scanf_s("%d", &a);
//     printf("Put value for b: ");
//     scanf_s("%d", &b);

//     while (b > 0 && a > 0)
//     {
//         countA = 0;
//         countB = 0;
//         if (a > b)
//         {
//             a -= b;
//             countAll++;
//             countA++;
//             printf("Square %d x %d - %d\n", b, b, countA);
//         }
//         else
//         {
//             b -= a;
//             countAll++;
//             countB++;
//             printf("Square %d x %d - %d\n", a, a, countB);
//         }
//     }
//     printf("Number of squares in rectanlge: %d", countAll);
//     return 0;
// }

// #include <stdio.h>

// int main()
// {

//     int a, b;
//     //ввод значений с проверкой
//     do
//     {
//         printf("Put the value a: ");
//         scanf("%d", &a);
//         printf("Put the value for b: ");
//         scanf("%d", &b);
//         if (a <= 0 || b <= 0)
//         {
//             printf("Put the correct values\n");
//             printf("_____________________________\n");
//         }
//     } while (a <= 0 || b <= 0);
//     if (a > 0 && b > 0)
//     {
//         printf("%d\n", a);
//         printf("%d", b);
//     }

//     return 0;
// }

// #include <stdio.h>

// int main()
// {

//     int a, b;

//     printf("Put the value for a: ");
//     scanf("%d", &a);
//     printf("Put the value for b: ");
//     scanf("%d", &b);

//     while (a <= 0 || b <= 0)
//     {
//         printf("Enter the correct values\n");

//         printf("Put value for a: ");
//         scanf_s("%d", &a);
//         printf("Put value for b: ");
//         scanf_s("%d", &b);
//     }

//     if (a > 0 && b > 0)
//     {
//         printf("a value: %d\n", a);
//         printf("b value: %d", b);
//     }
// }
// // }

// #include <stdio.h>

// int main()
// {

//     int a, b, countAll = 0, countA, countB;

//     printf("Put value for a: ");
//     scanf_s("%d", &a);
//     printf("Put value for b: ");
//     scanf_s("%d", &b);

//     while (b > 0 && a > 0)
//     {
//         countA = 0;
//         countB = 0;
//         if (a > b)
//         {
//             a -= b;
//             countAll++;
//             countA++;
//             printf("Square % d x %d - %d\n", b, b, countA);
//         }
//         else
//         {
//             b -= a;
//             countAll++;
//             countB++;
//             printf("Square % d x %d - %d\n", a, a, countB);
//         }
//     }

//     printf("Number of squares in rectanlge: %d", countAll);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// int max(int a, int b)
// {
//     if (a > b)
//     {
//         return a;
//     }
//     else
//         return b;
// }

// int main()
// {

//     int a, b, maximum, countAll = 0, countI = 0;

//     printf("Put value for a: ");
//     scanf("%d", &a);
//     printf("Put value for b: ");
//     scanf("%d", &b);

//     int array[max(a, b)][1];

// for (int i = 0; i < sizeof(array) / sizeof(int); i++) {
//   for (int j = 0; j < sizeof(array) / sizeof(int); j++) {
//     array[i][j] = 0;
//   }
//     while (a <= 0 || b <= 0)
//     {
//         printf("Enter the correct values\n");

//         printf("Put value for a: ");
//         scanf("%d", &a);
//         printf("Put value for b: ");
//         scanf("%d", &b);
//     }
//     if (a > 0 && b > 0)
//     {
//         while (b > 0 && a > 0)
//         {

//             if (a > b)
//             {
//                 a -= b;
//                 countAll++;
//                 printf("Square % d x %d\n", b, b);
//             }
//             else
//             {
//                 b -= a;
//                 countAll++;
//                 printf("Square % d x %d\n", a, a);
//             }
//         }
//         printf("Number of squares in rectanlge: %d", countAll);
//         return 0;
//     }
// }
