/*
*分析：回溯法跑暴力，可以预先把prime数组打出来，直接存储，复杂度仅为O(1)
*
*/
#include <stdio.h>
#include <math.h>

#define N 50

int vis[50], a[N];
int is_prime[50];

void dfs(int cur, int n) {
    if (cur == n && is_prime[a[n - 1] + a[0]]) {
        for (int i = 0; i < n; ++i) printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
    } else {
        for (int i = 1; i <= n; ++i) {
            if (!vis[i] && is_prime[i + a[cur - 1]]) {
                vis[i] = 1;
                a[cur] = i;
                dfs(cur + 1, n);
                vis[i] = 0;
            }
        }
    }
}

int main() {
    is_prime[5] = is_prime[2] = is_prime[3] = is_prime[7] = is_prime[11] = 1;
    is_prime[13] = is_prime[17] = is_prime[19] = is_prime[23] = is_prime[29] = 1;
    is_prime[31] = is_prime[37] = is_prime[41] = is_prime[43] = is_prime[47] = 1;
    int n, kase = 0;
    while (scanf("%d", &n) != EOF) {
        if (kase) puts("");
        printf("Case %d:\n", ++kase);
        a[0] = 1; vis[1] = 1;
        dfs(1, n);
    }
    return 0;
}
