#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define N 110000

int a[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, q;
        unordered_map<int, int> ma;
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            if (a[i]) ma[a[i]]++;
        }
        int op, x, y;
        while (q--) {
            scanf("%d", &op);
            if (op == 1) {
                scanf("%d%d", &x, &y);
                if (ma.count(a[x])) {
                    ma[a[x]]--;
                    if (ma[a[x]] == 0) {
                        ma.erase(a[x]);
                    }
                }
                a[x] = y;
                if (y) ++ma[y];
            } else if (op == 2) {
                printf("%d\n", ma.size());
            }
        }
    }
    return 0;
}
