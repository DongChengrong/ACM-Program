/*
用广度优先搜索判断最小的步数
用深度优先搜索来确定移动方向
另外，特别要注意箱子有可能回去我们可以加一个方向来完成这一工作
原来要先判断人所处的位置是否合法，因为这一个疏忽WA了34次，以后长记性了
*/

#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define N 15
#define cin(x) scanf("%d",&x)

struct Node {
    int x, y;
    int px, py;
    int step;
    Node(int x, int y, int px, int py, int step) {
        this->x = x; this->y = y;
        this->px = px; this->py = py;
        this->step = step;
    }
};

int m, n;
int dir[4][2] = {{1,0},{-1, 0},{0, 1},{0, -1}};
int G[N][N], vis[N][N][10];  //图
int pv[N][N],b[N][N];

int sx, sy;   //源点坐标
int tx, ty;   //目的地坐标
int px, py;   //人的坐标
int ppx, ppy;   //人要去的坐标

//用于查找指定字符的位置
void seek(int t, int &x, int &y) {
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            if (G[i][j] == t) {
                x = i; y = j;
                return;
            }
        }
}

bool dfs(int px, int py) {

    if (px == ppx && py == ppy) return true;

    if (px < 1 || py < 1 || px > m || py > n) //终止条件
        return false;

    if (pv[px][py] == 1) return false;

    if (G[px][py] == 1) return false;

    if (sx == px && sy == py) return false;

    pv[px][py] = 1;

    for (int i = 0; i < 4; i++) {  //遍历生成新节点
        if (dfs(px + dir[i][0],py + dir[i][1])) return true;
    }

    return false;
}

/*void pre() {
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j) {
            b[i][j] = G[i][j];
        }
}*/


int main() {
    int T;
    cin(T);
    while (T--) {

        cin(m); cin(n);

        for (int i = 1; i <= m; i++)   //建图
            for (int j = 1; j <= n; j++)
                cin(G[i][j]);

        seek(2, sx, sy);
        seek(3, tx, ty);
        seek(4, px, py);

        bool ok = false;
        queue<Node> q;
        memset(vis, 0, sizeof(vis));
        q.push(Node(sx, sy, px, py, 0));
        while (!q.empty()) {

            Node u = q.front(); q.pop();   //取出队列前端元素

            if (u.x == tx && u.y == ty) {
                ok = true;
                printf("%d\n",u.step);
                break;
            }

            for (int i = 0; i < 4; i++) {   //生成下一个子节点
                Node v = u;
                v.step++;

                ppx = v.x + dir[i][0];  //人要在的位置
                ppy = v.y + dir[i][1];

                sx = v.x; sy = v.y;

                v.x = v.x -  dir[i][0];  //箱子的位置
                v.y = v.y -  dir[i][1];

                //pre();
                memset(pv, 0, sizeof(pv));    //初始化人经过的位置

                if(v.x >= 1 && v.x <= m && v.y >= 1 && v.y <= n) {
                    if (!vis[v.x][v.y][i] && G[v.x][v.y] != 1) {  //筛选满足题意的点
                        if ( (ppx >= 1 && ppx <= m && ppy >= 1 && ppy <= n && G[ppx][ppy] != 1) && dfs(v.px, v.py)) {
                            v.px = ppx; v.py = ppy;
                            vis[v.x][v.y][i] = 1;
                            q.push(v);
                        }
                    }

                }

            }

        }

        if (!ok) printf("-1\n");
    }
    return 0;
}
