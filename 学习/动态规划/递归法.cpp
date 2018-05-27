#include <stdio.h>
#include <string.h>

#define N 11000

int a[N];
int n, m;

int dfs(int i, int sum) {
    if (sum == 0) return 1;
    if (i >= n) return 0;

    if (dfs(i + 1, sum + a[i])) return 1;
    if (dfs(i + 1, sum)) return 1;

    return 0;

}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("oil.in", "r", stdin);
    freopen("oil.out", "w", stdout);
    #endif // ONLINE_JUDGE

    while (scanf("%d%d",&n, &m) == 2) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d",&a[i]);
            sum += a[i];
        }

        if (sum < m) { puts("no"); continue; }
        if (sum == m) { puts("yes"); continue; }

        if (dfs(0, 0)) puts("yes");
        else puts("no");
    }
    return 0;
}
