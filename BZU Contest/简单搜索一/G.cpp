/*
这个题的难点在于火焰的延伸
我们可以定义一个vector用来表示最外面火苗的位置
火放的太多了，所以WA掉了
*/
#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define N 1100
#define fi first
#define se second

int T, r, c;
char G[N][N];
int vis[N][N];

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

struct Node {
    int x, y, step;
};

vector<Node> fires;

void fire() {
    vector<Node> tmp = fires;
    fires.clear();
    for (int i = 0; i < tmp.size(); ++i) {
        Node u = tmp[i];
        for (int j = 0; j < 4; ++j) {
            Node v = u;
            v.x += dir[j][0];
            v.y += dir[j][1];
            if (v.x <= r && v.x >= 1 && v.y <= c && v.y >= 1) {
                if (G[v.x][v.y] != '#' && G[v.x][v.y] != 'F') {
                    G[v.x][v.y] = 'F';
                    vis[v.x][v.y] = 1;
                    fires.push_back(v);
                }
            }
        }
    }
}

void print_G()
{
    printf("\n");
    for (int i = 1; i<= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            printf("%c", G[i][j]);
        }
        printf("\n");
    }
}

bool should_fire(Node u, queue<Node> q) {
    if (q.empty()) return true;
    else {
        Node v = q.front();
        if (v.step != u.step) return true;
        else return false;
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d",&T);
    int cnt = 1;
    while (T--) {

        fires.clear();
        int sx, sy, fx, fy;

        memset(vis, 0, sizeof(vis));

        scanf("%d%d",&r, &c);
        for (int i = 1; i <= r; ++i) {
            scanf("%s",G[i] + 1);
            for (int j = 1; j <= c; ++j) {
                if (G[i][j] == 'J') {
                    sx = i; sy = j;
                }
                if (G[i][j] == 'F') {
                    fx = i; fy = j;
                    vis[fx][fy] = 1;
                    fires.push_back((Node){fx,fy,0});
                }
            }
        }
//
//        if (cnt == 125) {
//            printf("%d %d\n",r,c);
//            print_G();
//        }
//        cnt++;

        queue<Node> q;
        vis[sx][sy] = 1;
        bool ok = false;
        q.push((Node){sx, sy, 0});

        while (!q.empty()) {
            Node u = q.front(); q.pop();
            //printf("%d %d  %d\n",u.x, u.y, u.step);
            if (u.x < 1 || u.x > r || u.y < 1 || u.y > c) {
                ok = true; printf("%d\n",u.step);
                break;
            }

            if (should_fire(u, q)) {
                fire();
                //print_G();
            }

            for (int i = 0; i < 4; ++i) {
                Node v = u;
                v.x += dir[i][0];
                v.y += dir[i][1];
                v.step++;
                if (v.x < 1 || v.x > r || v.y < 1 || v.y > c) {
                    vis[v.x][v.y] = 1;
                    q.push(v);
                    break;
                } else {
                    if (!vis[v.x][v.y] && G[v.x][v.y] != '#') {
                        vis[v.x][v.y] = 1;
                        q.push(v);
                    }
                }
            }
        }

        if (!ok) printf("IMPOSSIBLE\n");
    }
    return 0;
}
