#include<stdio.h>
#include<math.h>
char A[27]=" ABCDEFGHIJKLNMOPQRSTUVWXYZ";
int B[27][27];
int dir[2][8]={{-1,1,-2,2,-2,2,-1,1},{-2,-2,-1,-1,1,1,2,2}};
int key,k;
struct type
{
    int x;
    char y;
}node[100];
void zero()
{
    int i,j;
    for(i=1;i<27;i++)
        for(j=1;j<27;j++)
        {
            B[i][j]=0;
        }
}
void print(int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        printf("%c%d",node[i].y,node[i].x);
    }
    printf("\n\n");
}
void dfs(int cp,int cq,int p,int q,int len)
{
    int i;
    if(cp<=0 || cp>p || cq<=0 || cq>q)
        return;
    if(B[cp][cq] || key)
        return;
    B[cp][cq]=1;
    node[len].x=cp;
    node[len].y=A[cq];
    len++;
    if(len==p*q)
    {
        key=1;
        return;
    }
    for(i=0;i<8;i++)
    {
        if(!key)
            dfs(cp+dir[0][i],cq+dir[1][i],p,q,len);
        else
            break;
    }
    return;
}
int main()
{
    int n,q,p;
    int len,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        len=0;
        key=0;
        zero();
        printf("Scenario #%d:\n",i);
        scanf("%d%d",&p,&q);
        dfs(1,1,p,q,len);
        if(key)
            print(p*q);
        else
            printf("impossible\n\n");
    }
    return 0;
}
