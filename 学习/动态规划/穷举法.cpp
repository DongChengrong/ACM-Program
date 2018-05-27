#include <stdio.h>
#include <string.h>

#define N 110000

int a[N];

int main() {
    int n, m;

    #ifndef ONLINE_JUDGE
    freopen("oil.in", "r", stdin);
    freopen("oil.out", "w", stdout);
    #endif // ONLINE_JUDGE

    while (scanf("%d%d",&n, &m) == 2) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d",&a[i]);
            sum += a[i];
        }

        if (sum < m) { puts("no"); continue; }
        if (sum == m) { puts("yes"); continue; }

        for (int i = 0; i < (1 << n); ++i) {
            sum = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) sum += a[j];
            }
            if (sum == m) { puts("yes"); continue; }
        }

        puts("no");
    }
}
