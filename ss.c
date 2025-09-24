#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count;
void ss(int *a,int n)
{
    int min,temp;
    for(int i=0;i<n-1;i++)
    {
        min=i;
        for(int j=i+1;j<n;j++)
        {
            if(*(a+j)<*(a+min))
            min=j;
            count++;
        }
        if(min!=i)
        {
            temp=*(a+min);
            *(a+min)=*(a+i);
            *(a+i)=temp;
        }
    }
}
tester()
{
    int arr[100];
    int n;
    printf("Enter the size of an array:");
    scanf("%d",&n);
    printf("Enter the elements of an array:\n");
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    printf("Array:\n");
    for(int i=0;i<n;i++)
    printf("%d\t",arr[i]);
    ss(arr,n);
    printf("\nSorted array:\n   ");
    for(int i=0;i<n;i++)
    printf("%d\t",arr[i]);
}
void plotter()
{
    int n;
    FILE *fp;
    fp=fopen("ss.txt","a");
    n=10;
    while(n<=30000)
    {
        int *a=(int*)malloc(sizeof(int)*n);
        for(int i=0;i<n;i++)
        *(a+i)=i;
        count=0;
        ss(a,n);
        fprintf(fp,"%d\t%d\n",n,count);
        if(n<10000)
        n*=10;
        else
        n+=10000;
    }
}
void main()
{
    plotter();
}