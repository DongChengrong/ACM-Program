#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn = 500 + 10;
char maze[maxn][maxn];
int vis[maxn][maxn][2];

int H,W;  //高、宽

int dx[] = {0,1,0,-1};   //移动
int dy[] = {1,0,-1,0};

struct Node
{
    int x,y;  //坐标
    int k;   //钥匙
    int step;  //步数
};

//检查坐标是否越界
bool out_of_bounds(int x, int y)
{
    if(x < 1 || x > H) return true;  //检查X轴坐标
    if(y < 1 || y > W) return true;  //检查Y轴坐标
    return false;
}

//检查是否是墙
bool isWall(int x, int y)
{
    if(maze[x][y] == 'W')
        return true;
    return false;
}

//判断是否被门挡住
bool stop_by_door(int x, int y, int k)
{
    if(maze[x][y] == 'D' && !k)
        return true;
    return false;
}

int main()
{
    while(scanf("%d%d",&H,&W) == 2)
    {
        for(int i = 1; i <= H; i++)
            scanf("%s",maze[i] + 1);

        int x,y;   //寻找起点
        for(int i = 1; i <= H; i++)
            for(int j = 1; j <= W; j++)
                if(maze[i][j] == 'S')
                {
                    x = i; y = j; break;
                }

        int ok = 0;
        memset(vis,0,sizeof(0));
        queue<Node> q;  //开始BFS
        q.push((Node){x,y,0,0});
        while(!q.empty())
        {
            Node p = q.front(); q.pop();  //取出栈顶元素

            if(maze[p.x][p.y] == 'E')
            {
                printf("%d\n",p.step);
                ok = 1;
                break;
            }

            for(int i = 0; i < 4; i++)
            {
                Node u = p;    //init
                u.x += dx[i]; u.y += dy[i];   //移动后的位置
                if(isWall(u.x,u.y)) continue;     //如果是墙
                if(out_of_bounds(x,y)) continue;   //检查是否越界
                if(vis[u.x][u.y][u.k]) continue;  //如果已经走过
                if(stop_by_door(u.x,u.y,u.k)) continue;   //如果被门挡住

                //得到新的节点
                u.step++;
                if(maze[u.x][u.y] == 'K') u.k = 1;
                vis[u.x][u.y][u.k] = 1;
                q.push(u);
            }
        }

        if(ok) continue;
        else printf("-1\n");
    }
    return 0;
}
