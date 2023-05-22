// creating Sudoko game  <<Yossef Nada>>  #GAME
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
// exit(0) deh function bt2fl el program
#define rows 9
#define cols 9
//part one we will create the outline of the game                                   DONE
//it is an array 9*9 elements                                                       DONE
// 3alg moshkela el arkam el metkarara feh nafs el column aw el row                 DONE
// 3alg moshkela en el kol morab3 3*3 lazem mayb2ash feh arkam metkarara            DONE
// ye3rf ye3dl 3ala ely hwa katbo bas                                               DONE
// 7agat bel alwan                                                                  DONE
// congrats lw 3amlha sa7                                                           DONE
char array[rows][cols]= {0};
static char freq_array[9]= {0};
char countDiff=0;
char choice; //Either 1 2 3
char count=0; //counter for fill array to use recursive
char array_postitions[40][2]= {0};
char count_position=0;// for array _ position to fix the 0,0 problem
char return1,return2,return3;
int x=-4,y=-4;
int flag_bug=0;


void drawArray(void);
void fill_random(void);
void check_3_times_3(void);
void array_tasfeer(void);
int array_search_sudoko(char*parray,int n,int size);
int check_if_a1_isEitherRightORLeftTopOrBottom(int n,int row,int col);
void fill_position_array(void);
int check_if_there_are_repetitions_in_rowsORcolomns(void);
int final_check_3v3_times(void);
void red (void);
void green (void);
void reset (void);
void blue (void);




int main()
{
    flag_bug=0;
    int num;
    char* level;
    int flag=0;
    srand(time(NULL)); // time when passed null is gonna return the time each time which is going to be null so we will provide different seed numbers
    blue();
    printf("Set Difficulty:\n1-Easy\n2-medium\n3-difficult\n");
    scanf("%d",&choice);
    do
    {
        if(choice==1)
            level="Easy";
        else if(choice==2)
            level="Medium";
        else if(choice==3)
            level="Difficult";
        else
        {
            printf("Choose one of the designated numbers\n");
            scanf("%d",&choice);
        }
    }while(choice!= 1 && choice!=2 && choice!=3);
    reset();
    fill_random();
    //array2D_print2(array,9,9);
    check_3_times_3();
    if(flag_bug==1)
    {
        return 0;
    }
    fill_position_array();
    drawArray();
    while(count<=83)
    {
        do
        {
            blue();
            flag=0;
            printf("Enter the position of the number row=? and colomn=? separated by space and then the number you want to put\nDONT CHANGE THE GIVEN NUMBERS\n");
            scanf("%d%d%d",&x,&y,&num);
            if((x>9 || x<1) || (y>9 || y<1) )
            {
                printf("Enter valid X , Y from 1 to 9\n");
                continue;
            }
            for(int i=0; i<count_position; i++)
            {
                if((x-1)== array_postitions[i][0] && (y-1)==array_postitions[i][1])
                {
                    flag=1;
                    break;
                }

            }
        }while(flag==1);

        if(array[x-1][y-1]==0)
            count++;

        array[x-1][y-1]=num;
        system("cls");
        printf("                                            %s\n",level);
        reset();
        drawArray();
        printf("count=%d\n",count);
    }
    blue();
    if(final_check_3v3_times())
        printf("YOU LOSE DUE TO REPETITIONS IN 3V3 BOXES in BOX number %d\n",return1);
    else if(check_if_there_are_repetitions_in_rowsORcolomns()==2)
        printf("YOU LOSE DUE TO REPETITIONS in  COLOUMNS %d and %d for ROW %d\n",return2,return3,return1); // momken arg3 rakm mo5lf lel rows wel colomns we afslhm 3an ba3d
    else if(check_if_there_are_repetitions_in_rowsORcolomns()==1)
        printf("YOU LOSE DUE TO REPETITIONS in ROWS %d and %d for COLOUMN %d\n",return2,return3,return1); // momken arg3 rakm mo5lf lel rows wel colomns we afslhm 3an ba3d
    else
        printf("CONGRATS YOU WON THE GAME\n");

    char answer;
    printf("Do you want to play again if yes press 'y'?");
    scanf(" %c",&answer);
    if(answer=='y' || answer=='Y')
    {
        reset();
        return main();
    }
    else
        return 0;
}






















void drawArray(void)
{
    int flag1=0;
    green();
    int l=1;
    printf("\n\n\n                  1      2      3      4      5      6      7      8      9\n");
    printf("                ===============================================================\n");
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            flag1=0;
            if(j==0)
                printf("            %d  |",l);
            if(array[i][j]==0)
                printf("   ");
            else
            {
                for(int k=0; k<count_position; k++)
                {
                    if(array_postitions[k][0]==i && array_postitions[k][1]==j)
                    {
                        reset();
                        printf("%3c",array[i][j]+'0');
                        flag1=1;
                        break;
                    }

                }
                if(flag1==0)
                {
                    red();
                    printf("%3c",array[i][j]+'0');

                }


                green();

            }
            printf("   |");

        }
        printf("\n                ===============================================================\n");
        l++;
    }
    reset();
}

