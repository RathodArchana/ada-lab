#include<stdio.h>
#include<stdlib.h>
int count;
int ins(int *a,int n)
{
    count=0;
    for(int i=1;i<n;i++)
    {
        int value=a[i];
        int j=i-1;
        while(count++ && a[j]>value)
        {
            a[j+1]=a[j];
            j--;
            if(j<0)
            break;
        }
        a[j+1]=value;
    }
}
int main()
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
    ins(arr,n);
    printf("\nSorted array:\n   ");
    for(int i=0;i<n;i++)
    printf("%d\t",arr[i]);
}