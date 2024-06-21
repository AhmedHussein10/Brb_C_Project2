#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Application/Admin/admin.h"
#include "Application/Authentication/authentication.h"
#include "Application/User/student.h"
#include "Data_Access/File_Access/file_access.h"
#include "Data_Access/Data_Management/data_management.h"
#include "User_Interface/IO/input.h"
#include "User_Interface/Menu/menu.h"

int main()
{
    int exit=0;
    do
    {
       int option=select_mode();
       int choice;

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
                   case 0:exit=-1;
                          break;
                   default:printf("Invalid Choice\n");
                }
             }
               while(choice!=0);
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
                     case 0:exit= -1;
                             break;
                     default:printf("Invalid Choice\n");
                }
             }
                   while(choice!=0);
        }
    }
        else if (option==0)
        {
           return 0;
        }
        else
        {
           printf("invalid choice\n");
        }
      }
      while (exit==-1);

      return 0;
}
