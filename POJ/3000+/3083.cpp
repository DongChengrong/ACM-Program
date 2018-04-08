#include<cstdio>
#include<cstring>
int len;
int w,h;
int f[2][4]={{-1,0,0,1},{0,1,-1,0}};
char A[100][100];
int B[100][100];
void dfs(int x,int y,int l)
{
    if(x<0 || x>=w || y<0 || y>=h) return;
    if(B[x][y] || A[x][y]=='#') return;
    B[x][y]=1;
    if(A[x][y]=='E' && l<len) len=l;
    for(int i=0;i<4;i++)
        dfs(x+f[0][i],y+f[1][i],l+1);
    B[x][y]=0;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int x,y;
        len=10000;
        scanf("%d%d",&w,&h);
        for(int i=0;i<h;i++)
        {
            scanf("%s",&A[i]);
        }
        for(int i=0;i<h;i++)
        {
            if(strchr(A[i],'S')!=NULL)
            {
                y=i;
            }
        }
        for(int i=0;i<w;i++)
            if(A[y][i]=='S') x=i;
      //  printf("%d %d ",x,y);
        memset(B,0,sizeof(B));
        dfs(x,y,1);
        printf("%d",len);
    }
    return 0;
}
