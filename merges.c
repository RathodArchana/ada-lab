#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count;
int merge(int *a,int beg,int mid,int end)
{
    int i,j,k;
    int n1=(mid-beg)+1;
    int n2=end-mid;
    int left[n1],right[n2];
    for(i=0;i<n1;i++)
    left[i]=a[beg+i];
    for(j=0;j<n2;j++)
    right[j]=a[mid+j+1];
    i=0;j=0;k=beg;
    while(i<n1 && j<n2)
    {
        count++;
        if(left[i]<=right[j])
        a[k]=left[i++];
        else
        a[k]=right[j++];
        k++;
    }
    while(i<n1) a[k++]=left[i++];
    while(j<n2) a[k++]=right[j++];
}
int mergesort(int *a,int beg,int end)
{
    if(beg<end)
    {
        int mid=(beg+end)/2;
        mergesort(a,beg,mid);
        mergesort(a,mid+1,end);
        merge(a,beg,mid,end);
    }
}
/*int main()
{
    int arr[100];
    int n;
    printf("Enter the size:");
    scanf("%d",&n);
    printf("Enter the array:\n");
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    printf("Array:\n");
    for(int i=0;i<n;i++)
    printf("%d\t",arr[i]);
    mergesort(arr,0,n-1);
    printf("\nSorted array:\n");
    for(int i=0;i<n;i++)
    printf("%d\t",arr[i]);
}*/
void worst(int arr[],int beg,int end)
{
    if(beg<end)
    {
        int mid=(beg+end)/2;
        int i,j,k;
        int n1=(mid-beg)+1;
        int n2=end-mid;
        int a[n1],b[n2];
        for(i=0;i<n1;i++)
        a[i]=arr[(2*i)];
        for(j=0;j<n2;j++)
        b[j]=arr[(2*j)+1];
        worst(arr,beg,mid);
        worst(arr,mid+1,end);
        for(i=0;i<n1;i++)
        arr[i]=a[i];
        for(int j=0;j<n2;j++)
        arr[j+1]=b[j];
    }
}
void main()
{
    int *arr,n;
    srand(time(NULL));
    FILE *f1,*f2,*f3;
    f1=fopen("msb.txt","a");
    f2=fopen("msw.txt","a");
    f3=fopen("worstdata.txt","a");
    for(int n=2;n<=1024;n=n*2)
    {
        arr=(int*)malloc(sizeof(int)*n);
        for(int i=0;i<n;i++)
        *(arr+i)=i+1;
        count=0;
        mergesort(arr,0,n-1);
        fprintf(f1,"%d\t%d\n",n,count);
        count=0;
        worst(arr,0,n-1);
        for(int i=0;i<n;i++)
        fprintf(f3,"%d",*(arr+i));
        fprintf(f3,"\n");
        mergesort(arr,0,n-1);
        fprintf(f2,"%d\t%d\n",n,count);
        free(arr);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}