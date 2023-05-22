
static int max=0;
static int min=0x7fffffff;
static char flag=0;


void take_num(int y)
{
    if(y<0 && flag==0) // corner case for negative numbers
        /*if(flag==0)
        {
            max=y;
            min=y;
            flag=1;
            return ; // we hena mesh hatr eny a3mel intialize lel max wel min 3ala asas enha keda keda hatkhod awel kema
        }*/
    {
        max=y;
        flag=1;
    }
    if(y>max)
    {
        max=y;
        flag=1;
    }
    if(y<min)
    {
        min=y;
    }

}



int get_max(void)
{
    return max;
}



int get_min(void)
{
    return min;
}


