#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;
char A[28]=" ABCDEFGHIJKLNMOPQRSTUVWXYZ"; //字母
int B[27][27];  //记录是否经过
int dir[2][8]={{-2,-2,-1,-1, 1,1, 2,2},
        {-1, 1,-2, 2,-2,2,-1,1}};  //下一个节点位置
int key;  //是否可以
int p,q;   //边界
struct type
{
    int x;
    char y;
}node[100];   //记录路径
void print(int len)
{
    for(int i=0;i<len;i++)
    {
        printf("%c%d",node[i].y,node[i].x);
    }
    printf("\n\n");
}
void dfs(int cp,int cq,int len)
{
    if(key || B[cp][cq])
        return;
    if(cp<=0 || cp>p || cq<=0 || cq>q)
        return;
    B[cp][cq]=1;
    node[len].x=cp;
    node[len].y=A[cq];
    len++;
    if(len==p*q && !key) key=1;
    for(int i=0;i<8;i++)
    {
        if(key) break;
        dfs(cp+dir[1][i],cq+dir[0][i],len);
    }
    B[cp][cq]=0;  //千万不能忘，结束了一个子树
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        key=0;
        memset(B,0,sizeof(B));
        printf("Scenario #%d:\n",i);
        scanf("%d%d",&p,&q);
        dfs(1,1,0);
        if(key) print(p*q);
        else printf("impossible\n\n");
    }
    return 0;
}
