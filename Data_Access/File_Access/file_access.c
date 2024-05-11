
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_access.h"
#include "../../User_Interface/IO/input.h"
int ReadDataFromFile() {
    int records = 0;
    FILE *read;
    read = fopen("student_data.csv", "r");
    if (read == NULL) {
        printf("No records found\n");
        exit(1);
    }


    while (fscanf(read, "%49[^,],%d,%d,%49[^,],%49[^,],%d\n", students[records].name, &students[records].id, &students[records].age, students[records].gender, students[records].pass, &students[records].grade) != EOF) {

        records++;
    }

    fclose(read);
    return records;
}

void WriteDataToFile(int students_number)
{
    FILE *write;
    write=fopen("student_data.csv","a");
    if(write==NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    for(int i=0;i<students_number;i++)
    {

        fprintf(write,"%s,%d,%d,%s,%s,%d\n",students[i].name,students[i].id,students[i].age,students[i].gender,students[i].pass,students[i].grade);
    }
    fclose(write);

}
void WriteAdminPassword()
{

    FILE *write_pass=fopen("admin_password.csv","w");
    if(write_pass==NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    fprintf(write_pass,"%s\n",Admin_Pass);
    fclose(write_pass);
}
void ReadAdminPassword()
{
    FILE *read_pass=fopen("admin_password.csv","r");

    fscanf(read_pass,"%s\n",Admin_Pass);

    fclose(read_pass);
}

