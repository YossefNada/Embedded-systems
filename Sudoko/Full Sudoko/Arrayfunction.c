
void array_print(int*parray,int size)
{
    for(int i=0;i<size;i++)
        printf("%2d  ",parray[i]);
    printf("\n");
}

void array_print_char(char*parray,int size)
{
    for(int i=0;i<size;i++)
        printf("%2d  ",parray[i]);
    printf("\n");
}


int array_sum(int*parray,int size)
{
    int sum=0;
    for(int i=0;i<size;i++)
    {
        sum+=*(parray+i);
    }
    return sum;
}

 int array_search(int*parray,int n,int size,int*c)
{   // lw 3ayez ageeb kol el amaken ha3mel el flag array ageebo men main we aktb fel amaken ely feha el number
    // momken abd2 men al akher we ageeb awel mara ala2eh
    int flag=-1;
    int counter=0;
    for(int i=0;i<size;i++)
    {
        if(n==parray[i])
            {

                flag=i;
                counter++;

            }
    }
    *c=counter;
    return flag;
}
 int array_searchandreturnIndex(int*parray,int n,int size,int* firstposition,int* second)
{   // lw 3ayez ageeb kol el amaken ha3mel el flag array ageebo men main we aktb fel amaken ely feha el number
    // momken abd2 men al akher we ageeb awel mara ala2eh
    int flag=-1;
    int counter=0;
    for(int i=0;i<size;i++)
    {
        if(n==parray[i])
            {
                *second=i;
                counter++;
                if(counter==1)
                    *firstposition=i;



            }
    }

    return counter;//if the function returned zero then the element is not zero
}

int array_max (int*parray,int size,int*pmax,int*pmin,int*flagmax)
{
    int flagmin;
    for(int i=0;i<size;i++)
    {
        if(*(parray+i)>*pmax)
        {
            *pmax=*(parray+i);
            *flagmax=i;
        }
         if(*(parray+i)<*pmin)
        {
            *pmin=*(parray+i);
            flagmin=i;

        }
    }
    return flagmin;

}

int* array_numbers_InBetween(int n1,int n2)
 {
     int size= n2-n1-1;
     int array[size];
     for(int i=0;i<size;i++)
     {
         array[i]=++n1;
     }
     int *ptr=array;
     //printf("%d   %d   %d\n",array,array+1,array+2,array+3);
     //printf("%d   %d   %d",*array,*(array+1),*(array+2),*(array+3));
     return ptr;/*We can pass pointers to the function as well as return pointer from a function.
      But it is not recommended to return the address of a local variable outside the function as it goes out of scope after function returns.*/
      //You cant return address because once the function ends this address is terminated so you need to save it first

 }


int array_most_repeated(int*parray,int n,int*repeat,int size)
   {
       int flag=0;
       for(int i=0;i<size;i++)
       {
           if(parray[i]==n)
           {
               flag++;
           }
       }
       *repeat=flag;
       return flag;

   }
void array_reverse(int*ptr,int size)

{



    int arrayy[size];
    for(int i=0;i<size;i++)
    {
       arrayy[i]=*(ptr+size-i-1);
    }
    for(int j=0;j<size;j++)
    {
        ptr[j]=arrayy[j];
    }
    /*
    int i,j=size-1,temp;
    for(i=0;i<size/2;i++) // condition can be i<size/2
    {
        temp=ptr[i];
        ptr[i]=ptr[j];
        ptr[j]=temp;
        j--;

    }*/
}
void array_swap(int*p1,int*p2,int s1,int s2)
{

    int array_dummy[s2];
    for(int i=0;i<s2;i++)
    {
        if(i<s1)
        {
            array_dummy[i]=p1[i];
        }
        else
            array_dummy[i]=0;
    }
    for(int i=0;i<s1;i++)
    {
        p1[i]=p2[i];
    }
    for(int i=0;i<s2;i++)
    {
        p2[i]=array_dummy[i];
    }/*
    // if they were similar size

    int i,temp;
    int size=s1;
    if(s1>s2)
    {
        size=s2;
    }
    for(i=0;i<size;i++)
    {
        temp=p1[i];
        p1[i]=p2[i];
        p2[i]=temp;
    }*/
}
void arrayReverseSwap(int*p1,int s1,int*p2,int s2)
{
    array_swap(p1,p2,s1,s2);
    array_reverse(p1,s1);
    array_reverse(p2,s2);
}
void arrayReverseSwap2(int*p1,int s1,int*p2,int s2)
{
    int i,j=s1-1,temp;
    for(i=0;i<s1;i++)
    {
        temp=p1[i];
        p1[i]=p2[j];
        p2[j]=temp;
        j--;
    }
}
void arrayRemovePrime(int *ptr,int size)
{
    for(int i=0;i<size;i++)
    {
        if(!prime(ptr[i]))
            ptr[i]=0;
    }
}

int longest_occurence (int*ptr,int size,int*num) //consecutive occurence
{

    int counter=1,max=0;
    for(int i=0;i<size;i++)
    {
        if(ptr[i]==ptr[i+1])
        {
            counter++;
            if(counter>max)
            {
                max=counter;
                *num=ptr[i];
            }
        }
        else
            counter=1;

    }
    return max;
}

int longest_occurence_of_agiven_number (int*ptr,int size,int num) //consecutive occurence
{

    int counter=0,max=0;
    for(int i=0;i<size;i++)
    {
        if(num==ptr[i])
        {
            counter++;
            if(counter>max)
            {
                max=counter;
            }
        }
        else
            counter=0;

    }
    return max;
}

void array_merge (int*array1,int size1,int *array2,int size2,int*array3,int size) //consecutive occurence
{
    int i,j,k;

    printf("%d\n",size);
    for(i=0,j=1,k=0; j<size; j+=2,i+=2,k++)
    {

        if(size1==size2)
        {
            array3[i]=array1[k];
            array3[j]=array2[k];
        }
        else if(size1>size2)
        {

            if(k>=size2)
            {

                array3[i]=array1[k];
                array3[j]=0;

            }
            else
            {
                array3[i]=array1[k];
                array3[j]=array2[k];
            }
        }
        else
        {
            if(k>=size1)
            {
                array3[i]=0;
                array3[j]=array2[k];
            }
            else
            {
                array3[i]=array1[k];
                array3[j]=array2[k];
            }
        }
    }
}





int array_RepeatRemove (int*array1,int*new_array,int size1) //consecutive occurence
{
    int size=0;
    for(int i=0; i<size1; i++)
    {
        for(int j=1; j<size1; j++)
        {
            if(i==j)
                continue;
            if(array1[i]==array1[j])
                array1[j]=0;
        }
        if(array1[i]!=0)
            size++;
    }

    array_form(array1,new_array,size1);
    return size;
}
void array_form(int *array1,int*new_array,int size1)
{
    int j=0;
    for(int i=0; i<size1; i++)
    {
        if(array1[i]!=0)
        {

            new_array[j]=array1[i];
            j++;
        }
    }

}

