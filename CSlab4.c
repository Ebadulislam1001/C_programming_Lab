// Program 4
// Write a program to manage and display student records
// 1. percentage of students
// 2. highest marks holder in each subject
// 3. student with highest percentage

#include <stdio.h>

struct student
{
    int roll;
    int sub[3];
    float percentage;
} s[10];

void display(int i)
{
    printf("\n\tRoll no: %d", s[i].roll);
    printf("\n\tMarks 1: %d", s[i].sub[0]);
    printf("\n\tMarks 2: %d", s[i].sub[1]);
    printf("\n\tMarks 3: %d", s[i].sub[2]);
    printf("\n\tPercentage: %.02f\n", s[i].percentage);
}

int main()
{
    int n;
    printf("\nEnter no. of student: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int total = 0;
        printf("\nEnter data of student %d\n", i + 1);
        printf("Roll no: ");
        scanf("%d", &s[i].roll);
        for (int j = 0; j < 3; j++)
        {
            printf("marks in subject %d : ", j + 1);
            scanf("%d", &s[i].sub[j]);
            total = total + s[i].sub[j];
        }
        s[i].percentage = total / 3.0;
    }
    while (1)
    {
        int choice;
        printf("\n1. percentage of students\n2. highest marks holder in each subject");
        printf("\n3. student with highest percentage\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                display(i);
            }
            break;
        case 2:
            for (int j = 0; j < 3; j++)
            {
                int max = 0;
                for (int i = 0; i < n; i++)
                {
                    if (s[i].sub[j] > s[max].sub[j])
                        max = i;
                }
                printf("\nHighest mark holder in subject %d is:", j + 1);
                display(max);
            }
            break;
        case 3:
            int max = 0;
            for (int i = 0; i < n; i++)
            {
                if (s[i].percentage > s[max].percentage)
                    max = i;
            }
            printf("\nStudent with the highest percentage is:");
            display(max);
        case 4:
            printf("\nProgram made by\nEbadul islam Farooqi\n20BCS019");
            return 0;
        default:
            printf("\nEnter a valid option (1-4)");
            break;
        }
    }
}