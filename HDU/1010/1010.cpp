#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

const int maxn = 10;
const int dir[4][2] = {0,1,0,-1,1,0,-1,0};
char maze[maxn][maxn];
int vis[maxn][maxn];

int n,m,t;
int x, y, X, ex,ey;

//查寻起始状态
void seek()
{
    X = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            if(maze[i][j] == 'S')
            {
                x = i; y = j;
            }
            if(maze[i][j] == 'D') ex = i, ey = j;
            if(maze[i][j] == 'X') X++;
        }
}

bool dfs(int x0, int y0, int c)
{
    if(c == t) return maze[x0][y0] == 'D';
    if(c > t) return false;

    int dis = t - c - (abs(x0 - ex) + abs(y0 - ey));    //距离
    if(dis < 0 || dis & 1)
        return false;

    bool ok = false;

    for(int i = 0; i < 4; i++)
    {
        int x1 = x0 + dir[i][0];
        int y1 = y0 + dir[i][1];
        if(x1 <= n && x1 >= 1 && y1 <= m && y1 >= 1 && !vis[x1][y1] && maze[x1][y1] != 'X')
        {
            vis[x1][y1] = 1;
            if(dfs(x1,y1,c+1)) return true;   //就因为这里没有返回TLE了许多次，见鬼
            vis[x1][y1] = 0;
        }
    }

    return ok;
}

int main()
{
    while(~scanf("%d%d%d",&n,&m,&t) && (n || m || t))
    {
        for(int i = 1; i <= n; i++)
            scanf("%s",maze[i] + 1);

        memset(vis,0,sizeof(vis));

        bool ok = true;

        seek();  //查询起始状态

        if(n * m - X <= t) ok = false;

        vis[x][y] = 1;

        if(ok) ok = dfs(x,y,0);

        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
