#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

#define N 10 + 5

int a[N][N];
int m,n;
int vis[N][N][N][N];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

struct Node{
    int x,y;  //箱子坐标
    int x1,y1;   //搬运工坐标
    int step;
};

//此状态下人能走到哪
void dfs(Node u)
{
    if(u.x1 < 1 || u.x1 > m || u.y1 < 1 || u.y1 > n) return;   //终止条件
    if(u.x == u.x1 && u.y == u.y1) return;
    if(a[u.x1][u.y1] == 1) return;
    if(vis[u.x][u.y][u.x1][u.y1] == 1) return;

    vis[u.x][u.y][u.x1][u.y1] = 1;  //标记

    for(int i = 0; i < 4; i++)  //访问新节点
    {
        Node v = u;
        v.x1 += dir[i][0]; v.y1 += dir[i][1];
        dfs(v);
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int x0,y0,x1,y1,x2,y2;

        scanf("%d %d",&m,&n);

        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
            {
                scanf("%d",&a[i][j]);
                if(a[i][j] == 2) { x0 = i; y0 = j; }
                if(a[i][j] == 3) { x2 = i; y2 = j; }
                if(a[i][j] == 4) { x1 = i; y1 = j; }
            }

        bool ok = false;
        memset(vis,0,sizeof(vis));
        queue<Node> q;
        q.push((Node){x0,y0,x1,y1,0});
        while(!q.empty())
        {
            Node u = q.front(); q.pop();  //取出队列前端元素
            printf("%d %d\n",u.x,u.y);
            if(u.x == x2 && u.y == y2) { printf("%d\n",u.step); ok = true; break; }

            dfs(u);

            for(int i = 0; i < 4; i++)
            {
                Node v = u;
                int px = v.x + dir[i][0];
                int py = v.y + dir[i][1];
                if(vis[v.x][v.y][px][py] == 1){
                    v.x += -1 * dir[i][0];
                    v.y += -1 * dir[i][1];
                    if(v.x <= m && v.x >= 1 && v.y >= 1 && v.y <= n )
                    { v.step++; q.push(v); vis[v.x][v.y][v.x1][v.y1] = 2; }
                }
            }
        }
        if(!ok) printf("-1\n");
    }
    return 0;
}
