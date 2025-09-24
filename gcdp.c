#include<stdio.h>
#include<stdlib.h>
#define X 10
#define Y 100
int test=0;
float euclid(int m,int n)
{
    int r;
    float count=0;
    while(n)
    {
        count++;
        r=m%n;m=n;n=r;
    }
    printf("THE GCD IS %d\n",m);
    return count;
}
float consec(int m,int n)
{
    int min;
    float count=0;
    min=m;
    if(n<min)
    min=n;
    while(1)
    {
        count++;
        if(m%min==0)
        {
            count++;
            if(n%min==0)
                break;
            min-=1;
        }
        else
        min-=1;
    }
    printf("THE GCD IS %d\n",min);
    return count;
}
float modified(int m,int n)
{
    int temp;
    float count=0;
    while(n>0)
    {
        if(n>m)
        {
            temp=m;m=n;n=temp;
        }
        m=m-n;
        count+=1;
    }
    printf("THE GCD IS %d\n",m);
    return count;
}
int main()
{
    int m,n;
    int choice;
    while(1)
    {
        printf("ENTER THE TWO NUMBERS\n");
        scanf("%d%d",&m,&n);
        printf("1.EUCLID'S ALGORITHM\n2.CONSECUTIVE INTEGER CHECKING ALGORITHM\n3.MODIFIED EUCLID'S ALGORITHM\n4.EXIT\n");
        printf("ENTER YOUR CHOICE\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:euclid(m,n);
                     break;;
            case 2:consec(m,n);
                        break;
            case 3:modified(m,n);
                        break;
            case 4:exit(0);
            default:printf("INVALID CHOICE\n");
                        break;
        }
    }
}
