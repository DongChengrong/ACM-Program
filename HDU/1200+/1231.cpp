//最大子段和，水题
#include <stdio.h>
#include <string.h>

#define INF 0x3f3f3f3f

const int maxn = 1e5 + 10;

int a[maxn];

int main() {
    int n;
    while (scanf("%d", &n) != EOF && n) {
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        int i = 0, j = 0;
        int l = -1, r = -1;
        int sum = -1, Max = -INF;
        while (j < n) {
            if (sum < 0) {
                i = j;
                sum = a[j++];
            } else {
                sum += a[j++];
            }
            if (Max < sum) {
                Max = sum; l = i; r = j - 1;
            }
        }
        if (Max < 0) printf("%d %d %d\n", 0, a[0], a[n - 1]);
        else printf("%d %d %d\n", Max, a[l], a[r]);
    }
    return 0;
}
