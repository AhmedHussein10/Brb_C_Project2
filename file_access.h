//
// Created by HP on 5/5/2024.
//

#ifndef UNTITLED1_FILE_ACCESS_H
#define UNTITLED1_FILE_ACCESS_H
typedef struct
{
    char name[50];
    int id;
    int age;
    char gender[50];
    char pass[50];
    int grade;

}record;
int ReadDataFromFile(void);
void WriteDataToFile(int);
void WriteAdminPassword(char*);
char* ReadAdminPassword(void);
#endif //UNTITLED1_FILE_ACCESS_H
