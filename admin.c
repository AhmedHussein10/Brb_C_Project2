#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "admin.h"
#include "file_access.h"
#include "data_management.h"
extern record students[100];
void ala_edit_student_grade()
{
    int eid;
    int local_ngrade;
    int local_found=0;
    printf("Enter ID of student to change hid grade:");
    scanf("%d",&eid);
    printf("Enter the new grade:");
    scanf("%d",&local_ngrade);

    int num_records = ReadDataFromFile();
    for (int i = 0; i < num_records; i++) {
        if (eid == students[i].id)
        {
            students[i].grade=local_ngrade;
            local_found=1;
            break;
        }
    }
    editfunction(num_records);

    if(local_found)
    {
        printf("the grade is changed succefully\n");
    }

    else
    {
        printf("Student with id %d not found.\n",eid);
    }

}

void ala_add_record()
{
    int local_no_of_students;
    printf("Enter how many records do you want to add:\n");
    scanf("%d",&local_no_of_students);


    for(int i=0;i<local_no_of_students;i++)
    {
        printf("for student %d\n",1+i);

        printf("Enter name :");
        scanf("%s",students[i].name);
        printf("Enter ID :");
        scanf("%d",&students[i].id);
        printf("Enter age :");
        scanf("%d",&students[i].age);
        printf("Enter gender :");
        scanf("%s",students[i].gender);
        printf("Enter password :");
        scanf("%s",students[i].pass);
        printf("Enter grade :");
        scanf("%d",&students[i].grade);

    }
    WriteDataToFile(local_no_of_students);
    printf("Record saved\n");

}



void ala_remove_record() {
    int local_id;
    printf("Enter ID of student to remove his record:");
    scanf("%d", &local_id);

    int number=ReadDataFromFile();

    int index = -1;

    for (int i = 0; i <number; i++) {
        if (students[i].id ==local_id) {
            index = i;
            break;
        }
    }

    if (index != -1) {

        students[index] = students[(number) - 1];
        (number)--;

        editfunction(number);
        printf("Record with ID %d has been deleted successfully.\n",local_id);
    } else {
        printf("Record with ID %d not found.\n", local_id);
    }
}



void ala_view_record()
{
    int local_vid;
    printf("Enter student ID:");
    scanf("%d",&local_vid);
    int found=0;


    ReadDataFromFile();
    int no_records=ReadDataFromFile();
    for(int i=0;i<no_records;i++)
    {
        if(students[i].id==local_vid)
        {
            printf(" Name:%s\n ID:%d\n Age:%d\n Gender:%s\n Password:%s\n Grade:%d\n",students[i].name,students[i].id,students[i].age,students[i].gender,students[i].pass,students[i].grade);
            found=1;

            break;
        }
    }
    if(!found)
    {
        printf("Student with ID:%d not found\n",local_vid);
    }

}

void ala_view_all_record()
{

    int local_all_records=ReadDataFromFile();;


    for(int i=0;i<local_all_records;i++)
    {
        printf(" Name:%s\n ID:%d\n Age:%d\n Gender:%s\n Password:%s\n Grade:%d\n",students[i].name,students[i].id,students[i].age,students[i].gender,students[i].pass,students[i].grade);

        printf("__________________________________ \n");
    }

}

void ala_edit_admin_password() {

    char* new_pass = (char*)malloc(50 * sizeof(char));

    printf("Enter the new password:");
    scanf("%s", new_pass);


    WriteAdminPassword(new_pass);
    printf("Successfully updated password.\n");

    free(new_pass);
    new_pass=NULL;
}

