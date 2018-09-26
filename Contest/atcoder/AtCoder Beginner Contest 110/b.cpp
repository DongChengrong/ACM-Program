#include <stdio.h>
#include <algorithm>

using namespace std;

#define N 1100

int n, m;
int a[N], b[N];

int main() {
    while (scanf("%d%d%d%d", &n, &m, &a[0], &b[0]) != EOF) {
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        for (int i = 1; i <= m; ++i) scanf("%d", &b[i]);
        sort(a, a + n + 1); sort(b, b + m + 1);
        //printf("%d %d\n", a[n], b[0] -1);
        if (a[n] < b[0]) puts("No War");
        else puts("War");
    }
    return 0;
}
