#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Application_Layer/Admin_Module/admin.h"
#include "Application_Layer/Authentication_Module/authentication.h"
#include "Application_Layer/User_Module/student.h"
#include "Data_Access_Layer/File_Access_Module/file_access.h"
#include "Data_Access_Layer/Data_Management_Module/data_management.h"
#include "User_Interface_Layer/IO_Module/input.h"
#include "User_Interface_Layer/Menu_Module/menu.h"

int main()
{
    int option=select_mode();
    int choice;
    int another_choice=1;

    if(option==1)
    {
       if (Authenticate_Admin())
       {
          do
          {
             choice=admin_menu();
             switch(choice)
             {
                case 1:ala_add_record();
                       break;
                case 2:ala_remove_record();
                    break;
                case 3:ala_view_record();
                       break;
                case 4:ala_view_all_record();
                       break;
                case 5:ala_edit_admin_password();
                       break;
                case 6:ala_edit_student_grade();
                       break;
                default:printf("Invalid Choice\n");
                        break;
               }
               printf("Enter any number to do another operation and 0 to exist : ");
               scanf("%d",&another_choice);
           }
               while(another_choice);
       }

    }
    else if(option==2)
    {
        int i=Authenticate_Student();
        if (i!=-1)
        {
           do{
                choice=user_menu();
                switch(choice)
                {
                   case 1 :view_student_record(i);
                           break;
                   case 2 :edit_student_pass(i);
                           break;
                   case 3 :edit_student_name(i);
                           break;
                   default:printf("Invalid Choice\n");
                           break;
                }
                   printf("Enter any number to do another operation and 0 to exist : ");
                   scanf("%d",&another_choice);
             }
                   while(another_choice);
        }
    }
    else
    {
        printf("invalid choice\n");
    }

    return 0;
}
