#include <stdio.h>
#include <stdlib.h>
#include "Head.h"
#include <windows.h>
#define MaxSchoolSize 1000

extern int index;
extern student_t school[MaxSchoolSize];



void add_student()
{
    student_t*s;
    green();
    printf("Now you are adding a student with ID %d\n",index+1);
    printf("Main Student Details : \n");
    printf("Student name: ");
    string_scan(school[index].name,20);
    printf("Age: ");
    scanf("%d",&school[index].age);
    printf("Gender :");
    string_scan(school[index].gender,10);
    fflush(stdin);
    //string_print(school[index].gender);
    printf("LEVEL : ");
    scanf("%d",&school[index].level);
    //string_print(school[index].gender);
    fflush(stdin);
    printf("Now Enter Grades : \n");
    printf("Maths :");
    scanf("%d",&school[index].grades[0]);
    printf("Physics :");
    scanf("%d",&school[index].grades[1]);
    printf("Chemistry :");
    scanf("%d",&school[index].grades[2]);
    printf("Mechanics :");
    scanf("%d",&school[index].grades[3]);
    printf("Programming :");
    scanf("%d",&school[index].grades[4]);
    printf("Now Enter phone number (11 numbers): ");
    phone_scan(school[index].phone,12);
    system("cls");
    printf("Parents Data:\n1-Father:\n");
    printf("Father's name : ");
    string_scan(school[index].father.name,20);
    printf("phone number: ");
    phone_scan(school[index].father.phone,12);
    printf("Occupation :");
    string_scan(school[index].father.occupation,20);
    system("cls");
    printf("2-Mother:\n");
    printf("Mother's name : ");
    string_scan(school[index].mother.name,20);
    printf("phone number: ");
    phone_scan(school[index].mother.phone,12);
    printf("Occupation :");
    string_scan(school[index].mother.occupation,20);
    system("cls");
    printf("How many siblings (You can add up to 5) :");
    scanf("%d",&school[index].numberOfSiblings);
    //school[index].siblings=(person_t*)malloc(school[index].numberOfSiblings*sizeof(person_t));  //in case you wanted dynamic allocation but careful it wont work with saving the file externally
    for(int i=0; i<school[index].numberOfSiblings && i<5; i++)
    {
        printf("Sibling %d name: ",i+1);
        string_scan(school[index].siblings[i].name,20);
        printf("His/Her phone : ");
        phone_scan(school[index].siblings[i].phone,12);
        printf("His/Her occupation : ");
        string_scan(school[index].siblings[i].occupation,20);
    }
    reset();
    index++;
}


