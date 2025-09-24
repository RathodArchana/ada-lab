#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count;
int bs(int key,int *a,int high,int low)
{
    int mid;
    count++;
    mid=(high+low)/2;
    if(low>high)
    return count-1;
    if(*(a+mid)==key)
    return count;
    else if(*(a+mid)>key)
    return bs(key,a,mid-1,low);
    else
    return bs(key,a,high,mid+1);
}
void plotter()
{
    int *arr;
    int key,n,r;
    FILE *f1,*f2,*f3;
    f1=fopen("bsb.txt","a");
    f2=fopen("bsa.txt","a");
    f3=fopen("bsw.txt","a");
    n=2;
    while(n<=1024)
    {
        arr=(int*)malloc(n*sizeof(int));
        for(int i=0;i<n;i++)
        *(arr+i)=1;
        int mid=(n-1)/2;
        *(arr+mid)=0;
        count=0;
        r=bs(0,arr,n-1,0);
        fprintf(f1,"%d\t%d\n",n,r);
        for(int i=0;i<n;i++)
        *(arr+i)=rand()%n;
        key=rand()%n+1;
        count=0;
        r=bs(-1,arr,n-1,0);
        fprintf(f2,"%d\t%d\n",n,r);
        for(int i=0;i<n;i++)
        *(arr+i)=0;
        count=0;
        r=bs(1,arr,n-1,0);
        fprintf(f3,"%d\t%d\n",n,r);
        n=n*2;
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