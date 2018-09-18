/*
*UVA507
*最大子段和的相关问题
*与传统的最大子段和问题不同的地方在于加上限制条件长度
*注意边界条件
**/
#include <stdio.h>
#include <string.h>

#define N 110000
#define INF 0x3f3f3f3f

int a[N];

int main() {
    int T;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        int i = 2, j = 1;
        int sum, MAX, len = 1;
        int l = 1, r = 2, n;   //边界条件
        scanf("%d", &n);
        for (int i = 1; i <= n - 1; ++i) scanf("%d", &a[i]); a[n] = -INF;
        sum = MAX = a[1];
        while (i <= n) {
            if (sum > MAX || (sum == MAX && len < (i - j))) {
                len = i - j; MAX = sum;
                l = j; r = i;
            }
            if (sum >= 0) {
                sum += a[i++];
            } else {
                j = i; sum = a[i++];
            }
        }
        if (MAX > 0) printf("The nicest part of route %d is between stops %d and %d\n", kase, l, r);
        else printf("Route %d has no nice parts\n", kase);
    }
    return 0;
}
