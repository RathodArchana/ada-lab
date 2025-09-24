#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count;
int flag;
int bb(int *a,int n)
{
    flag=0;
    count=0;
    int temp;
    for(int i=0;i<n-1;i++)
    {
        flag=0;
        for(int j=0;j<n-i-1;j++)
        {
            count++;
            if(*(a+j)>*(a+j+1))
            {
                temp=*(a+j);
                *(a+j)=*(a+j+1);
                *(a+j+1)=temp;
                flag=1;
            }
        }
        if(flag==0)
        break;
    }
    return count;
}
void plotter()
{
    srand(time(NULL));
    int *arr;
    int n;
    FILE *f1,*f2,*f3;
    f1=fopen("bbb.txt","a");
    f2=fopen("bba.txt","a");
    f3=fopen("bbw.txt","a");
    n=10;
    while(n<=30000)
    {
        arr=(int*)malloc(sizeof(int)*n);
        for(int i=0;i<n;i++)
        *(arr+i)=i+1;
        count=0;
        bb(arr,n);
        fprintf(f1,"%d\t%d\n",n,count);
        for(int i=0;i<n;i++)
        *(arr+i)=n-i;
        count=0;
        bb(arr,n);
        fprintf(f3,"%d\t%d\n",n,count);
        for(int i=0;i<n;i++)
        *(arr+i)=rand()%n;
        count=0;
        bb(arr,n);
        fprintf(f2,"%d\t%d\n",n,count);
        if(n<10000)
        n=n*10;
        else
        n+=10000;
        free(arr);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}
int main()
{
    plotter();
}