void fill_random(void)
{
    static int i=0; // to reserve it's place only once
    static int j=0;
    int flagcol=0,flagrow=1;
    int h=0,k=0;
    i=rand()%9;// from 0 to 8
    j=rand()%9;// from 0 to 8

    if(array[i][j]==0)
    {
        array[i][j]=(rand()%9)+1;

    }
    else
    {
        i=rand()%9;
        j=rand()%9;
        array[i][j]=(rand()%9)+1;
    }
    count++;
    //the following two loops are to prevent ant similar numbers in either rows or columns
    while(1) // for the same coloumn
    {
        flagcol=0;
        for(int a=0,l=0; a<rows || l<cols; a++,l++)
        {
            if(((array[i][j]==array[a][j]) && a!=i )||((array[i][j]==array[i][a]) && a!=j ))
            {
                array[i][j]=(rand()%9)+1;
                a=-1;
                flagcol=1;
            }
        }
        if(flagcol==0)
            break;

    }





    if(choice==1 && count>35)
        return;
    else if(choice==2 && count>27)
        return;
    else if(choice==3  && count>20)
        return;
    fill_random();
}


// check 3 times has a bug that sometimes after there is no intersection between a row and a coloumn and element in the box
// thus it gives a run time error
// it comes from the function -> check_if_a1_isEitherRightORLeftTopOrBottom(a+1,i,j) as it returns zero all the time
// this bug may occur in 10% of the inputs (ignorable)

void check_3_times_3(void) // will return 1 in case of repetitions in 3v3 array
{
    int i=0,j=0,c=0,r=3,col=3,flag,flag2=0,z,y;
    char Block3V3[9]= {0};
    char* freq;
    // first line of boxes 0<rows<3    0<cols<9
    while(c<3)
    {
        flag=0;
        int a=0;
        for(; i<r; i++)
        {
            for(j=col-3; j<col; j++)
            {
                Block3V3[a]=array[i][j];
                a++;
                //printf("i=%d  j=%d\n",i,j);
            }
        }
        i=0;
        j-=3;
        //array_print_char(Block3V3,9);

        for(; i<r; i++)
        {
            for(j=col-3; j<col; j++)
            {
                flag2=1;
                array_tasfeer();
                while(array[i][j]!=0 && array_search_sudoko(Block3V3,array[i][j],9))
                {
                    flag2=0;
                    for(int a=0; a<9; a++)
                    {
                        if(freq_array[a]==0 && check_if_a1_isEitherRightORLeftTopOrBottom(a+1,i,j))
                        {
                            z=i;
                            if(j<3)
                                y=j;
                            else if(j<6)
                                y=j-3;
                            else
                                y=j-6;
                            array[i][j]=a+1; //add the minimum value
                            Block3V3[z*3+y]=a+1;
                            flag=1;
                            flag2=1;
                            break;
                        }
                    }
                    if(flag==1)
                        break;
                    if(flag2==0)
                    {
                        red();
                        printf("\n\nSORRY FOR THE DISTURBANCE RUN AGAIN :)\n");
                        reset();
                        flag_bug=1;
                        return;
                    }
                }




            }
        }
        i=0;
        col+=3;
        c++;
    }
    // 2nd line of boxes
    i=3,j=0,c=0,r=6,col=3;
    while(c<3)
    {
        flag=0;
        int a=0;
        for(; i<r; i++)
        {
            for(j=col-3; j<col; j++)
            {
                Block3V3[a]=array[i][j];
                a++;
                //printf("i=%d  j=%d\n",i,j);
            }
        }
        //array_print_char(Block3V3,9);
        i=3;
        j-=3;

        for(; i<r; i++)
        {
            for(j=col-3; j<col; j++)
            {
                array_tasfeer();
                while(array[i][j]!=0 && array_search_sudoko(Block3V3,array[i][j],9))
                {
                    for(int a=0; a<9; a++)
                    {
                        if(freq_array[a]==0 && check_if_a1_isEitherRightORLeftTopOrBottom(a+1,i,j))
                        {
                            z=i-3;
                            if(j<3)
                                y=j;
                            else if(j<6)
                                y=j-3;
                            else
                                y=j-6;
                            array[i][j]=a+1; //add the minimum value
                            Block3V3[z*3+y]=a+1;
                            flag=1;
                            break;
                        }
                    }
                    if(flag==1)
                        break;
                }


            }
        }
        i=3;
        col+=3;
        c++;
    }
    //third line of boxes
    i=6,j=0,c=0,r=9,col=3;
    while(c<3)
    {

        flag=0;
        int a=0;
        for(; i<r; i++)
        {
            for(j=col-3; j<col; j++)
            {
                Block3V3[a]=array[i][j];
                a++;
                //printf("i=%d  j=%d\n",i,j);
            }
        }
        //array_print_char(Block3V3,9);
        i=6;
        j-=3;

        for(; i<r; i++)
        {
            for(j=col-3; j<col; j++)
            {
                array_tasfeer();
                while(array[i][j]!=0 && array_search_sudoko(Block3V3,array[i][j],9))
                {
                    //printf("\n\n\n\n");
                    //array_print_char(freq_array,9);
                    //printf("\n\n\n\n");
                    for(int a=0; a<9; a++)
                    {
                        if(freq_array[a]==0 && check_if_a1_isEitherRightORLeftTopOrBottom(a+1,i,j))
                        {
                            z=i-6;
                            if(j<3)
                                y=j;
                            else if(j<6)
                                y=j-3;
                            else
                                y=j-6;
                            array[i][j]=a+1; //add the minimum value
                            Block3V3[z*3+y]=a+1;
                            flag=1;
                            //array_print_char(Block3V3,9);
                            //printf("abrakadabra     array[i][j]=%d\n",array[i][j]);
                            break;
                        }
                    }
                    if(flag==1)
                        break;

                }

            }
        }
        i=6;
        col+=3;
        c++;
    }



}



