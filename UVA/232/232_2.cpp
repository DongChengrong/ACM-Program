#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=15;
int row,col;
char G[maxn][maxn];
int vis[maxn][maxn];

int print(int r,int c,int way)
{
    printf("%3d.",vis[r][c]);
    while(c<col && r<=row)
    {
        if(G[r][c]!='*' && c<col) putchar(G[r][c]);
        else { putchar('\n'); if(!way) return c+1; else return r+1; }
        if(way) r++; else c++;
    }
    putchar('\n');
    return maxn;
}

int main()
{
    int T=1,flag=0;
    while(scanf("%d",&row)==1 && row)
    {
        if(flag) printf("\n");
        flag=1;
        scanf("%d",&col);
        printf("puzzle #%d:\n",T++);
        for(int i=1;i<=row;i++) scanf("%s",G[i]);
        int ans=1;
        memset(vis,0,sizeof(vis));
        for(int r=1;r<=row;r++)
            for(int c=0;c<col;c++)
            if( G[r][c]!='*' && (r-1<1 || G[r-1][c]=='*' || c-1<0 || G[r][c-1]=='*')) vis[r][c]=ans++;
        printf("Across\n");
        for(int r=1;r<=row;r++)
        {
            int c=0;
            while(c<col)
            {
                if(vis[r][c]) c=print(r,c,0);
                else c++;
            }
        }
        printf("Down\n");
        for(int r=1;r<=row;r++)
            for(int c=0;c<col;c++)
            {
                if((G[r-1][c]=='*' || r-1<1) && G[r][c]!='*' ) print(r,c,1);
            }
    }
    return 0;
}
