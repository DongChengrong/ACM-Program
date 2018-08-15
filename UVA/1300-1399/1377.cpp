#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 220
#define INF 0x3f3f3f3f

int n, m, maxLen;
int a[N], b[N], vis[N], scales[N];

void make_scale(int cnt) {
    for (int i = 0; i < cnt; ++i) {
        int tmp = b[cnt] - b[i];
        for (int j = 0; j < n; ++j) {
            if (tmp == a[j]) {
                vis[j] = 1;
            }
        }
    }
}

int judge() {
    for (int i = 0; i < n; ++i) if (!vis[i]) return 0;
    return 1;
}

void init() {
    sort(a, a + n);
    m = INF, maxLen = a[n - 1];
    memset(vis, 0, sizeof(vis));
    b[0] = 0; b[1] = a[0];
    make_scale(1);
}

void dfs(int cnt) {
    int vis2[N];
    if (cnt > m || b[cnt - 1] > maxLen) return;
    if (judge()) {
        if (cnt < m || (cnt == m && maxLen < b[cnt - 1])) {
            memcpy(scales, b, sizeof(scales));
            m = cnt; maxLen = b[cnt - 1];
            return;
        }
    }

    memcpy(vis2, vis, sizeof(vis2));
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            for (int j = 0; j < cnt; ++j) {
                if (b[j] + a[i] > b[cnt - 1]) {
                    b[cnt] = b[j] + a[i];
                    make_scale(cnt);
                    dfs(cnt + 1);
                    memcpy(vis, vis2, sizeof(vis));
                }
            }
        }
    }
}

int main() {
    int kase = 1;
    while (scanf("%d", &n) != EOF && n) {
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        init();
        dfs(2);
        printf("Case %d:\n", kase++);
        printf("%d\n", m);
        for (int i = 0; i < m; ++i) printf("%d%c", scales[i] , i == m - 1 ? '\n' : ' ');
    }
    return 0;
}
