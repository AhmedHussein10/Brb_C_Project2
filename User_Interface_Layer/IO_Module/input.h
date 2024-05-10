#ifndef INPUT_H
#define INPUT_H

typedef struct{
char  name [50];
int   grade;
int   id ;
int   age;
char  gender [8];
char  pass [20];
}record;

extern char Admin_Pass[20];

extern record students[100];         // Declaration of the global array


#endif
