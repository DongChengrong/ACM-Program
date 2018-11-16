#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 1100

int a[N], b[N], vis[N];

int main() {
    int n, s;
    while (scanf("%d%d", &n, &s) != EOF ) {
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
        if (s == 1) puts("YES");
        else if (!a[1]) puts("NO");
        else {
            int last = 1;
            for (int i = 1; i <= n; ++i) {
                if (a[i]) {
                    vis[i] = 1;
                    if (b[i]) last = i;
                }
            }
            for (int j = last; j >= 1; --j) {
                if (b[j]) vis[j] = 1;
            }
            if (vis[s]) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}
