/*
¼ÇÒä»¯ËÑË÷
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define N 30
#define _for(i,a,b) for(int i = (a); i < (b); ++i)

int cnt = 1;
int n, m, k;
int cherry[N][N][N][N], dp[N][N][N][N];

int count(int i, int j, int h, int w) {
    int &ans = cherry[i][j][h][w];
    if (ans != -1) return ans;

    if (w > 1) return ans = count(i, j, h, 1) + count(i, j + 1, h, w - 1);
    return ans = count(i, j, 1, w) + count(i + 1, j, h - 1, w);
}

int dfs(int i, int j, int H, int W) {
    int &ans = dp[i][j][H][W];
    if (ans != -1) return ans;
    if (count(i, j, H, W) == 1) return ans = 0;

    auto updateAns = [&ans](int a) {
        if (ans == -1) ans = a;
        else ans = min(ans, a);
    };

    _for (h, 1, H)   //ºáÅÙ
        if (count(i, j, h, W) >= 1 && count(i + h, j, H - h, W) >= 1)
            updateAns(W + dfs(i, j, h, W) + dfs(i + h, j, H - h, W));

    _for (w, 1, W) //ÊúÅÙ
        if (count(i, j, H, w) >= 1 && count(i, j + w, H, W - w) >= 1)
            updateAns(H + dfs(i, j, H, w) + dfs(i, j + w, H, W - w) );

    return ans;
}

int main() {
    int kase = 1;
    while (scanf("%d%d%d",&n, &m, &k) == 3) {

        cnt = 1;
        memset(cherry, -1, sizeof(cherry));
        memset(dp, -1, sizeof(dp));

        _for (i, 0, n) _for (j, 0, m) cherry[i][j][1][1] = 0;
        _for (i, 0, k) {
            int x, y;
            scanf("%d%d",&x, &y);
            cherry[x - 1][y - 1][1][1] = 1;
        }

        printf("Case %d: %d\n", kase++, dfs(0, 0, n, m));
    }
    return 0;
}
