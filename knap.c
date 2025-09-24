#include<stdio.h>
#include<stdlib.h>
int t[100][100],v[100],w[100],n,m,i,j,count=0;
int max(int a,int b){
return (a>b)?a:b;
}
int knap(int n,int m)
{
 for(int i=0;i<n+1;i++)
{
for(j=0;j<m+1;j++)
{
if(i==0||j==0)
t[i][j]=0;
else{
 count++;
if(j<w[i])
t[i][j]=t[i-1][j];
else
t[i][j]=max(t[i-1][j],v[i]+t[i-1][j-w[i]]);
}
}
}
 return t[n][m];
}
void main()
{
    FILE *f1;
 f1=fopen("knapsackgraph.txt","a");
count=0;
printf("Number of items: ");
scanf("%d",&n);
printf("Sack capacity: ");
scanf("%d",&m);
printf("Weight\tValue\n");
for(i=1;i<n+1;i++)
{
scanf("%d\t%d",&w[i],&v[i]);
}
printf("Max value %d\n",knap(n,m));
for(int i=0;i<n+1;i++)
{
for(int j=0;j<m+1;j++)
printf("%d ",t[i][j]);
printf("\n");
}
printf("Composition:\n");
for(int i=n;i>0;i--)
{
if(t[i][m]!=t[i-1][m])
{
printf("%d\t",i);
m=m-w[i];
}
}
printf("\n");
printf("%d\t%d\n",n,count);
fprintf(f1,"%d\t%d\n",n,count);
}
/*void main()
{
 FILE *f1;
 f1=fopen("knapsackgraph.txt","a");
 int ch;
 while(1)
 {
 printf("enter choice 1 to continue and 0 to exit\n");
 scanf("%d",&ch);
 switch(ch)
{
case 1:run();
 fprintf(f1,"%d\t%d\n",n,count);
 break;
 default:exit(0);
}
 }
 fclose(f1);
}*/