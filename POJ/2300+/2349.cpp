#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

#define N 1000
#define INF 0x3f3f3f3f

struct Point {
    double x,y;
};

int s,p;
int vis[N];
Point a[N];
double d[N],G[N][N];

void init() {
    for (int i = 0; i < p; ++i) {
        for (int j = 0; j < p; ++j) {
            G[i][j] = -1;
        }
        d[i] = -1;
        vis[i] = 0;
    }
}

double dis(Point a, Point b) {
    return sqrt((a.x -b.x) * (a.x -b.x) + (a.y -b.y) * (a.y -b.y));
}

int main () {
    int T;
    scanf("%d",&T);
    while (T--) {

        scanf("%d%d",&s,&p);

        for (int i = 0; i < p; ++i) {
            scanf("%lf%lf",&a[i].x,&a[i].y);
        }


        init();

        for (int i = 0; i < p - 1; ++i) {
            for (int j = i + 1; j < p; ++j) {
                G[j][i] = G[i][j] = dis(a[i], a[j]);
            }
        }

        d[0] = 0;
        while (1) {
            int v = -1;

            for (int i = 0; i < p; ++i) {
                if (!vis[i] && (v == -1 || (d[v] > d[i] && d[i] != -1) ) ) {
                    v = i;
                }
            }

            if (v == -1) break;
            vis[v] = 1;

            for (int i = 0; i < p; ++i) {
                if ( !vis[i] && ((d[i] == -1) || (d[i] > G[v][i] && G[v][i] != -1)) ) {
                    d[i] = G[v][i];
                }
            }

        }

        sort(d, d + p);

        printf("%.2f\n",d[p - s]);
    }
    return 0;
}