void array_Replace_TwoZeros (int*array1,int size1) // This function replaces the three numbers after the first zero with the three numbers after the second zero
{
    int temp[3];

    int stop;
    int flag=0;
    for(int i=0;i<size1;i++)
    {
        if(array1[i]==0)
        {
            if(flag==0)
            {
                stop=i+1;
                flag=1;
                for(int k=0;k<3;k++)
                    {
                        i++;
                        printf("%d\n",array1[i]);
                        temp[k]=array1[i];
                    }
            }
            else
            {
                for(int k=0;k<3;k++,stop++)
                {
                    i++;
                    array1[stop]=array1[i];
                    array1[i]=temp[k];
                }
            }
        }
    }
}

int array_Biggest_difference(int*array1,int size1) //consecutive occurence
{
   int difference=0;
   for(int i=0;i<size1;i++)
   {
       for(int j=i;j<size1;j++)
       {
           if(array1[j]-array1[i]>difference)
                difference=array1[j]-array1[i];
       }
   }
   return difference;
}



int array_FindMostRepeatedIn_Char(char*array1,int size1,int*most) //consecutive occurence
{
   int repeatNo=0;
   int max=0;
   for(int i=0;i<size1;i++)
   {
       for(int j=i;j<size1;j++)//j=i optimize
       {
           if(array1[i]==most)//optimize code
            break;
           if(array1[i]==array1[j])
           {
               repeatNo++;
           }

       }
       if(repeatNo>max)
       {
           max=repeatNo;
           *most=array1[i];
       }
       repeatNo=0;
   }
    printf("%d\n",max);
    return max;
}


void pointer_swap(int *px,int*py)
{
   int temp;
   temp=*px;
   *px=*py;
   *py=temp;

}



int Find_Fibancii_TERM_N(int n)
{
    // to avoid dynamic allocation and also to account for n increasing over twenty
    int array[100];
    array[0]=0;
    array[1]=1;
    for(int i=2;i<n || i<20;i++)
    {
        array[i]=array[i-1]+array[i-2];
    }
    array_print(array,20);
    return array[n];

}



int mostRepeatedFromMonoNumbers(int*m)
{
    printf("Enter 10 Mono numbers: ");
    int n;
    int count0=0,count1=0,count2=0,count3=0,count4=0,count5=0,count6=0,count7=0,count8=0,count9=0;
    int max=0;
    int mostrepeated;
    for(int i=0; i<9; i++)
    {
        scanf("%d",&n);
        switch (n)

        {
        case 0:
            count0++;
            if(count0>max)
            {
                max=count0;
                mostrepeated=0;
            }
            break;
        case 1:
            count1++;
            if(count1>max)
            {
                max=count1;
                mostrepeated=1;
            }
            break;
        case 2:
            count2++;
            if(count2>max)
            {
                max=count2;
                mostrepeated=2;
            }
            break;
        case 3:
            count3++;
            if(count3>max)
            {
                max=count3;
                mostrepeated=3;
            }
            break;
        case 4:
            count4++;
            if(count4>max)
            {
                max=count4;
                mostrepeated=4;
            }
            break;
        case 5:
            count5++;
            if(count5>max)
            {
                max=count5;
                mostrepeated=5;
            }
            break;
        case 6:
            count6++;
            if(count6>max)
            {
                max=count6;
                mostrepeated=6;
            }
            break;
        case 7:
            count7++;
            if(count7>max)
            {
                max=count7;
                mostrepeated=7;
            }
            break;
        case 8:
            count8++;
            if(count8>max)
            {
                max=count8;
                mostrepeated=8;
            }
            break;
        case 9:
            count9++;
            if(count9>max)
            {
                max=count9;
                mostrepeated=9;
            }
            break;
        default :
            return -1;

        }

    }
    *m=max;
    return mostrepeated;

}


int mostRepeatedFromMonoNumbers_ARRAY(int *maxnumber)
{
    char array[10];
    int n;
    for(int i=0;i<10;i++)
    {
        scanf("%d",&n);
        if(n<0 || n>9)
            return 1;
        array[i]=n;

    }
    return array_FindMostRepeatedIn_Char(array,10,maxnumber);
}



int array_find_longest_Consecutive_chain(int*array,int size,int*ptrIndex)
{
    int c=0,max=0;
    int j;
    for(int i=0;i<size-1;i++)
    {
        if(array[i]+1==array[i+1]) // i+1 will make us get out of the array thats why we used "size-1" or simply use i-1 but you will have to start with i=1
        {
            c++;
            if(c>max)
            {
                max=c;
                j=i;
            }
        }
        else
        {
            c=0;
        }
    }
    *ptrIndex=j+1-max;
    max++;
    return max;
}

void arraySwapAfterZeros(int*arr)
{
    int i,index1,index2,flag=0;;
    for(i=0;flag<2;i++)
    {
        if(arr[i]==0&&flag==0)
        {
            index1=i;
            flag=1;
        }
        else if(arr[i]==0 && flag==1)
        {
            index2=i;
            flag=2;
            break;
        }
    }
    swap(&arr[index1+1],&arr[index2+1]);
    swap(&arr[index1+2],&arr[index2+2]);
    swap(&arr[index1+3],&arr[index2+3]);
}



void string_print(char*array)
{
    for(int i=0;array[i];i++)
    {
        printf("%c",array[i]);
    }
    printf("\n");
}


int string_length(char* array) // not similar to sizeof because size of brings back the size of the char including the null size
{
    int i;
    for(i=0;array[i];i++);
    return i;
}

void tolower_string(char*str)
{
    for(int i=0;str[i];i++)
    {
        if(str[i]>='A' && str[i]<='Z')
            str[i]+='a'-'A';
    }
}



void toupper_string(char*str)
{
    for(int i=0;str[i];i++)
    {
        if(str[i]>='a' && str[i]<='z')
            str[i]-='a'-'A';
    }
}



int checkIfStringIdentical(char*str1,char*str2)
{
    int flag=1;
    for(int i=0;str1[i] || str2[i];i++)
    {
       if(str1[i]!=str2[i])
       {
           flag=0;
           break;
       }

    }
    return flag;
}


int string_compare(char*str1,char*str2)
{
    int l1=string_length(str1);
    int l2=string_length(str2);
    if(l1!=l2)
        return 0;
    for(int i=0;str1[i];i++)
    {
       if(str1[i]!=str2[i])
       {
           return 0;
       }
    }
    return 1;
}





