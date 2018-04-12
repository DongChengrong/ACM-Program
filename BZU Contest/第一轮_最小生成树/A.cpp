#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define N 100

struct Edge {
    int u, v, w;
    Edge() {}
    Edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
    bool operator < (const Edge &a) {
        return w < a.w;
    }
};

char a[4],b[4];
Edge e[N];
int pa[90];

void init() {
    for (int i = 0; i <= 30; ++i) {
        pa[i] = i;
    }
}

int findset(int x) {
    return x == pa[x] ? x : pa[x] = findset(pa[x]);
}

int main() {
    int n, m, x, w;
    while (scanf("%d",&n) == 1 && n) {
        m = 0;
        int cnt = n;
        n--;
        while (n--) {
            scanf("%s%d",a,&x);
            int u = a[0] - 'A' + 1;

            while (x--) {
                scanf("%s%d",b, &w);
                int v = b[0] - 'A' + 1;
                e[m++] = Edge(u, v, w);
            }
        }

        sort(e,e + m);

        int cost = 0;
        init();

        for (int i = 0; i < m; ++i) {
            Edge u = e[i];
            int x = u.u;
            int y = u.v;
            x = findset(x); y = findset(y);
            if (x != y) {
                cost += u.w;
                pa[x] = y;
                cnt--;
            }
            if (cnt == 1) break;
        }

        printf("%d\n",cost);
    }
    return 0;
}