int array_search_sudoko(char*parray,int n,int size)
{
    int counter=0;
    for(int i=0; i<9; i++)
    {
        if(parray[i]==0)
            continue;
        freq_array[parray[i]-1]++;
    }
    for(int i=0; i<size; i++)
    {
        if(n==parray[i])
        {
            counter++;
        }
        //printf("arrray[i][j]=%d  block[%d]=%d counter=%d\n",n,i,parray[i],counter);
    }
    if(counter>1)
    {

        return 1;
    }
    return 0;
}


void array_tasfeer(void)
{
    for(int i=0; i<9; i++)
    {
        freq_array[i]=0;
    }
}

int check_if_a1_isEitherRightORLeftTopOrBottom(int n,int row,int col)
{
    for(int i=0; i<cols; i++)
    {
        if(n==array[row][i])
            return 0;
    }
    for(int i=0; i<rows; i++)
    {
        if(n==array[i][col])
            return 0;
    }
    return 1;
}


void fill_position_array(void)
{
    int k=0,l=0;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if(array[i][j]!=0)
            {
                array_postitions[k][l]=i;
                array_postitions[k][l+1]=j;
                k++;
                count_position++;
            }
        }
    }
}


int check_if_there_are_repetitions_in_rowsORcolomns(void)
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++) // after this we will have an element of each array in the array
        {
            for(int a=j+1; a<cols; a++)
            {
                if(array[i][j]==array[i][a])
                {
                    return1=i;
                    return2=j;
                    return3=a;
                    return 2;
                }
            }

            for(int a=i+1; a<rows; a++)
            {
                if(array[i][j]==array[a][j])
                {
                    return1=j;
                    return2=i;
                    return3=a;
                    return 1;
                }
            }
        }
    }
    return 0;
}

int final_check_3v3_times(void)
{
    char block[9]= {0};
    int p=0,col=3,j,flag=0,y;
    while(p<3) // for the first set of boxes
    {

        int a=0;
        for(int i=0; i<3; i++)
        {
            for(j=col-3; j<col; j++)
            {
                block[a]=array[i][j];
                a++;
            }
        }
        for(int i=0; i<3; i++)
        {
            for(j=col-3; j<col; j++)
            {
                for(int a=0; a<9; a++)
                {
                    if(j<3)
                        y=j;
                    else if(j<6)
                        y=j-3;
                    else
                        y=j-6;
                    if(array[i][j] && a!=(i*3+y))
                    {
                        if(j<3)
                            return1=1;
                        else if(j<6)
                            return1=2;
                        else
                            return1=3;

                        return 1;
                    }

                }
            }
        }



        col+=3;
        p++;
    }
    p=0,col=3;
    while(p<3) // for the first set of boxes
    {

        int a=0;
        for(int i=3; i<6; i++)
        {
            for(j=col-3; j<col; j++)
            {
                block[a]=array[i][j];
                a++;
            }
        }
        for(int i=3; i<6; i++)
        {
            for(j=col-3; j<col; j++)
            {
                for(int a=0; a<9; a++)
                {
                    if(j<3)
                        y=j;
                    else if(j<6)
                        y=j-3;
                    else
                        y=j-6;
                    if(array[i][j] && a!=((i-3)*3+y))
                    {
                        if(j<3)
                            return1=4;
                        else if(j<6)
                            return1=5;
                        else
                            return1=6;

                        return 1;
                    }
                }
            }
        }



        col+=3;
        p++;
    }
    p=0,col=3;
    while(p<3) // for the first set of boxes
    {

        int a=0;
        for(int i=6; i<9; i++)
        {
            for(j=col-3; j<col; j++)
            {
                block[a]=array[i][j];
                a++;
            }
        }
        for(int i=6; i<9; i++)
        {
            for(j=col-3; j<col; j++)
            {
                for(int a=0; a<9; a++)
                {
                    if(j<3)
                        y=j;
                    else if(j<6)
                        y=j-3;
                    else
                        y=j-6;
                    if(array[i][j] && a!=((i-6)*3+y))
                    {
                        if(j<3)
                            return1=7;
                        else if(j<6)
                            return1=8;
                        else
                            return1=9;

                        return 1;
                    }
                }
            }
        }



        col+=3;
        p++;
    }
    return 0;
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