void string_reverse(char* str)
{
   int size=string_length(str);
   int i=size-1;
   str[size]='\0';
   char temp;
   for(int j=0;i>=size/2;i--,j++) // or i!=j in condition
   {
       temp=str[j];
       str[j]=str[i];
       str[i]=temp;
   }


}



int string_If_Mirror(char* str)
{
   int size=string_length(str);
   printf("%d\n",size);

   int i=0,j=size-1;;

   if(size%2==0)
   {
       return 0;
   }
   else
   {
        for(;i<size;i++,j--)
        {
            if(str[i]!=str[j])
                return 0;
        }
   }

   return 1;



}



int isspace(char x)
{
    if(x!=32)
        return 1;
    else
        return 0;
}

void string_scan(char*str,int max)
{
    int i=0;
    scanf("%c",&str[i]);// we put space here in case we used a scanf before there will be a space in the buffer which will make us exit the loop before we even start
    for(; str[i]!='\n' && i<max-1;)//-1 3alshan ha7pt el null fel postion el akher
    {
        i++;
        scanf("%c",&str[i]);
    }
    str[i]=0;
}


void string_longest_word(char*str,char*word)
{
    int i,c=0,max=0,index=0,j=0;
    for(i=0; str[i]; i++)
    {
        if(str[i]==' ')
        {
            if(c>=max)
            {
                max=c;
                index=i;//i here is the space after the large word
            }
            c=0;

        }
        else
            c++;
    }
    if(c>=max)
    {
        max=c;
        index=i;// will be the null
    }
    i=index-max;
    for(j=0;i<index;) // condition might be j<max
    {
        word[j]=str[i];
        j++;
        i++;
    }
    word[j]=0;
}

void string_reverse_part(char*str,int f,int l)
{
   int i=f;
   char temp;
   int j=l;
   for(;i<=j;i++,j--) // or i!=j in condition
   {
       temp=str[i];
       str[i]=str[j];
       str[j]=temp;
   }
}



void integer_to_string(char*str,long int n)
{
    int i=0,rem;
    int flag=0;
    if(n==0)
    {
        str[0]='0';
        str[1]=0;
        return;
    }

    else
    {
        if(n<0)
        {
            n=n*-1;
            flag=1;
        }

        while(n)
        {
            rem=n%10;
            rem+='0';
            str[i]=rem;
            i++;
            n/=10;
        }
        if(flag==1)
        {
            str[i++]='-';
        }
        str[i]=0;
        string_reverse(str);
    }

}



int string_to_integer(char*str)//"50123"
{
    int length=string_length(str);
    int weight=length-1;
    int counter=1;
    int flag=0;
    int j=0;
    int decimal=0;
    //char digits[]={0,1,2,3,4,5,6,7,8,9};
    if(str[0]=='-')
    {

        flag=1;
    }
    for(int i=weight;i>=0;i--)
    {

        if(str[i]>='0' && str[i]<='9')// if he entered something other than digits
        {
            decimal+=(str[i]-'0')*counter;
            counter*=10;
        }

    }
    if(flag==1)
        decimal*=-1;
    return decimal;
}

int string_to_integer2(char*str)//"50123"
{
    int num=0;
    for(int i=0;str[i];i++)
    {
        if(str[i]>='0' && str[i]<='9')
            num=num*10+(str[i]-'0');


    }
    return num;
}
int string_to_integer3(char*str,int*pnum)//"50123"
{
    int num=0;
    int i=0;
    int flag=0;
    if(str[0]=='-')
       {
         flag=1;
         i=1;
       }

    for(;str[i];i++)
    {
        if(str[i]>='0' && str[i]<='9')
        {
            num=num*10+(str[i]-'0');
        }
        else
            return 0;



    }
    if(flag==1)
        num*=-1;
    *pnum=num;
    return 1;
}

void reverse_string_fullWords(char*str) // we will reverse two times one with the whole string and then each word at a time
{
    string_reverse(str);
    int f=0,l;
    int flag;
    int j;
    for(j=0;str[j];j++)
    {
        flag=0;
        if(str[j]==' ')
        {
            l=j-1;
            flag=1;
        }
        if(flag==1)
        {
            string_reverse_part(str,f,l);// these are the first and last index of the word
            printf("j=%d  f=%d  l=%d\n",j,f,l);
            f=j+1;

        }
    }
    l=j-1;// to reverse the last word while taking care of the null
    string_reverse_part(str,f,l);
}


 int string_Triangle(char*str,char*triangle)// we will make it integer to return whether it's a triangle or not
{
    int side1=0,side2=0,side3=0;
    int flag=1;
    char equi[]="Equilateral triangle";
    char iso[]="Isosceles triangle";
    char scal[]="scalene triangle";
    for(int i=0;str[i];i++)
    {
        if(flag==1)
        {
            side1=side1*10+(str[i]-'0');
        }
        else if(flag==2)
        {
            side2=side2*10+(str[i]-'0');
        }
        else if(flag==3)
        {
            side3=side3*10+(str[i]-'0');
        }
        if(str[i+1]==' ') // don't use ++i because each time the condition gets checked i is incremented
        {
            flag++;
            i++;

        }
    }
    if(side1+side2>side3 &&side1+side3>side2&&side3+side2>side1)
    {
        if(side1==side2  && side2==side3)
        {
            //triangle="Equilateral triangle";  this is wrong because triangle is and address you cant store in it like this
            string_duplicate(triangle,equi);
        }
        else if(side1==side2 || side1==side3 || side2==side3)
        {
            string_duplicate(triangle,iso);
        }
        else
        {
            string_duplicate(triangle,scal);
        }
        return 1;
    }
    else
    {
        return 0;
    }

}
void string_duplicate(char*str1,char*str2)
{
    int i=0;
    while(str2[i])
    {
        str1[i]=str2[i];
        i++;
    }
    str1[i]=0;
}



float string_to_float(char*str)
{
    int i=0;
    float n1=0;
    float n2=0;
    int flag=0;
    while(str[i])
    {
        if(str[i]=='.')
        {
            flag=1;
            i++;
        }
        if(flag==0)
            n1=n1*10+(str[i]-'0');
        else if(flag==1)
            n2=n2*10+(str[i]-'0');
        i++;
    }
    int counter=10;
    while((n2/counter>1))
    {
        counter*=10;
    }

    return (n1+n2/counter);
}



