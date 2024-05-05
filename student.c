#include "student.h"
// Function to edit student's password
void edit_student_pass(int i)    // take index of student as a parameter i
{
    char new_pass[8];
    printf("Enter New Pass : ");
    scanf("%s",new_pass);       // Input new password
    strcpy(students[i].Pass,new_pass);
    printf("Password updated successfully.\n");
}

// Function to edit student's name
void edit_student_name(int i)    //take index of student as a parameter i
{
    char new_name[20];
    printf("Enter New Name : ");
    scanf("%s",new_name);          // Input new name
    strcpy(students[i].name,new_name);
    printf("Name updated successfully.\n");
}
void view_student_record(int i)
{
           // Display student information
    printf("\t\t\tName        : %s\n",students[i].name);
    printf("\t\t\tGender      : %s\n",students[i].Gender);
    printf("\t\t\tAge         : %c\n",students[i].Age);
    printf("\t\t\tTotal Grade : %f\n",students[i].TotalGrade);
    printf("\n");
}
