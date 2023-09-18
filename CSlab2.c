// Program 2
// Write a menu driven program to implement the following operations in an array:
// 1. Insert at the beginning
// 2. Insert at the end
// 3. Insert at a given index
// 4. Deletion at the beginning
// 5. Deletion at the end
// 6. Deletion at a given index
// 7. Exit.
// Take size of the array from user. Also, show the underflow and overflow conditions.

#include <stdio.h>

int insertAtBeg(int arr[], int size, int value)
{
    if (size == 50)
    {
        return 0;
    }
    else
    {
        for (int i = size; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = value;
        return 1;
    }
}

int insertAtEnd(int arr[], int size, int value)
{
    if (size == 50)
    {
        return 0;
    }
    else
    {
        arr[size] = value;
        return 1;
    }
}

int insertAtIndex(int arr[], int size, int value, int index)
{
    if (size == 50 || index < 0 || size < index)
    {
        return 0;
    }
    else
    {
        for (int i = size; i > index; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        return 1;
    }
}

int deleteAtBeg(int arr[], int size)
{
    if (size == 0)
    {
        return 0;
    }
    else
    {
        for (int i = 1; i < size; i++)
        {
            arr[i - 1] = arr[i];
        }
        return 1;
    }
}

int deleteAtEnd(int arr[], int size)
{
    if (size == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int deleteAtIndex(int arr[], int size, int index)
{
    if (size == 0 || index < 0 || size <= index)
    {
        return 0;
    }
    else
    {
        for (int i = index + 1; i < size; i++)
        {
            arr[i - 1] = arr[i];
        }
        return 1;
    }
}

void display(int a[], int size)
{
    printf("\nArray = ");
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", a[i]);
    }
}

int main()
{
    int a[50], size = 0, choice, index, value;

    while (1)
    {
        printf("\n1. Insertion at the beginning\n2. Insertion at the end\n3. Insertion at a given index");
        printf("\n4. Deletion at the beginning\n5. Deletion at the end\n6. Deletion at a given index");
        printf("\n0. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value : ");
            scanf("%d", &value);
            size += insertAtBeg(a, size, value);
            break;
        case 2:
            printf("Enter value : ");
            scanf("%d", &value);
            size += insertAtEnd(a, size, value);
            break;
        case 3:
            printf("Enter value : ");
            scanf("%d", &value);
            printf("Enter index : ");
            scanf("%d", &index);
            size += insertAtIndex(a, size, value, index);
            break;
        case 4:
            size -= deleteAtBeg(a, size);
            break;
        case 5:
            size -= deleteAtEnd(a, size);
            break;
        case 6:
            printf("Enter index : ");
            scanf("%d", &index);
            size -= deleteAtIndex(a, size, index);
            break;
        case 0:
            printf("\nProgram made by\nEbadul islam Farooqi\n20BCS019");
            return 0;
        default:
            printf("\nEnter a valid option [0-6]");
            break;
        }
        printf("\n===Updated Array===\n");
        display(a, size);
        printf("\n");
    }
}