void edit_student(void)
{
    char choice3,choice1,choice2,choice4;
    char name[20];
    int id;
    blue();
    printf("Which student : search by 1-name OR 2-ID \n");
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
        id=search_student(name);
        if(id==-1)
        {
            printf("Student Not Registered\n");
            return;
        }

    }
    else
    {
        printf("Write Student ID:");
        scanf("%d",&id);
        id--;
    }

    printf("If you want to edit student's name,age,grade,phone or level press '1'.\nIf you want to change parent details press'2'.\nIf you want to change sibling details press'3'.\n");
    scanf("%d",&choice1);
    while(choice1!= 1 && choice1!=2 && choice1!=3)
    {
        printf("Choose Either 1 or 2 or 3\n");
        scanf("%d",&choice1);
    }
    if(choice1==1)
    {
        printf("Is it only\n1-Name\n2-Age\n3-Grade\n4-Phone\n5-All of them(with gender and level)\n");
        scanf("%d",&choice2);
        while(choice2<1 || choice2>5)
        {
            printf("Choose valid number\n");
            scanf("%d",&choice2);
        }
        switch(choice2)
        {
        case 1:
            printf("Enter name: ");
            string_scan(school[id].name,20);
            break;
        case 2:
            printf("Enter age: ");
            scanf("%d",&school[id].age);
            break;
        case 3:
            printf("1-All Grades\n2-Maths\n3-Physics\n4-Chemistry\n5-Mechanics\n6-Programming\n");
            scanf("%d",&choice4);
            while(choice4<1 || choice4>6)
            {
                printf("Choose valid number\n");
                scanf("%d",&choice4);
            }
            if(choice4==1)
            {
                printf("Maths :");
                scanf("%d",&school[id].grades[0]);
                printf("Physics :");
                scanf("%d",&school[id].grades[1]);
                printf("Chemistry :");
                scanf("%d",&school[id].grades[2]);
                printf("Mechanics :");
                scanf("%d",&school[id].grades[3]);
                printf("Programming :");
                scanf("%d",&school[id].grades[4]);

            }
            else if(choice4==2)
            {
                printf("Maths :");
                scanf("%d",&school[id].grades[0]);
            }
            else if(choice4==3)
            {
                printf("Physics :");
                scanf("%d",&school[id].grades[1]);
            }
            else if(choice4==4)
            {
                printf("Chemistry :");
                scanf("%d",&school[id].grades[2]);
            }
            else if(choice4==5)
            {
                printf("Mechanics :");
                scanf("%d",&school[id].grades[3]);
            }
            else // choice4=6
            {
                printf("Programming :");
                scanf("%d",school[id].grades[4]);
            }
            break;
        case 4:
            printf("Phone: ");
            phone_scan(school[id].phone,12);
            break;
        case 5:
            struct_scan_Main(&school[id]);
            break;

        }
    }
    else if(choice1==2)
    {
        printf("Which parent 1-Father 2-Mother\n");
        scanf("%d",&choice2);
        while(choice2!= 1 && choice2!=2)
        {
            printf("Choose Either 1 or 2\n");
            scanf("%d",&choice2);
        }
        if(choice2==1)
        {
            printf("1-Name\n2-Phone\n3-Occupation?\n");
            scanf("%d",&choice4);
            while(choice4!= 1 && choice4!=2 && choice4!=3)
            {
                printf("Choose Either 1 or 2 or 3\n");
                scanf("%d",&choice4);
            }
            if(choice4==1)
            {
                printf("Father's name: ");
                string_scan(school[id].father.name,20);
            }
            else if(choice4==2)
            {
                printf("Father's Phone : ");
                phone_scan(school[id].father.phone,12);
            }
            else
            {
                printf("Occupation : ");
                string_scan(school[id].father.occupation,20);
            }

        }
        else
        {
            printf("1-Name\n2-Phone\n3-Occupation?\n");
            scanf("%d",&choice4);
            while(choice4!= 1 && choice4!=2 && choice4!=3)
            {
                printf("Choose Either 1 or 2 or 3\n");
                scanf("%d",&choice4);
            }
            if(choice4==1)
            {
                printf("Mothers's name: ");
                string_scan(school[id].mother.name,20);
            }
            else if(choice4==2)
            {
                printf("Mother's Phone : ");
                phone_scan(school[id].mother.phone,12);
            }
            else
            {
                printf("Occupation : ");
                string_scan(school[id].mother.occupation,20);
            }
        }
    }
    else
    {
        for(int i=0; i<school[id].numberOfSiblings; i++)
        {
            printf("1-Name\n2-Phone\n3-Occupation?\n4-All of them\n");
            scanf("%d",&choice4);
            while(choice4!= 1 && choice4!=2 && choice4!=3)
            {
                printf("Choose Either 1 or 2 or 3\n");
                scanf("%d",&choice4);
            }
            if(choice4==1)
            {
                printf("Sibling %d name: ",i+1);
                string_scan(school[id].siblings[i].name,20);
            }
            else if(choice4==2)
            {
                printf("Sibling %d Phone : ",i+1);
                phone_scan(school[id].siblings[i].phone,12);
            }
            else if(choice4==3)
            {
                printf("Occupation : ");
                string_scan(school[id].siblings[i].occupation,20);
            }
            else
            {
                printf("Sibling %d name: ",i+1);
                string_scan(school[id].siblings[i].name,20);
                printf("Sibling %d Phone : ",i+1);
                phone_scan(school[id].siblings[i].phone,12);
                printf("Occupation : ");
                string_scan(school[id].siblings[i].occupation,20);
            }
        }
    }
}

