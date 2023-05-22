//File guard
#ifndef HEAD_H
#define HEAD_H

#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>


// Creating the (struct type

typedef struct{    // this is any person father,mother or siblings

    char name[20];
    char phone[11];
    char occupation[20];

}person_t;




typedef struct{
    char name[20];
    int age;
    char phone[11];
    int grades[5]; // assign 5 subjects
    int level;
    char gender[10];
    person_t father;
    person_t mother;
    int numberOfSiblings;
    person_t siblings[5]; // in order to reserve memory we will use dynamic allocation

}student_t;


//===========================//
//***** Function Prototypes*****//
void add_student();
void edit_student(void);
void print_student(int id);
void delete_student(void);
void print_school(void);
void call_student(void);
void red (void);
void green(void);
void reset (void);
void blue (void);
void toupper_string(char*str);
void tolower_string(char*str);
int string_length(char* array);
void string_print(char*array);
int checkIfStringIdentical_case_insensitive(char*str1,char*str2);
int search_student(char*name);
void string_scan(char*str,int max);
void phone_print(char*parray,int size);
void phone_scan(char*p,char size);
void struct_scan_Main (student_t* s);
void delay(unsigned int milliseconds);
bool write_data(char*filename,student_t*data,int total);
student_t* read_data(char*filename,int*total);




























#endif // HEAD_H

