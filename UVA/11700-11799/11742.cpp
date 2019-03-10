#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define N 15
#define M 25

int a[N];
int n, m;

struct Node {
    int a, b, c;
}b[M];

int dis(int x, int y) {
    int i, j;
    for (i = 0; i < n; ++i) if (a[i] == x) break;
    for (j = 0; j < n; ++j) if (a[j] == y) break;
    return abs(i - j);
}

int check() {
    for (int i = 0; i < m; ++i) {
        if (b[i].c > 0) {
            if (dis(b[i].a, b[i].b) > b[i].c) return 0;
        } else {
            if (dis(b[i].a, b[i].b) < -b[i].c) return 0;
        }
    }
    return 1;
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF && (n + m)) {
        int ans = 0;
        for (int i = 0; i < n; ++i) a[i] = i;
        for (int i = 0; i < m; ++i) scanf("%d%d%d", &b[i].a, &b[i].b, &b[i].c);
        do {
            if (check()) ans++;
        } while (next_permutation(a, a + n));
        printf("%d\n", ans);
    }
    return 0;
}
