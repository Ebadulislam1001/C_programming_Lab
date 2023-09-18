// Program 6
// Write a menu driven program to perform the following operations on strings:
// 1. strlen
// 2. strrev
// 3. strcpy
// 4. strcmp
// 5. apppend
// 6. ispalindrome
// 7. searchsubstring
// 8. Exit

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int length(char a[100])
{
    int size = 0;
    for (int i = 0; a[i] != '\0'; i++)
    {
        size++;
    }
    return size;
}
void display(char a[100])
{
    for (int i = 0; a[i] != '\0'; i++)
    {
        printf("%c", a[i]);
    }
}
void reverse(char a[100], char b[100])
{
    int len = length(a);
    for (int i = 0, j = len - 1; i < len; i++, j--)
    {
        b[i] = a[j];
    }
}
void copy(char a[100], char b[100])
{
    for (int i = 0; a[i] != '\0'; i++)
    {
        b[i] = a[i];
    }
}
int compare(char a[100], char b[100])
{
    int len = length(a);
    int isSame;
    for (int i = 0; i < len; i++)
    {
        if (a[i] != b[i])
            return 0;
        if (a[i] == '\0' && b[i] == '\0')
            return 1;
    }
    return 0;
}
void append(char a[100], char b[100])
{
    printf("Enter the string to append:\n");
    gets(b);
    int len1 = length(a),
        len2 = length(b),
        len3 = len1 + len2;
    if (len3 > 100)
    {
        printf("\nOverflow ! strings can't be appended");
    }
    else
    {
        for (int i = len1 + 1; i <= len1 + len2; i++)
        {
            a[i] = b[i - len1 - 1];
        }
    }
}
int isPalindrome(char a[100])
{
    char b[100];
    reverse(a, b);
    return compare(a, b);
}
int searchSubstring(char a[100], char b[100])
{
    printf("Enter the substring to be searched:\n");
    gets(b);
    int i, j,
        len1 = length(a),
        len2 = length(b);
    for (i = 0; i <= len1 - len2; i++)
    {
        for (j = 0; j < len2; j++)
        {
            if (a[i + j] != b[j])
                break;
        }
        if (j == len2)
        {
            printf("substring found at index %d", i + 1);
            return i + 1;
        }
    }
    printf("substring not found");
    return 0;
}

int main()
{
    int i, j, choice, len;
    char a[100], b[100], c[100], gar;
    printf("\nEnter the main string:\n");
    gets(a);
    while (1)
    {
        printf("\n\n=====MENU=====");
        printf("\n1. String Length\n2. String Reverse");
        printf("\n3. String Copy\n4. String Compare");
        printf("\n5. String Append\n6. Palindrome Check");
        printf("\n7. Search Substring\n8. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        for (i = 0; i < 100; i++)
        {
            b[i] = ' ';
        }

        switch (choice)
        {
            //  string length
        case 1:
            scanf("%c", &gar);
            len = length(a);
            printf("\nstring length = %d", len);
            break;

            //  string reverse
        case 2:
            scanf("%c", &gar);
            reverse(a, b);
            printf("\nthe reversed string is:\n");
            display(b);
            break;

            //  string copy
        case 3:
            scanf("%c", &gar);
            copy(a, b);
            printf("\nthe copied string is:\n");
            display(b);
            break;

            // string compare
        case 4:
            scanf("%c", &gar);
            printf("Enter the string to compare:\n");
            gets(b);
            int isSame = compare(a, b);
            if (isSame)
            {
                printf("\nstrings ARE same\n");
            }
            else
            {
                printf("\nstrings ARE NOT same\n");
            }
            break;

            //  string append
        case 5:
            scanf("%c", &gar);
            append(a, b);
            printf("\nthe appended string is:\n");
            display(a);
            break;

            //  palindrome check
        case 6:
            scanf("%c", &gar);
            int palindrome = isPalindrome(a);
            if (palindrome == 1)
            {
                printf("\nThe string is a palindrome");
                return 1;
            }
            else
            {
                printf("\nThe string is not a palindrome");
                return 0;
            }
            break;

            //  search Substring
        case 7:
            scanf("%c", &gar);
            i = searchSubstring(a, b);
            break;

            // Exit
        case 8:
            printf("\nProgram made by\nEbadul islam Farooqi\n20BCS019");
            return 0;

            // default
        default:
            printf("\nEnter a valid option (1-8)");
            break;
        }
    }
}
