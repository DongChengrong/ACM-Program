#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn = 100 + 10;
int r,c;
char G[maxn][maxn];
int vis[maxn][maxn];

void dfs(int i,int j,int count)
{

    for(int k = -1; k <= 1; k++)
    {
        for(int z = -1; z <= 1; z++)
        {
            if(!k && ! z) continue;
            int x = i + k;
            int y = j + z;
            if(x < 0 || x >= r || y < 0 || y >= c) continue;
            if(G[x][y] != '@') continue;
            if(vis[x][y]) continue;
            vis[x][y] = count;
            dfs(x,y,count);
        }
    }
}

int main()
{
    while(scanf("%d%d",&r,&c) == 2 && r)
    {
        for(int i = 0; i < r; i++)
            scanf("%s",G[i]);

        int count = 0;
        memset(vis,0,sizeof(vis));
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
                if(G[i][j] == '@' && !vis[i][j])
                    dfs(i,j,++count);
        }

        printf("%d\n",count);

    }
    return 0;
}
