#include<stdio.h>
#include "menu.h"

int select_mode(void)       // determin if the user will go admin mode or user mode
{
    int choice;
    printf("\t\t---------Welcome to our Student Record system---------\n");
    printf("\t\t\t _____________________________\n");
    printf("\t\t\t|                             |\n");
    printf("\t\t\t|       1. Admin Mode         |\n");
    printf("\t\t\t|                             |\n");
    printf("\t\t\t|       2. User Mode          |\n");
    printf("\t\t\t|                             |\n");
    printf("\t\t\t|_____________________________|\n");
    printf("\nPlease select mode : ");
    scanf("%d",&choice);
    return choice;
}

int admin_menu(void)    //show admin Privileges
{
    int choice;
    printf("\t\t\t ______________________________________\n");
    printf("\t\t\t|                                      |\n");
    printf("\t\t\t|       1. Add student record          |\n");
    printf("\t\t\t|                                      |\n");
    printf("\t\t\t|       2. Remove student record       |\n");
    printf("\t\t\t|                                      |\n");
    printf("\t\t\t|       3. View student record         |\n");
    printf("\t\t\t|                                      |\n");
    printf("\t\t\t|       4. View all records            |\n");
    printf("\t\t\t|                                      |\n");
    printf("\t\t\t|       5. Edit admin password         |\n");
    printf("\t\t\t|                                      |\n");
    printf("\t\t\t|       6. Edit student grade          |\n");
    printf("\t\t\t|                                      |\n");
    printf("\t\t\t|______________________________________|\n");
    printf("\n\nPlease Select Your Choice : ");
    scanf("%d",&choice);
    return choice;
}

int user_menu(void)    //show user Privileges
{
    int choice;
    printf("\t\t\t ______________________________________\n");
    printf("\t\t\t|                                      |\n");
    printf("\t\t\t|       1. View Your Record            |\n");
    printf("\t\t\t|                                      |\n");
    printf("\t\t\t|       2. Edit Your Password          |\n");
    printf("\t\t\t|                                      |\n");
    printf("\t\t\t|       3. Edit Your Name              |\n");
    printf("\t\t\t|                                      |\n");
    printf("\t\t\t|______________________________________|\n");
    printf("\n\nPlease Select Your Choice : ");
    scanf("%d",&choice);
    return choice;
}

