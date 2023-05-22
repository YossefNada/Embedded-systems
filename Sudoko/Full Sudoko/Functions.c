
// Prototypes have to be included in the main file
/*
int power(int base,int exp)
{
    int result=1;
    for(int i=1; i<=exp; i++)
    {
        result*=base;
    }

    return result;
}
*/

void swap (int *p1,int *p2) // the address has been passed
{
    // by passing the address of the callee we can return more than one answer using pointers
    //p1 contains &x
    //p2 contains &y
    int temp;
    temp= *p1; //temp=x
    *p1=*p2;   // x=y
    *p2=temp;
    printf("In Func:Swap first = %d, second = %d\n",*p1,*p2);
}

// when we pass the address to the function this is called call by reference
// take care that the type of the pointer and the type of the variable are the same to avoid corrupting data (when writing in memory) and garbage values when reading from memory
int add_mul(int x,int y,int *pmul)//takes two numbers and the address of the multiply
{
    *pmul=x*y;
    return x+y; // take care from overflow
}
char check_overflow(unsigned char n1,unsigned char n2,unsigned char *psum)
{
    unsigned char r =n1/2 +n2/2;
    if(r>127)
        return 0;//indicating overflow
    else
    {

        *psum=n1+n2;
        return 1; //indicating there is no overflow
    }


}
//function that checks whether this is number is a base of two
int base_of_two (int n) // base of two means that it only has (1) bit in his binary representation
{
    int sum=0;
    while(n>0)
    {
        sum+=n&1;
        n>>=1;
    }
    if(sum==1)
    {
        return 1;
    }
    else
        return 0;
}

// Other ways to implement the base of two function
int base_of_two1(int n)
{
    for(int i=0; i<=31; i++)
    {
        if(n==power(2,i))
            return 1;

    }
    return 0;
}
int base_of_two2(int n)
{
    if(n==0)
        return 0;
    while(n>1)
    {
        if(n%2!=0)
            return 0;
        n/=2;
    }
    return 1;
}
int base_of_two3(int n) //8=1000   7=0111
{
    /*
    if(n==0)
        return 0;
    if(n&(n-1)==0)
        return 1;
    else
        return 0;
        */
    return n && (!(n & (n-1)));
}


