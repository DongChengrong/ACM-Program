/*
这个题不可以使用贪心算法求解
多重背包问题的变形
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define N 440

int n;

struct Node {
    int h, a, c;
    bool operator < (const Node & a) const {
        return this->a < a.a;
    }
}a[N];

int dp[N];

int main() {
    int MAX = 0;
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d%d",&a[i].h, &a[i].a, &a[i].c);
        MAX = max(a[i].a, MAX);
    }

    sort(a + 1, a + n + 1);

    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= a[i].c && j * a[i].h <= a[i].a; ++j) {
            for (int k = a[i].a; k >= a[i].c; --k) {
                dp[k] = max(dp[k], dp[k - a[i].h] + a[i].h);
            }
        }
    }
    printf("%d\n",dp[MAX]);
    return 0;
}