void float_to_string(char*str,float n)//3.15
{
    long int trunc;
    float change=n-trunc;
    int i=0;
    long long int counter=1;
    for(;;i++)// get integer from float 3.122
    {

        trunc=n*counter;

        if((float)trunc==n*counter)
        {
            printf("trunc=%d     n=%f\n",trunc,n);
            break;
        }

        counter*=10;
        printf("trunc=%d     n=%f\n",trunc,n);

    }
    printf("trunc=%d\n",trunc);
    //number comes out multiplied by 10 more so we replace the last zero with dot
    trunc*=10;
    integer_to_string(str,trunc);

    int length=string_length(str);
    int j=length-1;//     3150
    while(j>=0)
    {
       if(j!=length-i-1)
       {
           str[j]=str[j-1];
       }
       else
       {
           str[j]='.';
           break;
       }

       j--;

    }
    printf("i=%d  length=%d   dot=%d\n",i,length,length-i-1);



}




void string_Find_and_replace(char*str,char*find,char*replace)
{

    int lenFind=string_length(find);
    int lenreplace=string_length(replace);
    int lenstr=string_length(str);
    int l=find[lenFind-1],f=find[0];
    int j=0;
    int difflen=lenreplace-lenFind;
    int flag=0;
    int startindex=0;
    for(int i=0; str[i]; i++) //find
    {
        j=0;
        if(str[i]==f)
        {
            startindex=i;
            while(str[i]==find[j] && str[i]!=0)
            {
                i++;
                j++;
            }
            if(j==lenFind)
            {
                flag=1; //found
                break;
            }
        }
    }
    l=startindex+lenFind-1;
    int k=difflen;
    int temp;
    // printf("index F =%d   letter=%c   length=%d   flag=%d  difflen=%d\n",startindex,str[startindex],lenFind,flag,difflen);
    if(flag==1)//found and we have the first index
    {
        if(difflen>=0)
        {
            for(int i=lenstr-1; i!=l; i--) //shift loop
            {
                str[i+difflen]=str[i];

            }

            for(int i=startindex,p=0; p<lenreplace; p++,i++)
            {
                str[i]=replace[p];
                // printf("i=%d\n",i);
            }
            str[lenstr+difflen+1]=0;
        }
        else
        {
            for(int i=l+difflen+1;str[i];i++) //shift loop
            {
                str[i]=str[i-difflen];

            }

            for(int i=startindex,p=0; p<lenreplace; p++,i++)
            {
                str[i]=replace[p];
                // printf("i=%d\n",i);
            }
            str[lenstr+difflen+2]=0;

        }




    }
    else//not found
    {

    }
}


void string_print_part(char*array,int f,int l)
{
    for(int i=f;i<l;i++)
    {
        printf("%c",array[i]);
    }
    printf("\n");
}

void string_PrintWordsAsTheirNumbers(char*str)
{
    int flag=0;
    int number1=0;
    int firstcomma;
    int lastcomma;
    int secondcomma;
    int number2=0;
    for(int i=0;str[i];i++)
    {
        if(str[i]==',' && flag==0)
        {
           firstcomma=i;
           while(str[i+1]!=',')
           {


                i++;
                if(str[i]>='0' && str[i]<='9')
                number1=number1*10+str[i]-'0';
                if(str[i+1]==',')
                {
                    flag=1;
                    secondcomma=i+1;
                }

           }

        }
        else if(str[i]==',' &&flag==1)
        {
            lastcomma=i;
            while(str[i+1]!=',' && str[i+1]!=0)
            {
                i++;
                if(str[i]>='0' && str[i]<='9')
                number2=number2*10+str[i]-'0';
            }


        }
    }
    printf("n1=%d   first comma=%d  n2=%d\n",number1,firstcomma,number2);
    for(int i=0;i<number1;i++)
        string_print_part(str,0,firstcomma);
    for(int i=0;i<number2;i++)
        string_print_part(str,secondcomma+1,lastcomma);

}




void longestEvenWord(char*str)
{
    int max=0;
    int counter=0;
    int firstindex=0;
    for(int i=0; str[i]; i++)
    {
        counter=0;
        while(str[i]!=' ' && str[i]!=0)
        {
            counter++;
            i++;

        }
        if(counter>max && counter%2==0)
        {
            max=counter;
            firstindex=i-max;
        }
    }
    printf("f=%d  total length =%d max=%d \n",firstindex,string_length(str),max);
    if(max==0)
    {
        printf("00\n");
    }
    else
    {
        for(int i=firstindex; i<firstindex+max; i++)
        {
            printf("%c",str[i]);
        }
        printf("\n");
    }
}

int*array_scan_dynamic(void)
{
    int size;
    scanf("%d",&size);
    int *arr=(int*)malloc(size*sizeof(size));
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    return arr;
}




int* array_remove_repeat(int*arr,int size,int *pn_size)
{
    int *arrayNew=(int*)malloc(size*sizeof(int));
    int i,j=0,flag=1;
    for(i=0;i<size;i++)
    {
        flag=1;
        for(int k=0;k<i;k++)
        {
            if(arr[i]==arr[k])
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            arrayNew[j]=arr[i];
            j++;
        }
        else
        {
            arrayNew[j]=0;
            j++;
        }
    }
    *pn_size=j;
    arrayNew=realloc(arrayNew,j*4); // btakhod 3dd el bytes  (Optimization)
    return arrayNew;
}


int* array_merge_dynamic(int*arr1,int s1,int*arr2,int s2,int*newsize)
{
    int i,j=0;
    int size=s1+s2;
    int *arrnew=(int*)malloc(size*sizeof(int));
    if(arrnew==0)
    {
        *newsize=0;//no memory available in the heap
        return 0;
    }
    for(i=0;i<size;i++)
    {
        if(i%2==0)
        {
            arrnew[i]=arr1[j];
        }
        else
        {
            arrnew[i]=arr2[j];
            j++;// 3alshan akhod i mara we j marteen
        }
    }
        *newsize=size;
        return arrnew;
    }


    int* array_merge_dynamic2(int*arr1,int s1,int*arr2,int s2,int*newsize)
{
    int i,j=0;
    int size=s1+s2;
    int size1=s1>s2?s2:s1;
    size1=size1*2;
    int *arraymax=s1>s2?arr1:arr2;
    int *arrnew=(int*)malloc(size*sizeof(int));
    if(arrnew==0)
    {
        *newsize=0;//no memory available in the heap
        return 0;
    }
    for(i=0;i<size1;i++)
    {

        if(i%2==0)
        {
            arrnew[i]=arr1[j];
        }
        else
        {
            arrnew[i]=arr2[j];
            j++;// 3alshan akhod i mara we j marteen
        }
    }
        for(;i<size;i++)
        {
            arrnew[i]=arraymax[j];
            j++;
        }

        *newsize=size;
        return arrnew;

        /*
        arrnew[i]=arr1[j];
        if(i+1==size)
            break;
        arrnew[i+1]=arr2[j];
        j++;
        */


}

