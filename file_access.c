#include <stdio.h>
#include <stdlib.h>


void WriteDataToFile (void)
{
   FILE *file=NULL;
   file=fopen("student_data.csv","w");

   if (file!=NULL)
   {
      for (int i=0;i<Students_Number;i++)
      {
         fprintf (file,"%s %f %s %d %s %s %d    %s \n",students[i].Name,students[i].TotalGrade
                                                      ,students[i].ID,students[i].Age,students[i].Gender
                                                      ,students[i].Pass,Students_Number,Admin_Pass);
      }
   }


   else
   {
      printf ("Error opening file\n");
   }

   fclose(file);
}

void ReadDataFromFile (void)
{
   int i=0;
   FILE *file;
   file=fopen("student_data.csv","r");

   while (fscanf(file,"%s %f %s %d %s %s %d    %s \n",&students[i].Name,&students[i].TotalGrade
                                                     ,&students[i].ID,&students[i].Age,&students[i].Gender
                                                     ,&students[i].Pass,&Students_Number,&Admin_Pass)!=EOF)

   {
      i++;
   }

   fclose(file);
}
