#include <stdio.h>
#include <stdlib.h>
#include "Head.h"
#include<windows.h>
#include<stdbool.h>
#include<string.h>
#define MaxSchoolSize 1000




//person_t s1= {"Yossef Ali",{0,1,2,3,4,5,6,7,8,9,1},"Student"}; //if you want to use dynamic allocation instead of siblings array create this struct as initialization and put it's address in the main struct
//person_t s2= {"ahmed kareem",{0,1,2,3,4,5,6,7,8,9,1},"Student"};

student_t school[MaxSchoolSize]= {{"Ahmed Ali",21,{0,1,2,3,4,5,6,7,8,9,1},{93,92,90,95,96},2,"Male",{"Ali EL rawy",{0,1,2,3,4,5,6,7,8,9,1},"Pensioner"},{"Amany Mohamed",{0,1,2,3,4,5,6,7,8,9,1},"Engineer"},1,{{"Yossef Ali",{0,1,2,3,4,5,6,7,8,9,1},"Student"}}},
                                    {"ziad karem",22,{0,1,2,3,4,5,6,7,8,9,1},{91,94,80,84,90},3,"Male",{"karem alaa",{0,1,2,3,4,5,6,7,8,9,1},"officer"},{"asmaa Mohamed",{0,1,2,3,4,5,6,7,8,9,1},"cook"},1,{{"ahmed kareem",{0,1,2,3,4,5,6,7,8,9,1},"Student"}}}};  // will be initialized with zeros in the .bss in RAM

int index=2; // index of the first free slot



int main()
{
    red();

    if(read_data("database.bin",&index)==NULL)
    {
        printf("Error reading from file\n");
        delay(5000);
        return 1;
    }
    else
    {
        printf("Reading Data\n");
        for(int i=0; i<1; i++)
        {
            printf(".");
            delay(500);
            printf(".");
            delay(500);
            printf(".");
            delay(500);
            printf(".");
            delay(500);
            printf(".");
            delay(500);
            printf("\r");
            printf("     ");
            printf("\r");
        }
    }
    reset();
    system("cls");

    char choice,answer,choice3;
    char name[20];
    int id_student;
    red();
    printf("                                     *********************************************\n                                     *This is a full Database for school students*\n                                     *********************************************\n\n");
    reset();

    do
    {


        answer='y';
        green();
        printf("1- Add Student\n2- Edit Student\n3- Print Student\n4- Delete Student\n5- Print School\n6- Call Student\n");

        scanf("%d",&choice); // Now we will articulate the choices in the form of functions
        reset();
        //====================================================================================//
        switch(choice)
        {
        case 1:
            add_student();
            break;
        case 2:
            edit_student();
            break;
        case 3:
            blue();
            printf("Do You want to search by 1-name OR 2-ID \n");
            scanf("%d",&choice3);
            while(choice3!= 1 && choice3!=2)
            {
                printf("Choose Either 1 or 2\n");
                scanf("%d",&choice3);
            }
            if(choice3==1)
            {
                printf("Enter student name:");
                string_scan(name,20);
                id_student=search_student(name);
                if(id_student==-1)
                    printf("Student Not Registered\n");
            }
            else
            {
                printf("Write Student ID:");
                scanf("%d",&id_student);
                id_student--;
            }
            print_student(id_student);
            fflush(stdin);
            reset();
            break;
        case 4:
            delete_student();
            break;
        case 5:
            print_school();
            break;
        case 6:
            call_student();
            break;
        default:
            system("cls");
            fflush(stdin);
            blue();
            printf("Choose answers from 1 to 6 to do one of the of the following operations\n");
            reset();
            continue;

        }


        //====================================================================================//
        blue();
        printf("Do you want to run any other operation? If 'YES' press 'Y' or press 'N' to exit\n");
        reset();
        scanf(" %c",&answer);
        system("cls");

    }
    while(answer=='Y' ||answer=='y');
    red();

    if(write_data("database.bin",school,index))

    {
        printf("Writing Data OK\n");
        for(int i=0; i<1; i++)
        {
            printf(".");
            delay(500);
            printf(".");
            delay(500);
            printf(".");
            delay(500);
            printf(".");
            delay(500);
            printf(".");
            delay(500);
            printf("\r");
            printf("     ");
            printf("\r");
        }
    }
    else
    {
        printf("ERROR in writing data\n");
        return 1; // to signal that something went wrong

    }










    return 0;
}

