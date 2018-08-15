//埃氏筛法
//在埃氏筛法的基础上稍加修改即可
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 1100000

int n;
int a[N], vis[N];

int judge(int x) {
    int sum = 0;
    while (x) {
        sum += x % 10;
        x /= 10;
    }
    return !vis[sum];
}

void init() {
    n = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 2; i < N; ++i) {
        if (!vis[i]) {
            for (int j = i + i; j < N; j += i) {
                vis[j] = 1;
            }
            if (judge(i)) a[n++] = i;
        }
    }
}

int main() {
    int T;
    init();
    scanf("%d", &T);
    while (T--) {
        int l, r, num;
        scanf("%d%d", &l, &r);
        int pl = lower_bound(a, a + n, l) - a;
        int pr = lower_bound(a, a + n, r) - a;
        num = (a[pr] == r ? pr - pl + 1 : pr - pl);
        printf("%d\n", num);
    }
    return 0;
}
