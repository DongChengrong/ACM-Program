//枚举所有可能的发车顺序，使用STL中的next_permutation
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 15
#define INF 0x3f3f3f3f
#define _for(i, a, b) for (int i = (a); i < (b); ++i)

typedef long long ll;

int n, a[N];
double l, t;
double v[N], time[N];

int main() {
    int kase = 0;
    while (scanf("%lf", &l) && l != 0) {
        scanf("%d%lf", &n, &t);
        for (int i = 0; i < n; ++i) a[i] = i;
        for (int i = 0; i < n; ++i) {
            scanf("%lf", &v[i]);
        }
        int cost = INF;
        do {
            int ok = 1;
            for (int i = 0; i < n; ++i) {
                time[i] = l / v[a[i]] + i * t;
                if (i != 0 && time[i] < time[i - 1]) ok = 0;
            }
            if (ok) cost = min(cost, (int)time[n - 1]);
        } while (next_permutation(a, a + n));
        printf("Case %d: %d\n", ++kase, cost);
    }
    return 0;
}
