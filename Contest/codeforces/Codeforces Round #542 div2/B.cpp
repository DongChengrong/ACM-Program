#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define N 220000

typedef long long ll;

struct Node {
    int a, b;
    bool operator < (const Node &u) const {
        if (a != u.a) return a < u.a;
        return b < u.b;
    }
};

Node a[N];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int m = 2 * n;
        for (int i = 1; i <= m; ++i) {
            scanf("%d", &a[i].a);
            a[i].b = i;
        }
        sort(a + 1, a + m + 1);
        ll res = 0, t1 = 1, t2 = 1;
        for (int i = 1; i <= m; i += 2) {
            res += abs(a[i].b - t1);
            res += abs(a[i + 1].b - t2);
            t1 = a[i].b; t2 = a[i + 1].b;
        }
        printf("%I64d\n", res);
    }
    return 0;
}
