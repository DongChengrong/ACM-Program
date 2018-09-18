//题目链接：https://pintia.cn/problem-sets/994805260223102976/problems/994805309963354112
//分析：埃氏筛法打表搞定
#include <stdio.h>
#include <string.h>

#define N 1100000

int a[N], vis[N];

void init() {
    int cnt = 1;
    memset(vis, 0, sizeof(vis));
    for (int i = 2; i <= 11000; ++i) {
        if (!vis[i]) {
            for (int j = i + i; j <= 1000000; j += i) {
                vis[j] = 1;
            }
        }
    }
    for (int j = 2; j <= 1000000; ++j) if (!vis[j]) a[cnt++] = j;
}

int main() {
    int n, m;
    init();
    while (scanf("%d %d", &m, &n) != EOF) {
        int cnt = 1;
        for (int i = m; i <= n; ++i) {
            printf("%d%c", a[i], (cnt == 10 || i == n) ? '\n' : ' ');
            cnt = (cnt == 10 ? 1 : cnt + 1);
        }
    }
    return 0;
}
