#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "student.h"


int main()
{
    int option=select_mode();
    int choice;
    int another_choice=1;
    if(option==1)
    {
        do
        {
            choice=admin_menu();
            switch(choice)
            {
            case 1:
                //1. Add student record
                break;
            case 2:
                //2. Remove student record
                break;
            case 3:
                //3. View student record
                break;
            case 4:
                //4. View all records
                break;
            case 5:
                //5. Edit admin password
                break;
            case 6:
                //6. Edit student grade
                break;
            default :
                printf("Invalid Choice\n");
                break;
            }
            printf("press 1 to continue and 0 to exist : ");
            scanf("%d",&another_choice);
        }while(another_choice);


    }
    else if(option==2)
    {
        do{
            choice=user_menu();
            switch(choice)
            {
            case 1:
                  //1. View Your Record
                break;
            case 2:
                 //2. Edit Your Password
                break;
            case 3:
                //3. Edit Your Name
                break;
            default:
                printf("Invalid Choice\n");
                break;
            }
            printf("press 1 to do another operation and 0 to exist : ");
            scanf("%d",&another_choice);
        }while(another_choice);
    }
    else
    {
        printf("invalid choice\n");
    }

    return 0;
}