int array_most_repeated2(int*arr,int size,int*pnum)
{
    int i,j,c=0,max=0,c2=0;
    for(i=0;i<size;i++)
    {
        c=0;
        for(j=i;j<size;j++)
        {
            if(arr[i]==arr[j])
            {
                c++;
            }
            c2++;
        }
        if(c>max)
        {
            max=c;
            *pnum=arr[i];
        }
    }
    printf("c2=%d\n",c2);
    return max;

}


int array_binary_search(int*arr,int size,int num) // this function must be sorted first
{
    int f=0,l=size-1,m,c=0;
    while(f<=l)
    {   c++;
        printf("c=%d\n",c);
        m=(f+l)/2;
        if(arr[m]==num)
        {
            return m;
        }
        else if(num<arr[m])
        {
            l=m-1;
        }
        else
        {
            f=m+1;
        }
    }
    return -1;// not present




}

int array_most_repeated_mononumber(int*arr,int size,int*pnum) //frequency array
{
    int i,max=0,count[10]={0};
    for(int i=0;i<size;i++)
    {
        count[arr[i]]++;
    }
    for(int i=0;i<10;i++)
    {
        if(count[i]>max)
        {
             max=count[i];
             *pnum=i;
        }

    }
    return max;
}


int array_most_repeated_anynumber_Min0(int*arr,int size,int*pnum) //frequency array
{
    int i,max=0,count_size,max_num=0,min_num=0;
    for(int i=0;i<size;i++)
    {
        if(max_num<arr[i])
            max_num=arr[i];
    }
    count_size=max_num-min_num+1;
    int*count=(int*)calloc(count_size,sizeof(int));
    if(count==0)
        // ro7 estkhdm el code el bate2
      for(int i=0;i<count_size;i++)
    {
        count[arr[i]]++;
    }
    for(int i=0;i<count_size;i++)
    {
        if(count[i]>max)
        {
             max=count[i];
             *pnum=i;
        }

    }
    free(count);
    return max;
}


int array_most_repeated3(int*arr,int size,int*pnum)//O(n^2)

{
    int i,j,c=0,max=0,c2=0;
    for(i=0; i<size; i++)
    {
        c=0;
        for(j=i; j<size; j++)
        {
            if(arr[i]==arr[j])
            {
                c++;
            }
            c2++;
        }
        if(c>max)
        {
            max=c;
            *pnum=arr[i];
        }
    }
    printf("c2=%d\n",c2);
    return max; // number of repetitions

}

int array_most_repeated_anynumber_MinVALUE(int*arr,int size,int *pnum)
{
    int max_num=arr[0],min_num=arr[0],count=0;
    //Find the maximum and the minimum in the array
    for(int i=0; i<size; i++)
    {
        if(arr[i]>max_num)
        {
            max_num=arr[i];
        }
        if(arr[i]<min_num)
        {
            min_num=arr[i];
        }
    }
    //calculate the number of odds(K)
    count=max_num-min_num+1;
    int*count_array=(int*)calloc(count,sizeof(int));//frequency array----->>O(K)
    int max;
    if(count_array==0) // safety from null pointer
    {
        max=array_most_repeated3(arr,size,pnum);
    }

    else
    {
        for(int i=0; i<size; i++)
        {
            count_array[arr[i]-min_num]++;
        }
        for(int i=0; i<count; i++)
            printf("%3d    %3d\n",i+min_num,count_array[i]);
        max=count_array[0];
        for(int i=0; i<count; i++)
        {
            if(count_array[i]>max)
            {
                max=count_array[i];
                *pnum=i+min_num; // maximum number itself
            }


        }
    }

    return max;//no. of repetitions





}
 int array_find_Repeated(int*arr,int size)
 {
     int*freq_array=(int*)calloc(size,sizeof(int));
     for(int i=0;i<size;i++)
     {
         freq_array[arr[i]]++;
     }
     for(int i=0;i<size;i++)
        printf("%d    %d\n",i,freq_array[i]);
     for(int i=0;i<size;i++)
     {
         if(freq_array[i]==2)
         {
             return i;
         }
     }


 }
  int array_find_missing(int*arr,int size)
 {
     int*freq_array=(int*)calloc(size+1,sizeof(int));
     for(int i=0;i<size;i++)
     {
         freq_array[arr[i]]++;
     }
     for(int i=0;i<size+1;i++)
        printf("%d    %d\n",i,freq_array[i]);
     for(int i=0;i<=size;i++)
     {
         if(freq_array[i]==2)
         {
             return i;
         }
     }


 }



 /*You have an array of integers all numbers in the array repeated 2 times except one number repeated one time only
find this number (try o(n)). array like {1,2,4,66,2,1,500,66,7,7,500}->4.
4) repeat Q3 but array is sorted (try less than O(n)).
array {1,1,2,2,4,4,70,70,73,80,80,81,81} ->73.*/
 int array_find_not_repeated(int*arr,int size)
 {
     int max=arr[0],min=arr[0],count_size;
     for(int i=0;i<size;i++)
     {
         if(arr[i]>max)
            max=arr[i];
         if(arr[i]<min)
            min=arr[i];
     }
     count_size=max-min+1;
     int*freq_array=(int*)calloc(count_size,sizeof(int));
     for(int i=0;i<size;i++)
     {
         freq_array[arr[i]-min]++;
     }
     for(int i=0;i<count_size;i++)
        printf("%d    %d\n",i+min,freq_array[i]);
     for(int i=0;i<count_size;i++)
     {
         if(freq_array[i]==1)
         {
             return i+min;
         }
     }


 }


 /*8) . Write C function to take an array and if it finds a number "given" makes the
previous elements in a new array and returns it (try to optimize).*/
int* array_return_untilCertainNumber(int*arr,int size,int num,int*newsize) // we will try to optimize the heap memory consumption
{
    int flag=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i]==num)
            break;
        flag++;
    }
    int*array2=(int*)calloc(flag,sizeof(int));
    for(int i=0;i<flag;i++)
    {
        array2[i]=arr[i];
    }
    *newsize=flag;
    return array2;

}

