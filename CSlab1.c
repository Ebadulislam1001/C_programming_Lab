// Program 1
// Write a menu driven program using functions to perform int following operations on two matrices:
// 1. Addition
// 2. Subtraction
// 3. Multiplication
// 4. Exit
// take matrix size from user.

#include <stdio.h>

void add(int a[10][10], int R1, int C1, int b[10][10], int R2, int C2)
{
    if (R1 != R2 || C1 != C2)
    {
        printf("\nThe two given matrices cannot be added\n");
        return;
    }
    int c[10][10];
    for (int i = 0; i < R1; i++)
    {
        for (int j = 0; j < C1; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    printf("\n===After Addition===\n");
    for (int i = 0; i < R1; i++)
    {
        for (int j = 0; j < C1; j++)
        {
            printf(" %d ", c[i][j]);
        }
        printf("\n");
    }
}

void sub(int a[10][10], int R1, int C1, int b[10][10], int R2, int C2)
{
    if (R1 != R2 || C1 != C2)
    {
        printf("\nThe two given matrices cannot be subtracted\n");
        return;
    }
    int c[10][10];
    for (int i = 0; i < R1; i++)
    {
        for (int j = 0; j < C1; j++)
        {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
    printf("\n===After Subtraction===\n");
    for (int i = 0; i < R1; i++)
    {
        for (int j = 0; j < C1; j++)
        {
            printf(" %d ", c[i][j]);
        }
        printf("\n");
    }
}

void mul(int a[10][10], int R1, int C1, int b[10][10], int R2, int C2)
{
    if (C1 != R2)
    {
        printf("\nThe two given matrices cannot be multiplied\n");
        return;
    }
    int c[10][10];
    for (int i = 0; i < R1; i++)
    {
        for (int j = 0; j < C1; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < R2; k++)
            {
                c[i][j] += (a[i][k] * b[k][j]);
            }
        }
    }
    printf("\n===After Multiplication===\n");
    for (int i = 0; i < R1; i++)
    {
        for (int j = 0; j < C2; j++)
        {
            printf(" %d ", c[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int a[10][10], b[10][10];
    int R1, C1, R2, C2, choice;
    printf("\nEnter the no. of rows in first matrix: ");
    scanf("%d", &R1);
    printf("\nEnter the no. of columns in first matrix: ");
    scanf("%d", &C1);
    printf("\nEnter the elements of first matrix\n");
    for (int i = 0; i < R1; i++)
    {
        for (int j = 0; j < C1; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("\nEnter the no. of rows in second matrix: ");
    scanf("%d", &R2);
    printf("\nEnter the no. of columns in second matrix: ");
    scanf("%d", &C2);
    printf("\nEnter the elements of second matrix\n");
    for (int i = 0; i < R2; i++)
    {
        for (int j = 0; j < C2; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    while (1)
    {
        printf("\n1. Addition \n2. Subtraction \n3. Multiplication ");
        printf("\n0. Exit \nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add(a, R1, C1, b, R2, C2);
            break;
        case 2:
            sub(a, R1, C1, b, R2, C2);
            break;
        case 3:
            mul(a, R1, C1, b, R2, C2);
            break;
        case 0:
            printf("\nProgram made by\nEbadul islam Farooqi\n20BCS019");
            return 0;
        default:
            printf("\nEnter a valid option [0-3]");
            break;
        }
    }
}