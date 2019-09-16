//尽管有着IDA*这样好听的名字，但其实质上仍然属于暴力，这只是一种比较优美的暴力算法而已
//没有想象中的那么神奇，
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 15

int n;
int a[N];

bool is_sort() {
    for (int i = 0; i < n - 1; ++i) if (a[i] > a[i + 1]) return false; return true;
}

int h() { //乐观估价函数
    int cnt = 0;
    for (int i = 0; i < n - 1; ++i) if (a[i]  + 1 != a[i + 1]) ++cnt;
    if (a[n - 1] != n) ++cnt;
    return cnt;
}

int dfs(int d, int maxd) {
    //for (int i = 0; i < n; ++i) printf("%d ", a[i]); puts("");
    if (is_sort()) return 1;
    if (3 * d + h() > 3  * maxd) return 0;
    if (d == maxd) return 0;
    int old[N], b[N];
    memcpy(old, a, sizeof(old));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int cnt = 0, cnt2 = 0;
            for (int k = 0; k < n; ++k)
                if (k < i || k > j) b[cnt++] = a[k];
            for (int k = 0; k <= cnt; ++k) {
                cnt2 = 0;
                for (int p = 0; p < k; ++p) a[cnt2++] = b[p];
                for (int p = i; p <= j; ++p) a[cnt2++] = old[p];
                for (int p = k; p < cnt; ++p) a[cnt2++] = b[p];
                if (dfs(d + 1, maxd)) return 1;
                memcpy(a, old, sizeof(a));
            }
        }
    }
    return 0;
}

int main() {
    int kase = 0;
    while (scanf("%d", &n) != EOF && n) {
        int maxd;
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        for (maxd = 0; maxd < 5; ++maxd) {
            if (dfs(0, maxd)) break;
        }
        printf("Case %d: %d\n", ++kase, maxd);
    }
    return 0;
}
