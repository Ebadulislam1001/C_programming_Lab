// Program 5
// Write a program to print a given 2-D matrix in a spiral order

#include <stdio.h>

void printSpiral(int matrix[9][9], int R, int C)
{
    int i = 0, j = 0;
    printf("\n");
    while (1)
    {
        // going right
        for (int k = 0; k < C; k++)
        {
            printf(" %d", matrix[i][j]);
            j = j + 1;
        }
        i = i + 1;
        j = j - 1;
        R--;
        if (R == 0)
            break;
        // going down
        for (int k = 0; k < R; k++)
        {
            printf(" %d", matrix[i][j]);
            i = i + 1;
        }
        i = i - 1;
        j = j - 1;
        C--;
        if (C == 0)
            break;
        // going left
        for (int k = 0; k < C; k++)
        {
            printf(" %d", matrix[i][j]);
            j = j - 1;
        }
        i = i - 1;
        j = j + 1;
        R--;
        if (R == 0)
            break;
        // going up
        for (int k = 0; k < R; k++)
        {
            printf(" %d", matrix[i][j]);
            i = i - 1;
        }
        i = i + 1;
        j = j + 1;
        C--;
        if (C == 0)
            break;
    }
}

int main()
{
    int arr[9][9];
    int r, c;
    printf("\nEnter the size of array\n");
    printf("Rows = ");
    scanf("%d", &r);
    printf("Cols = ");
    scanf("%d", &c);
    printf("\nEnter the elements:\n");
    //  Array input
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    //  Array output
    for (int i = 0; i < r; i++)
    {
        printf("\n");
        for (int j = 0; j < c; j++)
        {
            printf("%d ", arr[i][j]);
        }
    }
    printf("\n");
    printSpiral(arr, r, c);
    printf("\n\nProgram made by\nEbadul islam Farooqi\n20BCS019");
    return 0;
}
