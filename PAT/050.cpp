/*
*题目链接：https://pintia.cn/problem-sets/994805342720868352/problems/1038430013544464384
*明明是道简单的模拟题比赛时竟然只过了16分，我还真是菜啊
**/
#include <stdio.h>
#include <string.h>

#define N 220
#define INF 0x3f3f3f3f

int n, m, p;
int vis[N];
int G[N][N];

int main() {
    scanf("%d%d", &n, &m);
    memset(G, 0, sizeof(G));
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u][v] = G[v][u] = w;
    }
    int res = INF, pos = -1;
    scanf("%d", &p);
    for (int i = 1; i <= p; ++i) {
        int ok = 0, pre;
        memset(vis, 0, sizeof(vis));
        int flag = 1, sum = 0, cnt = 1;
        int k, u, v; scanf("%d%d", &k, &pre); u = pre, vis[u] = 1;
        for (int j = 1; j < k; ++j) {
            scanf("%d", &v);
            if (!flag) continue;
            if (!G[u][v]) {
                flag = 0;
                printf("Path %d: NA (Not a TS cycle)\n", i);
                continue;
            } else {
                sum += G[u][v];
                if (!vis[v]) ++cnt;
                ++vis[v];
                if (vis[v] > 2) ok = 1;
            }
            if (j != k - 1) u = v;
        }
        if (!flag) continue;
        else if (pre != v || cnt != n) {
            printf("Path %d: %d (Not a TS cycle)\n", i, sum);
        } else {
            if (res > sum) {
                res = sum; pos = i;
            }
            if (ok) printf("Path %d: %d (TS cycle)\n", i, sum);
            else printf("Path %d: %d (TS simple cycle)\n", i, sum);
        }
    }
    printf("Shortest Dist(%d) = %d\n", pos, res);
    return 0;
}
