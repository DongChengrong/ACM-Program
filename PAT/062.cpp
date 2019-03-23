//ÌâÄ¿Á´½Ó£ºhttps://pintia.cn/problem-sets/994805046380707840/problems/994805054207279104
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define N 11000
#define M 110

int n, m;
int a[N];
int dp[N][M];
int choic[N][M];

int cmp(int a, int b) {
    return a > b;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= 0; --j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= a[i] && dp[i][j] <= dp[i - 1][j - a[i]] + a[i]) {
                dp[i][j] = dp[i - 1][j - a[i]] + a[i];
                choic[i][j] = 1;
                //printf("%d %d\n", i, j);
            }
        }
    }
    if (dp[n][m] != m) puts("No Solution");
    else {
        int cnt = m, i = n;
        vector<int> res;
        while (cnt > 0) {
            //printf("%d %d %d\n", i, cnt, choic[i][cnt]);
            if (choic[i][cnt]) {
                res.push_back(a[i]);
                cnt -= a[i];
            }
            --i;
        }
        for (int i = 0; i < res.size(); ++i) printf("%d%c", res[i], i == res.size() - 1 ? '\n' : ' ' );
    }
    return 0;
}
