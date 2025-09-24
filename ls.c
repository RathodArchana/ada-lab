#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count;
int ls(int *a,int key,int n)
{
    count=0;
    for(int i=0;i<n;i++)
    {
        count++;
        if(*(a+i)==key)
        return count;
    }
    return count;
}
int main()
{
    srand(time(NULL));
    int *arr;
    int n,key,count;
    FILE *f1,*f2,*f3;
    f1=fopen("lsb.txt","a");
    f2=fopen("lsa.txt","a");
    f3=fopen("lsw.txt","a");
    n=2;
    while(n<=1024)
    {
        arr=(int*)malloc(n*sizeof(int));
        for(int i=0;i<n;i++)
        *(arr+i)=1;
        count=ls(arr,1,n);
        fprintf(f1,"%d\t%d\n",n,count);
        for(int i=0;i<n;i++)
        *(arr+i)=rand()%n;
        key=rand()%n;
        count=ls(arr,key,n);
        fprintf(f2,"%d\t%d\n",n,count);
        for(int i=0;i<n;i++)
        *(arr+i)=0;
        count=ls(arr,1,n);
        fprintf(f3,"%d\t%d\n",n,count);
        n=n*2;
        free(arr);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}