int approximation (float n)
{
    n+=0.5;
    return n;

}
int prime(int n)
{
    if(n==0 || n==1)
        return 1;
    for(int i=2; i<=n/2; i++)
    {
        if(n%i==0)
            return 1;
    }
    return 0;
}
int base_of_two4(unsigned int n)
{
    for(int i=1; i<=n;)
    {
        if(n==i)
        {
            return 1;
        }
        i*=2;
    }
    return 0;
}
int base_of_two5(unsigned int n) // if the largest base of two number in 32 bits (unsigned int) is divisble by the number then the number is base of two
{
    if(n==0)
        return 0;
    if(0x80000000%n==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int base_of_three(int n)
{
    while(n>1)
    {
        if(n%3)
            return 1;
        n/=3;

    }
    return 0;
}



unsigned int circ_shift_right(unsigned int num,unsigned char shifts)

{
    //shifts=4
    //num=0xaabbccdd
    unsigned int mask;
    switch(shifts)
    {
    case 4:
        mask=0x0000000f;
        break;
    case 8:
        mask=0x000000ff;
        break;
    case 12:
        mask=0x00000fff;
        break;
    case 16:
        mask=0x0000ffff;
        break;
    case 20:
        mask=0x000fffff;
        break;
    case 24:
        mask=0x00ffffff;
        break;
    case 28:
        mask=0x0fffffff;
        break;
    case 32:
        mask=0xffffffff;
        break;

    }
    //shifts=4
    //mask=0x0000000f
    unsigned int movable=num&mask;
    movable=movable<<(32-shifts);
    //movable=0xf0000000
    unsigned int  x;
    x=num>>shifts;
    //x=0x00aabbcc
    return x | movable;


}
unsigned int circ_shift_left(unsigned int num,unsigned char shifts)

{
    //shifts=4
    //num=0xaabbccdd
    unsigned int mask;
    switch(shifts)
    {
    case 4:
        mask=0xf0000000;
        break;
    case 8:
        mask=0xff000000;
        break;
    case 12:
        mask=0xfff00000;
        break;
    case 16:
        mask=0xffff0000;
        break;
    case 20:
        mask=0xfffff000;
        break;
    case 24:
        mask=0xffffff00;
        break;
    case 28:
        mask=0xfffffff0;
        break;
    case 32:
        mask=0xffffffff;
        break;

    }
    //shifts=4
    //mask=0xf0000000
    unsigned int movable=num&mask;
    movable=movable>>(32-shifts);
    //movable=0x0000000d
    unsigned int  x;
    x=num<<shifts;
    //x=0xdaabbccd
    return x | movable;


}

unsigned char reverse_number(unsigned char n)
{
    unsigned char n2=0;
    int i,j=7;
    for(i=0; i<8; i++,j--)
    {
        if((n>>i)&1)
        {
            n2=n2 | (1<<j);
        }
    }
    binary_print(n2);
    return n2;
}
// same but for int
unsigned int reverse_number_int(unsigned int n)
{
    unsigned int n2=0;
    int i,j=31;
    for(i=0; i<32; i++,j--)
    {
        if((n>>i)&1)
        {
            n2=n2 | (1<<j);
        }
    }
    binary_print(n2);
    return n2;
}

void binary_print_int (unsigned int n)
{
    int i;
    for(i=31; i>=0; i--)
    {
        if((n>>i)&1)
        {
            printf("1");
        }
        else
            printf("0");
    }
}

void binary_print (unsigned char n)
{
    int i;
    for(i=7; i>=0; i--)
    {
        if((n>>i)&1)
        {
            printf("1");
        }
        else
            printf("0");
    }
}


int count_Max_number_of_ones_in_theBinaryNumber(unsigned int n)
{
    //10000000101010111100001
    int max=0,c=0;
    int flag=0;
    for(int i=0; i<32; i++)
    {
        if((n>>i)&1)
        {
            flag=1;
            if(c>max)
                max=c;
            c=0;

        }
        else
        {
            if(flag)
                c++;
        }
    }
    return max;
}
int maximum_of_XOR(int i,int j)
{
    int maximum=0;
    int temp;
    int max=j;
    int r;
    if(i>j)
    {
        max=i;
        temp=i;
        i=j;
        j=temp;

    }
    for(;i<=max; i++)
    {
        for(int j=i; j<=max; j++)
        {
            r=i^j;
            if((i^j)>maximum) // take care from precedence of the operators
            {
                maximum=r;

            }


            printf("\n%d  %d  %d",i,j,i^j);
            printf("   maximum= %d\n",maximum);
        }
        printf("\n=================\n");

    }

    return maximum;
}

int func_return_max_overTheCourseOfItS_operation1(int n)
{
    static int max; // kan momken bardo a3melo intialize b 0x80000000  akbr rakm saleb
    // blash te3mlo global variable 3alashan el privacy 3alshan ma7adesh ye3dl 3aleh
    static flag=0;
    if(n<0 && flag==0)
    {
        max=n;
        flag=1; // blash te3ml flag++ 3alshan momken yegy feh wa2t we ye3ml overflow khaleh b 1 we khalas
    }
    if(n>max)
    {
        max=n;
        flag=1;
    }
    return max;
}



/*9) Write a c function to swap the two bytes of a short int (n=0xFE20 ->0X20FE)
use 2 methods.*/

short  swap_Two_bytes_ofShort1(short n)
{
    short byteLeft=n&0x00ff;//0x0020
    short byteRight=n&0xff00;//0xFE00
    byteLeft<<=8;//0x2000
    byteRight=byteRight>>8 & 0x00ff;//0x00fe
    n=byteLeft|byteRight;
    return n;

}
static int z=8;
void swap_Two_bytes_ofShort2(char*n)
{
    char temp;
    temp=*n;
    *n=*(n+1);
    *(n+1)=temp;
}

int power(int base,int exp)
{
    int result=1;
    for(int i=1; i<=exp; i++)
    {
        result*=base;
    }

    return result;
}
char * f2s(float num)
{
    float right=num-(int)num;//0.3000000 to get the decimal part
    int left=num,left2=num,digitsl=0,digitsr=0,i;//to get the left part before the full stop
    static char array[50]= {0}; //intialize array and return
    while(left2>0) // calculate the digits of the left part
    {
        left2/=10;
        digitsl++;
    }

    for(i=0; i<digitsl; i++) // put the left part in the array
    {
        array[i]=(((left/power(10,digitsl-1-i))%10)+'0');
    }
    array[i]='.'; // add the full stop
    i++; // increment i to start from the position following the full stop
    int j=i; // copy it to use as offset later on
    right*=power(10,6);//multiplying by 7 would deviate the precision by 0.0000001
    int rightNew=right;
    while(rightNew%10==0) // remove the zeros on the left in case the number is of limited precision like 0.30000---->3000000-->3
    {
        rightNew/=10;
    }
    int rightNew2=rightNew;

    while(rightNew2>0) //calculate digits of the right part
    {
        rightNew2/=10;
        digitsr++;
    }
    int k=digitsr;
    for(;i<digitsr+j; i++) // add the next part
    {
        array[i]=(((rightNew/power(10,k-1))%10)+'0');
        k--;
    }

    return array;
}



void Swap_pointer(char**p1,char**p2)
{

    char*temp;
    temp=*p1;
    *p1=*p2;
    *p2=temp;


//    printf("x=%d   y=%d   *p1=%d *p2=%d\n",x,y,*p1,*p2);
}


