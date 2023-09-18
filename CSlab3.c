// Program 3
// Write a menu driven program in C to convert
// 1. decimal to hexadec
// 2. hexadec to decimal

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char map[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int indexOf(char x)
{
    for (int i = 0; i < 16; i++)
    {
        if (map[i] == x)
            return i;
    }
    return -1;
}

char *decToHex(int dec)
{
    char *hex = (char *)calloc(20, sizeof(char));
    int len = 0;
    for (int i = 0; dec > 0; i++)
    {
        int rem = dec % 16;
        hex[i] = map[rem];
        dec = dec / 16;
        len += 1;
    }
    for (int i = 0, j = len - 1; i < j; i++, j--)
    {
        char temp = hex[i];
        hex[i] = hex[j];
        hex[j] = temp;
    }
    return hex;
}

int hexToDec(char *hex)
{
    int dec = 0;
    for (int i = 0; hex[i] != '\0'; i++)
    {
        int rem = indexOf(hex[i]);
        dec = dec * 16;
        dec = dec + rem;
    }
    return dec;
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n1. Decimal to hexadec\n2. Hexadec to decimal");
        printf("\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            int dec1;
            printf("Enter the decimal number: ");
            scanf("%d", &dec1);
            char *hex1 = decToHex(dec1);
            printf("hexadec equivalent = %s\n", hex1);
            break;
        case 2:
            char hex2[20];
            printf("Enter the hexadec number: ");
            scanf("%s", &hex2);
            int dec2 = hexToDec(hex2);
            printf("decimal equivalent = %d\n", dec2);
            break;
        case 3:
            printf("\nProgram made by\nEbadul islam Farooqi\n20BCS019");
            return 0;
        default:
            printf("\nEnter a valid option [1-3]");
            break;
        }
    }
    while (choice != 3)
        ;
}
