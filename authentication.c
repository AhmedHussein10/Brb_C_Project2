#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Check_ID (void)
{
   char id [20];
   printf ("Enter student's ID : ");
   scanf  ("%s",&id);
   for (int i=0;i<Students_Number;i++)
   {
      if (strcmp(id,students[i].ID)==0)
      {
         return i;
      }
   }
   return -1;
}


int Authenticate_Admin (void)
{
   char Pass [20];
   for (int i=0;i<3;i++)
   {
      printf ("Enter admin's password : ");
      scanf  ("%s",&Pass);
      if (strcmp(Pass,Admin_Pass)==0)
      {
         printf ("Welcome admin\n");
         return 1;
      }
      else
      {
         printf ("Wrong password\n");
      }
   }

   printf ("No more attempts\n");
   return 0;
}

int Authenticate_Student (void)
{
   int i=Check_ID ();
   if (i!=-1)
   {
      char Pass [20];
      for (int n=0;n<3;n++)
      {
         printf ("Enter student's password : ");
         scanf  ("%s",&Pass);
         if (strcmp(Pass,students[i].Pass)==0)
         {
            printf ("Welcome %s",students[i].Name);
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
