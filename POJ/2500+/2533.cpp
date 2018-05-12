#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define N 1100
#define INF 0x3f3f3f3f

int a[N],d[N];

int main() {
    int n;
    while (scanf("%d",&n) == 1) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d",&a[i]);
        }

        memset(d, INF, sizeof(d));

        int MAX = 0;
        for (int i = 1; i <= n; ++i) {
            int p = lower_bound(d + 1, d + 1 + n, a[i]) - d;
            if (d[p] > a[i]) d[p] = a[i];
            MAX = max(MAX, p);
        }

        printf("%d\n",MAX);
    }
    return 0;
}
