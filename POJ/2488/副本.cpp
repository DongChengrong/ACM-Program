#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;
int T,p,q,vis[30][30],flag;
int f[2][8]={{-2,-2,-1,-1, 1,1, 2,2},{-1, 1,-2, 2,-2,2,-1,1}};
struct node{
    int x;int y;
}ans[30];
void dfs(int x,int y,int step,int tt)
{
    if (flag) return ;

    vis[x][y]=1;
    ans[step].x=x;
    ans[step].y=y;

    if (step==p*q && flag==0)
    {
        flag=1;
        printf("Scenario #%d:\n",tt);
        for (int i=1;i<=step;i++)
        {
            char c=ans[i].x-1+'A';
            cout<<c<<ans[i].y;
        }
        printf("\n");
        printf("\n");
        return ;
    }
    for (int i=0;i<8;i++)
    {
        int nex=x+f[0][i];
        int ney=y+f[1][i];
        if (nex>=1 && nex<=q && ney>=1 && ney<=p && vis[nex][ney]!=1)
        dfs(nex,ney,step+1,tt);

    }
    vis[x][y]=0;
}
int main()
{
    scanf("%d",&T);
    for (int t=1;t<=T;t++)
    {
        memset(vis,0,sizeof(vis));
        flag=0;
        scanf("%d%d",&p,&q);
        dfs(1,1,1,t);
        if (!flag)
        {
            printf("Scenario #%d:\n",t);
            printf("impossible\n");
            printf("\n");
        }
    }
}
