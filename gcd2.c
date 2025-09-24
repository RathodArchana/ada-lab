#include<stdio.h>
#include<stdlib.h>
#define x 10
#define y 100
int test=0;
int euclid(int m,int n)
{
int r;
int count=0;
while(n)
{
count++;
r=m%n;
m=n;
n=r;
}
return count;
}
int consec(int m, int n)
{
int min;
int count=0;
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
return count;
}
int modified(int m,int n)
{
int temp;
int count=0;
while(n>0)
{
if(n>m)
{
temp=m;m=n;n=temp;
}
m=m-n;
count +=1 ;
}
return count; // m is the GCD
}
void analysis(int ch)
{
    int m,n,i,j,k;
    int count,maxcount,mincount;
    FILE *fp1,*fp2;
    for(i=x;i<=y;i+=10)
    {
        maxcount=0;mincount=10000;
        for(j=2;j<=i;j++)
        {
            for(k=2;k<=i;k++)
            {
                count=0;
                m=j;n=k;
                switch(ch)
                {
                    case 1: count=euclid(m,n);break;
                    case 2: count=consec(m,n);break;
                    case 3: count=modified(m,n);break;
                    default: break;
                }
                if(count>maxcount)
                maxcount=count;
                if(count<mincount)
                mincount=count;
            }
        }
        switch(ch)
        {
            case 1:fp2=fopen("e_b.txt","a");
            fp1=fopen("e_w.txt","a");
            break;
            case 2:fp2=fopen("c_b.txt","a");
            fp1=fopen("c_w.txt","a");
            break;
            case 3:fp2=fopen("m_b.txt","a");
            fp1=fopen("m_w.txt","a");
            break;
            default:break;
        }
        fprintf(fp2,"%d\t%d\n",i,mincount);
        fprintf(fp1,"%d\t%d\n",i,maxcount);
        fclose(fp1);
        fclose(fp2);
    }
}
void main()
{
int ch;
while(1)
{
printf("GCD\n");
printf("1.Euclid\n3.modified Euclid\n2.consecutive integer method\n0 to exit\n");
scanf("%d",&ch);
if(ch ==0)
break;
switch(ch)
{
case 1:
case 2:
case 3: analysis(ch);
break;
default:break;
}
}
return ;
}