void print_student(int id) // for printing Each student
{
    system("cls");
    green();
    printf("Name:%s\tAge=%d\tPhone:",school[id].name,school[id].age);
    phone_print(school[id].phone,11);
    printf("\tGender : %s\tlEVEL=%d",school[id].gender,school[id].level);
    int average=(school[id].grades[0]+school[id].grades[1]+school[id].grades[2]+school[id].grades[3]+school[id].grades[4])/5;
    red();
    printf("\n****************************************************************************\nGRADES:\n");
    green();
    printf("Maths=%d   Physics=%d   Chemistry=%d   mechanics=%d   Programming=%d  => Average Score=%d\n",school[id].grades[0],school[id].grades[1],school[id].grades[2],school[id].grades[3],school[id].grades[4],average);
    red();
    printf("******************************************************************************\n");
    green();
    printf("Parents Details:\n");
    red();
    printf("******************************************************************************\n");
    green();
    printf("Father:%s\tPhone NO. :",school[id].father.name);
    phone_print(school[id].father.phone,11);
    printf("\tOccupation:%s\n",school[id].father.occupation);
    red();
    printf("******************************************************************************\n");
    green();
    printf("mother:%s\tPhone NO. :",school[id].mother.name);
    phone_print(school[id].mother.phone,11);
    printf("\tOccupation:%s\n",school[id].mother.occupation);
    red();
    printf("******************************************************************************\n");
    green();
    printf("No. of Siblings: %d\n",school[id].numberOfSiblings);
    red();
    printf("******************************************************************************\n");
    green();
    for(int i=0; i<school[id].numberOfSiblings; i++)
    {

        printf("sibling:%-15s\tPhone NO. :",school[id].siblings[i].name);
        phone_print(school[id].siblings[i].phone,11);
        printf("\tOccupation:%-15s\n",school[id].siblings[i].occupation);
        red();
        printf("******************************************************************************\n");
        green();
    }
    fflush(stdin);
    reset();

}


void delete_student(void)
{
    char choice3;
    int id;
    char name[20];
    green();
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
        id=search_student(name);
        if(id==-1)
        {
             printf("Student Not Registered\n");
             return;
        }

    }
    else
    {
        printf("Write Student ID:");
        scanf("%d",&id);
        id--;
    }
    for(int i=id; i<index-1; i++)
    {
        school[i]=school[i+1];
    }
    index--;

}


void print_school(void) // will print the basic information only
{
    system("cls");
    red();
    printf("===============================================================================================================\n");
    green();
    printf("|      |                  |      |                |             |                        |                    |\n");
    printf("|  ID  |       NAME       |  AGE |     GENDER     |    LEVEL    |      AVERAGE GRADE     |     PHONE NUMBER   |\n");
    printf("|      |                  |      |                |             |                        |                    |\n");
    red();
    printf("===============================================================================================================\n");
    int average;
    for(int i=0; i<index; i++)
    {
        average=(school[i].grades[0]+school[i].grades[1]+school[i].grades[2]+school[i].grades[3]+school[i].grades[4])/5;
        green();
        printf("|  %-4d| %-14s   |  %-4d|      %-10s|      %-7d|           %-13d|    ",i+1,school[i].name,school[i].age,school[i].gender,school[i].level,average);
        phone_print(school[i].phone,12);
        printf("    |");
        red();
        printf("\n===============================================================================================================\n");

    }



}


void call_student(void)
{
    char choice3;
    char choice;
    int id;
    char name[20];
    green();
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
        id=search_student(name);
        if(id==-1)
        {
             printf("Student Not Registered\n");
             return;
        }
    }
    else
    {
        printf("Write Student ID:");
        scanf("%d",&id);
        id--;
    }
    printf("1-student :    %-20s \t\t",school[id].name);
    printf("Phone number: ");
    phone_print(school[id].phone,11);
    printf("\n2-Father  :    %-20s \t\t",school[id].father.name);
    printf("Phone number: ");
    phone_print(school[id].father.phone,11);
    printf("\n3-Mother  :    %-20s\t\t",school[id].mother.name);
    printf("Phone number: ");
    phone_print(school[id].mother.phone,11);
    printf("\nWho do you want to call? (Use numbers from 1 to 3) : ");
    scanf("%d",&choice);
    while(choice!= 1 && choice!=2 && choice!=3)
    {
        printf("Choose Either 1 or 2 or 3\n");
        scanf("%d",&choice);
    }
    if(choice==1)
    {
        system("cls");
        printf("Calling student : %s\n",school[id].name);
        for(int i=0; i<5; i++)
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
            delay(500);
        }

    }
    else if(choice==2)
    {
        system("cls");
        printf("Calling student's father : %s\n",school[id].father.name);
        for(int i=0; i<5; i++)
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
        system("cls");
        printf("Calling student's mother : %s\n",school[id].mother.name);
        for(int i=0; i<5; i++)
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
    char choice2='n';
    printf("No Answer.....\n");
    printf("Do you want to try calling again? 'Y' or 'N' :");
    scanf(" %c",&choice2);
    system("cls");
    if(choice2=='Y' || choice2=='y')
    {
        call_student();
    }



}

