/*
很遗憾没学会刘汝佳的做法，不过我们可以把它们均分最后用二分确定一下大小就好了
*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define N 2200

double a[N], b[N];

int main() {
    int n,m;
    while (scanf("%d%d",&n, &m) == 2) {
        double a_cnt = 10000.0 / n;
        double b_cnt = 10000.0 / (n + m);
        for (int i = 0; i < n; ++i) {
            a[i] = i * a_cnt;
        }
        for (int i = 0; i < n + m; ++i) {
            b[i] = i * b_cnt;
        }
        double ans = 0;
        for (int i = 1; i < n; ++i) {
            int p = lower_bound(b, b + n + m, a[i]) - b;
            ans += min(fabs(b[p - 1] - a[i]), fabs(b[p] - a[i]));
        }
        printf("%.4f\n",ans);
    }
    return 0;
}