void array_Bubble_sort_Descending(int*arr,int size) //bubble sort
{
    int i,temp,c=0,flagIfSoarted=0;
    for(int j=0; j<size; j++)
    {
        flagIfSoarted=1; // to get out as soon as it gets sorted without needing to go on
        for(i=0; i<size-1-j; i++)
        {

            if(arr[i]<arr[i+1])
            {
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                flagIfSoarted=0;

            }
            c++;
        }
        if(flagIfSoarted==1)
            break;
    }
    printf("c is %d\n",c);

}
void array_Bubble_sort_Ascending(int*arr,int size) //bubble sort
{
    int i,temp,c=0,flagIfSoarted=0;
    for(int j=0; j<size; j++)
    {
        flagIfSoarted=1; // to get out as soon as it gets sorted without needing to go on
        for(i=0; i<size-1-j; i++) // negative j 3alshan ma3edsh el ana already 3amelo sort hatwfr nos el wa2t
        {

            if(arr[i]>arr[i+1])
            {
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                flagIfSoarted=0;

            }
            c++;
        }
        if(flagIfSoarted==1)
            break;
    }
    printf("c is %d\n",c);

}


void array_Selection_sort_Ascending(int*arr,int size) //selection sort if you want descending just use the opposite sign
{
    int max=arr[0],min=arr[0];
    int index,temp;
    for(int j=0;j<size;j++)
    {
        max=arr[0];
        index=0;
        //max=min
        for(int i=0;i<size-j;i++)
        {
            if(arr[i]>max)
            {
                max=arr[i];
                index=i;
            }
            if(arr[i]<min)
            {
                min=arr[i];
            }

        }
        temp=arr[index];
        arr[index]=arr[size-j-1];
        arr[size-j]=temp;
    }

}
void array_Selection_sort_Ascending2(int*arr,int size)
{
    int min=arr[0],temp,index;
    for(int j=0;j<size;j++)
    {
        min=arr[size-1];
        index=size-1;
        for(int i=size-1;i>=j;i--)
        {
            if(arr[i]<min)
            {
                index=i;
                min=arr[i];
            }
        }
        temp=arr[index];
        arr[index]=arr[j];
        arr[j]=temp;
    }
}




int array_find_max(int*arr,int size)
{
        int max=arr[0];
        int index=0;
        //max=min
        for(int i=0;i<size;i++)
        {
            if(arr[i]>max)
            {
                max=arr[i];
                index=i;
            }
            size--;
        }
        return index;

}

void array_Selection_sort_Ascending3(int*arr,int size) //selection sort if you want descending just use the opposite sign
{
    int max=arr[0],min=arr[0];
    int index,temp;
    for(int j=0;j<size;j++)
    {
        index=array_find_max(arr,size);
        swap(&arr[index],&arr[size-j-1]);
    }

}

void array_counting_sort_mono(int*arr,int size)
{
    int count[10]={0};
    int i,j;
    for(i=0;i<size;i++)
    {
        count[arr[i]]++;
    }
    j=0;
    for(i=0;i<10;i++)
    {
        while(count[i])
        {
            arr[j]=i;
            count[i]--;
            j++;
        }
    }

}




void array_bubble_sort_2(int*arr,int size) // best case when the array is already sorted while the worst case is when the array is sorted in the opposite direction
{
    int i,j,temp,flag=0,c=0;
    for(int j=0;j<size;j++)
    {
        flag=0;// to check if it has been sorted out yet
        for(int i=0; i<size-1-j; i++)
        {
            if(arr[i]>arr[i+1])
            {
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                flag=1;
            }
            c++;
        }
        if(flag==0)
        {
            break;
        }
    }
    printf("c=%d\n",c);
}


void array_selection_sort2(int*arr,int size)
{
    int i,j,max=arr[0],index=0,temp;
    for(int j=0; j<size; j++)
    {
        max=arr[0];
        index=0;
        for(int i=0; i<size-j; i++)
        {
            if(arr[i]>max)
            {
                max=arr[i];
                index=i;
            }
        }
        temp=arr[index];
        arr[index]=arr[size-1-j];
        arr[size-1-j]=temp;
    }
}
void array_selection_sort3(int*arr,int size)
{
    int i,j,temp,index=0,min=arr[0];
    for(int j=0; j<size; j++)
    {
        min=arr[size-1];
        index=size-1;
        for(int i=size-1; i>=j; i--)
        {
            if(arr[i]<min)
            {
                min=arr[i];
                index=i;
            }
        }
        temp=arr[index];
        arr[index]=arr[j];
        arr[j]=temp;
    }

}



void array_counting_sort(int*arr,int size)
{
    int max=arr[0],min=arr[0],k;
    for(int i=0;i<size;i++)
    {
        if(arr[i]>max)
            max=arr[i];
        if(arr[i]<min)
            min=arr[i];
    }
    k=max-min+1;
    int*freq_array=(int*)calloc(k,sizeof(int));
    for(int i=0;i<size;i++)
    {
        freq_array[arr[i]-min]++;
    }
    int j=0;
    for(int i=0;i<k;i++)
    {
        while(freq_array[i])
        {
            arr[j]=i+min;
            j++;
            freq_array[i]--;
        }
    }


}


static int z=9;

int array_find_not_repeated2(int*arr,int size)
{
    int i=0,j=1;
    while(j<size)
    {
       if(arr[j]==arr[i])
       {
           i+=2;
           j+=2;

       }
       else
       {
           return arr[i];
       }

    }

    return arr[i];
}

void Swap_First_SECOND_words(char* str) // works for different word sizes
{


    int flag1=0,flag2=0,size1,size2;
    int index11,index12,index21,index22;

    for(int i=0; str[i]; i++)
    {
        if(str[i]!=' ' && flag1==0)
        {
            index11=i;
            flag1=1;
        }
        else if(str[i]==' ' && flag1==1)
        {
            index12=i-1;
            index21=i+1;
            flag1=2;
        }
        else if(str[i]==' ' && flag1==2)
        {
            index22=i-1;
            break;
        }
    }
    size1=index12-index11+1;
    size2=index22-index21+1;
    char*word1=(char*)calloc(size1,1);
    char*word2=(char*)calloc(size2,1);
    //printf("size of first word=%d   size of second word=%d\n",size1,size2);
    for(int i=0; i<size1; i++)
    {
        word1[i]=str[index11];
        index11++;
    }
    word1[index11]=0;
    for(int i=0; i<size2; i++)
    {
        word2[i]=str[index21];
        index21++;
    }
    word2[index21]=0;
    int i;
    for(i=0; word2[i]; i++)
    {
        str[i]=word2[i];
    }
    str[i]=' ';
    i++;
    int j=0;
    for(; word1[j]; i++)
    {
        str[i]=word1[j];
        j++;
    }
    //string_print(word1);
    //string_print(word2);




}


void SwapTwoPointers(char**pp1,char**pp2)
{
    char*temp;
    temp=*pp1;
    *pp1=*pp2;
    *pp2=temp;
   // printf("*p1=%d   *p2=%d\n",**pp1,**pp2);
}


