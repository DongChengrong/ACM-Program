#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 200010

int n, m;
int pa[2 * N];

int findset(int x) {
    return x == pa[x] ? pa[x] : pa[x] = findset(pa[x]);
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        int q, ans = n + m - 1;
        for (int i = 1; i <= n + m; ++i) pa[i] = i;
        scanf("%d", &q);
        while (q--) {
            int u, v;
            scanf("%d%d", &u, &v);
            int x = findset(u);
            int y = findset(v + n);
            if (x != y) {
                --ans;
                pa[x] = y;
                findset(x);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
