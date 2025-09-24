#include<stdio.h>
#include<stdlib.h>
int graph[100][100],path[100],vis[100],dfscount=0,dcount=0,count=0,cyclic=0,d;
void dfs(int n,int start,int parent)
{
    vis[start]=0;count++;
    for(int i=0;i<n;i++)
    {
        if(i!=parent && graph[start][i] && vis[i])
        cyclic=1;
        dcount++;
        if(graph[start][i] && vis[i]==0)
        dfs(n,i,start);
    }
}
void main()
{
    int k;
    FILE *f1=fopen("dfsb.txt","a");
    FILE *f2=fopen("dfsw.txt","a");
    int v;
    for(int i=1;i<=10;i++)
    {
        v=i;
        if(k==0)
        {
            for(int i=0;i<v;i++)
            {
                for(int j=0;j<v;j++)
                {
                    if(i!=j)
                    {
                        graph[i][j]=1;
                    }
                    else
                    graph[i][j]=0;
                }
            }
        }
        if(k==1)
        {
            for(int i=0;i<v;i++)
            {
                for(int j=0;j<v;j++)
               {
                graph[i][j]=0;
               }
            }
            for(int i=0;i<v-1;i++)
            {
                graph[i][i+1]=1;
            }
        }
        cyclic=0;dfscount=0;dcount=0;count=0;
        dfs(v,0,-1);
        dfscount++;
        int start;
        start=1;
        while(count!=v)
        {
            if(vis[i]!=1)
            {
                dfs(v,start,-1);
                dfscount++;
            }
            start++;
        }
        if(k==0)
        {
        fprintf(f2,"%d\t%d\n",v,dcount);
        }
        else
        fprintf(f1,"%d\t%d\n",v,dcount);
    }
    fclose(f1);
    fclose(f2);
}
/*void main()
{
    for(int i=0;i<2;i++)
    plotter(i);
    printf("data is entered\n");
}*/