void print_ArrayOfPointersToFixedNames(char**array,int size)
{

    for(int i=0;i<size;i++) // contains addresses
    {
        string_print(array[i]); // array[i] is an address itself
    }
}

void print_ArrayOfPointersToFixedNames_WithSwapingFirstTwoNames(char**array,int size)
{
    SwapTwoPointers(array,array+1);
    for(int i=0;i<size;i++) // contains addresses
    {
        string_print(array[i]); // array[i] is an address itself
    }
}




int checkIfStringIdentical_caseInsensitive(char*str1,char*str2)
{
    int flag=1;

    for(int i=0; str1[i] || str2[i]; i++)
    {

        if(tolower(str1[i])!=tolower(str2[i]))
        {
            flag=0;
            break;
        }

    }
    return flag;
}
int tolower (char x)
{
    if(x>='A' && x<='Z')
        x+='a'-'A';
    return x;
}

int toupper (char x)
{
    if(x>='a' && x<='z')
        x-='a'-'A';
    return x;
}
char* Pointer_Search(char**array,int size,char*word) // search for a word in an array of pointers
{
    int flag;
    char*data;
    for(int i=0; i<size; i++)
    {
        flag=checkIfStringIdentical_caseInsensitive(array[i],word);
        if(flag==1)
        {
            data="Word found";
            break;
        }

    }

    if(flag==0)
        data="Word not found";

    return data;
}



void bubbleSort_ArrayOfPointersContainingWords2(char**array,int size)
{
   int i,temp,c=0,flagIfSoarted=0;
    for(int j=0; j<size; j++)
    {
        flagIfSoarted=1; // to get out as soon as it gets sorted without needing to go on
        for(i=0; i<size-1-j; i++) // negative j 3alshan ma3edsh el ana already 3amelo sort hatwfr nos el wa2t
        {

            if(string_compare_case_insenstive_forSortingAscendingly(array[i],array[i+1]))
            {
                SwapTwoPointers(&array[i],&array[i+1]);
                flagIfSoarted=0;

            }

        }
        if(flagIfSoarted==1)
            break;
    }

}


int string_compare_case_insenstive_forSortingAscendingly(char*str1,char*str2) // this function will return one if the first word is greater than the 2nd
{

    for(int i=0; str1[i] || str2[i]; i++)
    {
        if(tolower(str1[i])<tolower(str2[i]))
        {
            return 0;
        }
        else if(tolower(str1[i])>tolower(str2[i]))
        {
            return 1;
        }

    }
    return 0;
}


void bubbleSort_ArrayOfPointersContainingWords(char**array,int size)
{
   int i,temp,c=0,flagIfSoarted=0;
    for(int j=0; j<size; j++)
    {
        flagIfSoarted=1; // to get out as soon as it gets sorted without needing to go on
        for(i=0; i<size-1-j; i++) // negative j 3alshan ma3edsh el ana already 3amelo sort hatwfr nos el wa2t
        {

            if(string_compare_case_insenstive_forSortingAscendingly(array[i],array[i+1]))
            {
                SwapTwoPointers(&array[i],&array[i+1]);
                flagIfSoarted=0;

            }

        }
        if(flagIfSoarted==1)
            break;
    }

}


int Find_Max_wordInAnArray(char*str1,char*str2)
{
    int i=0;
    for(;str1[i]||str2[i];i++)
    {
        if(tolower(str1[i])>tolower(str2[i]))
            return 1;
        else if(tolower(str1[i])<tolower(str2[i]))
            return 0;
    }
}

void array_selection_sort_array_of_pointers(char**arr,int size)
{
    int i,j,max=arr[0],index=0,temp;
    for(int j=0; j<size; j++)
    {
        max=arr[0];
        index=0;
        for(int i=0; i<size-j; i++)
        {
            if(Find_Max_wordInAnArray(arr[i],max))
            {
                max=arr[i];
                index=i;
            }
        }

        pointer_swap(&arr[index],&arr[size-1-j]);
    }
}

int string_compare_case_BinarySearchOfWords(char*str1,char*str2) // this function will return one if the first word is greater than the 2nd
{

    for(int i=0; str1[i] || str2[i]; i++)
    {
        if(tolower(str1[i])>tolower(str2[i]))
        {
            return 0;
        }
        else if(tolower(str1[i])<tolower(str2[i]))
        {
            return 1;
        }

    }
    return -1;
}


int array_binary_search_array_ofPointers(char**arr,int size,char* num) //In binary search the array has to be sorted
{
    bubbleSort_ArrayOfPointersContainingWords(arr,size);
    int f=0,l=size-1,m,value;
    while(f<=l)
    {
        m=(f+l)/2;

        value=string_compare_case_BinarySearchOfWords(arr[m],num);
        if(value==-1)
        {
            return m;
        }
        else if(value==0)
        {
            l=m-1;
        }
        else
        {
            f=m+1;
        }
    }
    return -1;// not present
}


void string_printNUmbers(char*array)
{
    for(int i=0;i<26;i++)
    {
        printf("%d\n",array[i]);
    }
}



char* pangrams(char* s)
{
    int i;
    char*alphabet=(char*)calloc(26,1);
    i=0;
    while(s[i])
    {
        if((s[i])>='a' && (s[i])<='z')
        {
            alphabet[s[i]-'a']++;
        }
        else if(s[i]>='A' && s[i]<='Z')
        {
            alphabet[s[i]-'A']++;
        }

        i++;
    }


    char* rvalue;
    for(int i=0;i<26;i++)
    {
        if(alphabet[i]==0)
        {
            printf("i am here %d\n",i);
            rvalue="not pangram";
            break;
        }
        rvalue ="pangram";
    }

    return rvalue;
}

char* string_merge(char*str1,char*str2)
{
    int l1=string_length(str1);
    int l2=string_length(str2);
    int newsize=l1+l2,lmax;
    char*maxstr;
    if(l1>l2)
    {
        maxstr=str1;
    }
    if(l2>l1)
    {
        maxstr=str2;
    }


    char * str_new =(char*)malloc((l1+l2)*sizeof(char));
    int i=0,j=0;
    for(;str1[j] && str2[j];i++)
    {
        if(i%2==0)
        {
            str_new[i]=str1[j];
        }
        else
        {
            str_new[i]=str2[j];
            j++;
        }

    }
    for(;i<=newsize;i++)
    {
        str_new[i]=maxstr[j];
        j++;
    }
    return str_new;
}


int array2D_print(int matrix[][100],int row,int col)
{
    int i=0,j=0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("%3d ",matrix[i][j]);
        }
        if(i!=row-1)
            printf("->");
    }
}


int array2D_print2(char matrix[9][9],int row,int col)
{
    int i=0,j=0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("%3d ",matrix[i][j]);
        }
        printf("\n");
    }
}

