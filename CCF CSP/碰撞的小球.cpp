//ÌâÄ¿Á´½Ó£ºhttp://118.190.20.162/view.page?gpid=T72
#include <stdio.h>
#include <string.h>
#include <algorithm>

#define N 110
#define M 1100

int n, l, t;
int vis[M];

struct Node {
    int pos, dir;
}a[N];


int main() {
    scanf("%d%d%d", &n, &l, &t);
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i].pos);
        a[i].dir = 1;
        vis[a[i].pos] = 1;
    }
    while (t--) {
        for (int i = 0; i < n; ++i) {
            if (vis[a[i].pos] > 1) { vis[a[i].pos] -= 3; a[i].dir = a[i].dir ^ 1; }
            else vis[a[i].pos ]--;
            if (a[i].pos == l) a[i].dir = 0;
            if (a[i].pos == 0) a[i].dir = 1;
            if (a[i].dir == 1) a[i].pos += 1;
            if (a[i].dir == 0) a[i].pos -= 1;
            if (vis[a[i].pos] == 1) vis[a[i].pos] = 6;
            else vis[a[i].pos]++;
        }
        //for (int i = 0; i < n; ++i) printf("%d%c", a[i].pos, i == n - 1 ? '\n' : ' ');
    }
    for (int i = 0; i < n; ++i) printf("%d%c", a[i].pos, i == n - 1 ? '\n' : ' ');
    return 0;
}
