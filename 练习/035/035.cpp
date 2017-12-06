#include<stdio.h>
#include<string.h>
#include<queue>
#include<cctype>
using namespace std;

typedef pair<int, int> P;

const int INF = 0x3f3f3f3f;
const int maxn = 100 + 10;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int n,m;
char maze[maxn][maxn];
int d[maxn][maxn];
int sx,sy,gx,gy;

int bfs()
{
    for(int i = 0; i < n; i++)  //初始化
        for(int j = 0; j < m; j++)
            d[i][j] = INF;

    for(int i = 0; i < n; i++)  //找到起点和终点
        for(int j = 0; j < m; j++)
        {
            if(maze[i][j] == 'S')
                sx = i, sy =j;
            if(maze[i][j] == 'G')
                gx = i, gy = j;
        }
    queue<P> que;
    d[sx][sy] = 0;
    que.push(P(sx,sy));
    while(!que.empty())
    {
        P p= que.front(); que.pop();   //去除队列顶部元素
        for(int i = 0; i < 4; i++)
        {
            int nx = dx[i] + p.first;
            int ny = dy[i] + p.second;
            if(0 <= nx && nx < n && 0 <= ny && ny < m && d[nx][ny] == INF && maze[nx][ny] != '#')
            {
                d[nx][ny] = d[p.first][p.second] + 1;
                que.push(P(nx,ny));
            }
        }
    }
    return d[gx][gy];
}

int main()
{
    while(scanf("%d%d",&n,&m) == 2)
    {
        for(int i = 0; i < n; i++)
            scanf("%s",maze[i]);
        printf("%d\n",bfs());
    }
    return 0;
}
