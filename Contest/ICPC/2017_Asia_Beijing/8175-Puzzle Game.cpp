/*
*分析：最大子矩阵衍生问题
*经典，预处理某一点上下左右的最大子矩阵
*找到任意一个最大子矩阵，进行枚举修改
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 160
#define INF 0x3f3f3f3f

int n, m, p, MAX;
int s[N][N], val[N][N], L[N], R[N], U[N], D[N];

void init() {
    MAX = -INF;
    memset(s, 0, sizeof(s));
    memset(L, 0, sizeof(L));
    memset(R, 0, sizeof(R));
    memset(U, 0, sizeof(U));
    memset(D, 0, sizeof(D));
}

void read() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &val[i][j]);
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + val[i][j];
        }
    }
}

void pre() {
    //预处理U
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            int tmp = -INF, ans = -INF;
            for (int k = 1; k <= m; ++k) {
                int x = s[j][k] - s[i - 1][k] - (s[j][k - 1] - s[i - 1][k - 1]);
                if (tmp < 0) tmp = x;
                else tmp += x;
                ans = max(ans, tmp);
                MAX = max(tmp, MAX);
            }
            U[j + 1] = max(U[j], max(ans, U[j + 1]));
        }
    }
    //预处理D
    for (int i = n; i <= 1; --i) {
        for (int j = i; j <= n; ++j) {
            int ans = -INF, tmp = -INF;
            for (int k = 1; k <= m; ++k) {
                int x = s[j][k] - s[i - 1][k] - (s[j][k - 1] - s[i - 1][k - 1]);
                if (tmp < 0) tmp = x;
                else tmp += x;
                ans = max(tmp, ans);
            }
            D[i - 1] = max(D[i], max(ans, D[i - 1]));
        }
    }
    //预处理L
    for(int i = 1; i <= m; ++i) {
        for (int j = i; j <= m; ++j) {
            int ans = -INF, tmp = -INF;
            for (int k = 1; k <= n; ++k) {
                int x = s[k][j] - s[k][i - 1] - (s[k - 1][j] - s[k - 1][i - 1]);
                if (tmp < 0) tmp = x;
                else tmp += x;
                ans = max(tmp, ans);
            }
            L[j + 1] = max(L[j], max(L[j + 1], ans));
        }
    }
    //预处理R
    for (int i = m; i >= 1; --i) {
        for (int j = i; j <= m; ++j) {
            int ans = -INF, tmp = -INF;
            for (int k = 1; k <= n; ++k) {
                int x = s[k][j] - s[k][i - 1] - (s[k - 1][j] - s[k - 1][i - 1]);
                if (tmp < 0) tmp = x;
                else tmp += x;
                ans = max(tmp, ans);
            }
            R[i - 1] = max(R[i], max(ans, R[i - 1]));
        }
    }
}

int main() {
    while (scanf("%d%d%d", &n, &m, &p) != EOF) {
        init();
        read();
        pre();
        int st, et;
        int sx, sy, ex, ey;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                int ans = -INF;
                for (int k = 1; k <= m; ++k) {
                    int x = s[j][k] - s[i - 1][k] - (s[j][k - 1] - s[i - 1][k - 1]);
                    if (ans < 0) ans = x, st = k;
                    else ans += x;
                    if (ans == MAX) {
                        sx = i, ex = j, sy = st, ey = k;
                        goto LOOP;
                    }
                }
            }
        }
        LOOP: ;
        int res = MAX;
        for (int i = sx; i <= ex; ++i) {
            for (int j = sy; j <= ey; ++j) {
                int tmp = MAX - val[i][j] + p;
                res = min(MAX, max(tmp, max(L[j], max(R[j], max(U[i], D[i])))));
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