int search_student(char*name) // takes the name of the student and returns ID
{
    for(int i=0; i<index; i++)
    {
        if(checkIfStringIdentical_case_insensitive(name,school[i].name))
        {
            return i;
        }
    }
    return -1;
}



void red (void)
{
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);

}

void green(void)
{
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN);
}

void reset (void)
{
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
}
void blue (void)
{
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE);
}


void string_print(char*array)
{
    for(int i=0; array[i]; i++)
    {
        printf("%c",array[i]);
    }
    printf("\n");
}


int string_length(char* array) // not similar to sizeof because size of brings back the size of the char including the null size
{
    int i;
    for(i=0; array[i]; i++);
    return i;
}

void tolower_string(char*str)
{
    for(int i=0; str[i]; i++)
    {
        if(str[i]>='A' && str[i]<='Z')
            str[i]+='a'-'A';
    }
}



void toupper_string(char*str)
{
    for(int i=0; str[i]; i++)
    {
        if(str[i]>='a' && str[i]<='z')
            str[i]-='a'-'A';
    }
}

int checkIfStringIdentical_case_insensitive(char*str1,char*str2)
{
    int flag=1;
    for(int i=0; str1[i] || str2[i]; i++)
    {
        if(towlower(str1[i])!=tolower(str2[i]))
        {
            flag=0;
            break;
        }

    }
    return flag;
}


void string_scan(char*str,int max)
{
    int i=0;
    scanf(" %c",&str[i]);// we put space here in case we used a scanf before there will be a space in the buffer which will make us exit the loop before we even start
    for(; str[i]!='\n' && i<max-1;)//-1 3alshan ha7pt el null fel postion el akher
    {
        i++;
        scanf("%c",&str[i]);
    }
    str[i]=0;
}


void phone_print(char*parray,int size)
{
    for(int i=0; i<size; i++)
        printf("%d",parray[i]);

}

void phone_scan(char*p,char size)
{
    char*s;
    string_scan(s,size);
    for(int i=0; i<size && s[i]; i++)
    {
        p[i]=s[i]-'0';
    }
}
void struct_scan_Main (student_t* s)
{
    system("cls");
    printf("Enter Name :");
    string_scan(s->name,20); // (*(s+i)).name
    printf("Enter Age  :");
    scanf("%d",&(s->age));
    fflush(stdin);
    printf("Enter gender: ");
    string_scan(s[0].gender,10);
    fflush(stdin);
    printf("Enter level : ");
    scanf("%d",&(s[0].level));
    printf("Enter Grades:\n");
    printf("Maths :");
    scanf("%d",&s->grades[0]);
    printf("Physics :");
    scanf("%d",&s->grades[1]);
    printf("Chemistry :");
    scanf("%d",&s->grades[2]);
    printf("Mechanics :");
    scanf("%d",&s->grades[3]);
    printf("Programming :");
    scanf("%d",&s->grades[4]);
    printf("Phone: ");
    phone_scan(s->phone,11);

    //fflush(stdin);     badl ma astkhdmha ro7t 7ateta  space abl %c fel string scan
}



void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}








//file layout
//total  (to know how many structs)
//school[1]
//school[2]
//school[3]

bool write_data(char*filename,student_t*data,int total) // to write to a binary file
{
    FILE*file; // pointer to file
    file=fopen(filename,"wb");//wb is for write to binary file mode fopen returns file pointer that we are going to store in the file
    if(file==NULL)
        return false;
    if(fwrite(&total,sizeof(int),1,file) !=1)
        return false;                              // it returns how many of how much size it was able to write



    if(fwrite(data,sizeof(student_t),total,file)!=total)      //fwrite returns how many it could write, so it should equal total if it doesnot we got a problem
        return false;



     if(fclose(file)==EOF)   //if ti returns EOF this signals something wrong
            return false;


     return true;



}


student_t* read_data(char*filename,int*total)
{
    FILE*file;
    file=fopen(filename,"rb");
    if(file==NULL)
        return NULL;
    if(fread(total,sizeof(int),1,file)!=1)
        return NULL;

    if((fread(school,sizeof(student_t),*total,file))!=(*total))
        return NULL;   //if you used dynamic memory from the heap make sure you free all the allocated memory to avoid memory leak

    if(fclose(file)==EOF)
        return NULL;

     return 1;

}
