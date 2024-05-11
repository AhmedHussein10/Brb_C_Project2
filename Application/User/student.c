#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "../../User_Interface/IO/input.h"
#include "../Authentication/authentication.h"
#include "../../Data_Access/File_Access/file_access.h"
#include "../../Data_Access/Data_Management/data_management.h"
void view_student_record(int i)
{

   printf(" Name :     %s\n ID :       %d\n Age :      %d\n Gender :   %s\n Password : %s\n Grade :    %d\n",students[i].name,students[i].id,students[i].age
                                                                                                            ,students[i].gender,students[i].pass,students[i].grade);
}

void edit_student_pass(int i)
{
   int num_records=ReadDataFromFile();
   char* new_pass=(char*)malloc(50);

   printf("Enter New Pass : ");
   scanf("%s",new_pass);
   strcpy(students[i].pass,new_pass);
   editfunction(num_records);
   printf("Password updated successfully.\n");

   free(new_pass);
   new_pass=NULL;
}

// Function to edit student's name
void edit_student_name(int i)
{
   int num_records=ReadDataFromFile();
   char* new_name=(char*)malloc(50);

   fflush(stdin);
   printf("Enter New name : ");
   gets  (new_name);
   strcpy(students[i].name,new_name);
   editfunction(num_records);
   printf("Name updated successfully.\n");

   free(new_name);
   new_name=NULL;
}
