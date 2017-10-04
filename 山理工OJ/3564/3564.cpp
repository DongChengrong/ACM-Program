#include<stdio.h>
#include<cstring>
using namespace std;

const int maxn=100+10;
char G[maxn][maxn];
int ans,r,c;
bool vis[maxn][maxn];

int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};

void init()
{
    memset(G,0,sizeof(G));
    memset(vis,false,sizeof(vis));
    ans=0;
}

void dfs(int i,int j,int way)
{
    vis[i][j]=true;
    if(way==1)
    {
        int cnt=0;
        for(int k=0;k<4;k++) { int x=i+dr[k]; int y=j+dc[k]; if(G[x][y]=='#') cnt++; }
        if(cnt==1) ans++;
    }
    else if(way==2)
    {
        for(int k=0;k<4;k++)
        {
            int x=i+dr[k];
            int y=j+dc[k];
            if(x<0 ||  x>=r || y<0 || y>=c) ans++;
            else if(!vis[x][y] && G[x][y]=='.') dfs(x,y,1);
            else if(!vis[x][y] && G[x][y]=='#') dfs(x,y,2);
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&r,&c);
        init();
        for(int i=0;i<r;i++) scanf("%s",G[i]);
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(!vis[i][j] && G[i][j]=='#') dfs(i,j,2);
        printf("%d\n",ans);
    }
    return 0;
}
