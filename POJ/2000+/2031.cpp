
/*
这个题是关于最小生成树的题，只不过这个题的权值需要我们自己去求
因为节点最多只有100个所以我采用prim算法坐解
少了一个初始化结果WA了一次
在这里，我用-1表示无穷大，想一想为什么
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;

#define N 110

struct Point {
    double x, y, z, r;
};

int n;
Point a[N];
double G[N][N];
int vis[N];
double d[N];

void fill(double x) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            G[i][j] = x;
        }
        d[i] = x;
    }
}

double two (double x) {
    return x * x;
}

double dis(Point a, Point b) {
    return sqrt(two(a.x - b.x) + two(a.y - b.y) + two(a.z - b.z));
}

int main() {
    while (scanf("%d",&n) == 1 && n) {

        for (int i = 0; i < n; ++i) {
            scanf("%lf%lf%lf%lf",&a[i].x, &a[i].y, &a[i].z, &a[i].r);
        }

        fill(-1);
        for (int i = 0; i < n - 1; ++i) {     //计算权值
            for (int j = i + 1; j < n; ++j) {
                double di = G[j][i] = dis(a[i],a[j]) - a[i].r - a[j].r;
                G[i][j] = G[j][i] = di < 0 ? 0 : di;
            }
            vis[i] = 0;
        }

        vis[n - 1] = 0;
        double cost = 0;
        d[0] = 0;
        while (1) {

            int v = -1;

            for (int i = 0; i < n; ++i) {  //寻找下一个要被更新的的节点
                if (!vis[i] && (v == -1 || d[v] == -1 || (d[v] > d[i] && d[i] != -1) ) ) {
                    v = i;
                }
            }

            if (v == -1) break;
            vis[v] = 1;
            cost += d[v];


            for (int i = 0; i < n; ++i) {  //更新节点
                if (d[i] == -1 || (d[i] > G[v][i] && G[v][i] != -1) ){
                    d[i] = G[v][i];
                }
            }

        }

        printf("%.3lf\n",cost);

    }
    return 0;
}