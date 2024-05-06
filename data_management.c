
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "data_management.h"
#include "file_access.h"
#include "input.h"

void editfunction(int students_number) {
    FILE *temp;
    temp = fopen("temporary_data.csv", "w");
    if (temp == NULL) {
        printf("Error creating temporary file!\n");
        exit(1);
    }

    for (int i = 0; i < students_number; i++) {
        fprintf(temp, "%s,%d,%d,%s,%s,%d\n", students[i].name, students[i].id, students[i].age, students[i].gender, students[i].pass, students[i].grade);

    }

    fclose(temp);
    remove("student_data.csv");
    rename("temporary_data.csv", "student_data.csv");
}
