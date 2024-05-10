#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "authentication.h"
#include "../../User_Interface_Layer/IO_Module/input.h"
#include "../../Data_Access_Layer/File_Access_Module/file_access.h"

int Check_ID (void)
{
   int num=ReadDataFromFile();
   int id ;
   printf ("Enter student's ID : ");
   scanf  ("%d",&id);
   for (int i=0;i<num;i++)
   {
      if (id==students[i].id)
      {
         return i;
      }
   }
   return -1;
}


int Authenticate_Admin (void)
{
   ReadAdminPassword();
   int found=0;
   char *pass = (char*)malloc(20 * sizeof(char));
   for (int i=0;i<3;i++)
   {
      printf ("Enter admin's password : ");
      scanf  ("%s",pass);
      if (strcmp(pass,Admin_Pass)==0)
      {
         printf ("Welcome admin\n");
         found=1;
         break;
      }
      else
      {
         printf ("Wrong password\n");
      }
   }
   free(pass);
   pass=NULL;
   return found;
}

int Authenticate_Student (void)
{
   int i=Check_ID ();
   if (i!=-1)
   {
      char *pass = (char*)malloc(20 * sizeof(char));
      for (int n=0;n<3;n++)
      {
         printf ("Enter student's password : ");
         scanf  ("%s",pass);
         if (strcmp(pass,students[i].pass)==0)
         {
            printf ("Welcome %s\n",students[i].name);
            free(pass);
            pass=NULL;
            return i;
         }
         else
         {
            printf ("Wrong password\n");
         }
      }
    }
    else
    {
       printf ("Invalid ID\n");
    }
    return -1;
}
