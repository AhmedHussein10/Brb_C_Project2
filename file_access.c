
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "file_access.h"
record students[100];
int ReadDataFromFile() {
    int records = 0;
    FILE *read;
    read = fopen("student_data.csv", "r");
    if (read == NULL) {
        printf("Error opening file\n");
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
void WriteAdminPassword(char *paass)
{

    FILE *admin_pass=fopen("admin_password.csv","w");
    if(admin_pass==NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    fprintf(admin_pass,"%s\n",paass);
    fclose(admin_pass);
}
char* ReadAdminPassword()
{
    static char pass[50];
    FILE *read_pass=fopen("admin_password.csv","r");

    if(read_pass==NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    fscanf(read_pass,"%49[^,]\n",pass);
    fclose(read_pass);
    return pass;
}

