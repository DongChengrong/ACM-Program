//ÌâÄ¿Á´½Ó£ºhttp://118.190.20.162/view.page?gpid=T62
#include <stdio.h>
#include <algorithm>

using namespace std;

#define N 21000

struct Node {
    int id, sta, time;
    bool operator < (const Node &u) const {
        if (time != u.time) return time < u.time;
        if (sta != u.sta) return sta > u.sta;
        return id < u.id;
    }
};

Node a[N];
int pos[N];

int main() {
    int n, m, cnt = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) pos[i] = i;
    for (int i = 0; i < m; ++i) {
        int w, u, v;
        scanf("%d%d%d", &w, &u, &v);
        a[cnt++] = (Node) { w, 0, u };
        a[cnt++] = (Node) { w, 1, u + v };
    }
    sort(a, a + cnt);
    for (int i = 0; i < cnt; ++i) {
        int id = a[i].id, j;
        if (!a[i].sta) {
            for (j = 1; j <= n; ++j) if (pos[j] == id) break;
            pos[j] = -1;
        } else {
            for (j = 1; j <= n; ++j) if (pos[j] == -1) break;
            pos[j] = id;
        }
    }
    for (int i = 1; i <= n; ++i) printf("%d%c", pos[i], i == n ? '\n' : ' ');
    return 0;
}