int matrix_cal_sum_diagonals(int matrix[][100],int row,int col)
{
    if(row!=col)
        return 0;
    else
    {
        int diagonal1=0,diagnoal2=0;
        int last=row-1;
        printf("last=%d\n",last);
        for(int i=0;i<row;i++)
        {
           diagonal1+=matrix[i][i];
           diagnoal2+=matrix[i][last];
           last--;
        }
        printf("diag1=%d   diag2=%d\n",diagonal1,diagnoal2);
        if(diagonal1==diagnoal2)
            printf("Equal diagonals\n");

        else
            printf("Not equal diagonals\n");
        return 1;

    }
}

void array2D_print_ZIAGZAG(int matrix[][100],int row,int col)
{
    int i=0,j=0,flag=1;
    for(i=0;i<row;i++)
    {
        for(;;)
        {
           if(j>=col || j<0)
                break;
           printf("%3d ",matrix[i][j]);
           if(flag==1)
           {
               j++;
           }
           else
           {
               j--;
           }

        }
        if(flag==0)
        {
            j=0;
            flag=1;
        }
        else
        {
            j=col-1;
            flag=0;
        }
        if(i!=row-1)
            printf("->");
    }
}



 // we can keep it with /,/,\,\ but we will either overwrite on the array or copy it to another array which will be time and memory consuming
void star_set(char arr[][30],int row,int col,int x,int y)
{
    int i=0,j=0;
    arr[x][y]='*';
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(i>x && (j==y))
            {
                arr[i][j]='^';
            }
            else if(i<x && (j==y))
            {
                arr[i][j]='v';
            }
            else if(j>y && (i==x))
            {
                arr[i][j]='<';
            }
            else if(j<y && (i==x))
            {
                arr[i][j]='>';
            }
            else if(i<x && (j<y)) //top left
            {
                arr[i][j]='\\';
            }
            else if(i<x && (j>y)) //top right
            {
                arr[i][j]='7';
            }
            else if(i>x&& (j<y)) //bottom left
            {
                arr[i][j]='/';
            }
            else if(i>x && (j>y)) // bottom right
            {
                arr[i][j]='`';
            }

            else
            {
                arr[i][j]='0';
            }
        }
    }
    arr[x][y]='*';
}
void star_print(char arr[][30],int row,int col)
{
    int i=0,j=0;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("%c ",arr[i][j]);

        }
        printf("\n");
    }
}
void star_find(char arr[][30],int row,int col,int*px,int*py)
{
    int i=0,j=0;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            if(arr[i][j]=='*')
            {
                *px=i;
                *py=j;
            }
        }
    }
}
void star_find_binary_search(char arr[][30],int row,int col,int*px,int*py)
{
    int frow=0,lrow=row-1,fcol=0,lcol=col-1,mrow,mcol;
    while(fcol<=lcol && frow<=lrow)
    {
        mrow=(frow+lrow)/2;
        mcol=(fcol+lcol)/2;
        if(arr[mrow][mcol]=='*')
        {
            *px=mrow;
            *py=mcol;
            break;
        }
        switch(arr[mrow][mcol])
        {
        case '<':
            lcol=mcol-1;
            break;
        case '>':
            fcol=mcol+1;
            break;
        case 'v':
            frow=mrow+1;
            break;
        case '^':
            lrow=mrow-1;
            break;
        case '/':
            fcol=mcol+1; // bottom left corner
            lrow=mrow-1;
            break;
        case '`':
            lcol=mcol-1; //bottom right corner
            lrow=mrow-1;
            break;
        case '7':
            lcol=mcol-1;  //top right
            frow=mrow+1;
            break;
        case '\\':
            fcol=mcol+1; //top left (although 4 slashes will print the same as two slashes it has different weight)
            frow=mrow+1;
            break;
        }
    }
    //printf("%c    %c    %c    %c\n",'/////','/','\\','\\\\\\'); // all are the same as they will be trancuated
}



// we can keep it with /,/,\,\ but we will either overwrite on the array or copy it to another array which will be time and memory consuming
void star_set2(int arr[][30],int row,int col,int x,int y)
{
    int i=0,j=0;
    arr[x][y]='*';
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(i>x && (j==y))
            {
                arr[i][j]='^';
            }
            else if(i<x && (j==y))
            {
                arr[i][j]='v';
            }
            else if(j>y && (i==x))
            {
                arr[i][j]='<';
            }
            else if(j<y && (i==x))
            {
                arr[i][j]='>';
            }
            else if(i<x && (j<y)) //top left
            {
                arr[i][j]='\\';
            }
            else if(i<x && (j>y)) //top right
            {
                arr[i][j]='//';
            }
            else if(i>x&& (j<y)) //bottom left
            {
                arr[i][j]='/';
            }
            else if(i>x && (j>y)) // bottom right
            {
                arr[i][j]='\\\\';
            }

            else
            {
                arr[i][j]='0';
            }
        }
    }
    arr[x][y]='*';
}
void star_print2(int arr[][30],int row,int col)
{
    int i=0,j=0;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("%c ",arr[i][j]);

        }
        printf("\n");
    }
}
void star_find2(int arr[][30],int row,int col,int*px,int*py)
{
    int i=0,j=0;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            if(arr[i][j]=='*')
            {
                *px=i;
                *py=j;
            }
        }
    }
}
void star_find_binary_search2(int arr[][30],int row,int col,int*px,int*py)
{
    int frow=0,lrow=row-1,fcol=0,lcol=col-1,mrow,mcol;
    while(fcol<=lcol && frow<=lrow)
    {
        mrow=(frow+lrow)/2;
        mcol=(fcol+lcol)/2;
        if(arr[mrow][mcol]=='*')
        {
            *px=mrow;
            *py=mcol;
            break;
        }
        switch(arr[mrow][mcol])
        {
        case '<':
            lcol=mcol-1;
            break;
        case '>':
            fcol=mcol+1;
            break;
        case 'v':
            frow=mrow+1;
            break;
        case '^':
            lrow=mrow-1;
            break;
        case '/':
            fcol=mcol+1; // bottom left corner
            lrow=mrow-1;
            break;
        case '\\\\':
            lcol=mcol-1; //bottom right corner
            lrow=mrow-1;
            break;
        case '//':
            lcol=mcol-1;  //top right
            frow=mrow+1;
            break;
        case '\\':
            fcol=mcol+1; //top left (although 4 slashes will print the same as two slashes it has different weight)
            frow=mrow+1;
            break;
        }
    }
    //printf("%c    %c    %c    %c\n",'/////','/','\\','\\\\\\'); // all are the same as they will be trancuated
}






