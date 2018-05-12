//因为必须从(1,1)出发所以要初始化为负无穷
#include <bits/stdc++.h>
using namespace std;

#define N 30
#define M 1100

int m, n, T;
vector<int> pre[M];
int a[N][M], dp[N][M];

void init() {
    for (int i = 1; i <= 1000; ++i) {
        for (int j = 1; j < i; ++j) {
            if (i % j == 0) pre[i].push_back(j);
        }
    }
}

int main() {
    init();
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&m,&n);

        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = -99999999;
            }
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                scanf("%d",&a[i][j]);
            }
        }

        dp[1][1] = a[1][1];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == 1 && j == 1) continue;
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  //从上面和左边过来
                for (int k = 0; k < pre[j].size(); ++k) {  //从k倍过来
                    int y = pre[j][k];
                    dp[i][j] = max(dp[i][j], dp[i][y]);
                }
                dp[i][j] += a[i][j];
            }
        }
        printf("%d\n",dp[m][n]);
    }
    return 0;
}
