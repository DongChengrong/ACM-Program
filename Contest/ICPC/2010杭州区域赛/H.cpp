#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 1100

typedef long long ll;

int rep[N], x[N], y[N];

struct Node {
    int axis1, axis2;
    int val1, val2;

    bool operator == (const Node &u) const {
        if (axis1 != u.axis1 || axis2 != u.axis2 || val1 != u.val1 || val2 != u.val2)
            return 0;
        return 1;
    }

}a[N];

void read(int i) {
    int val;
    char c;
    while (scanf("%c", &c) && (c != 'X' && c != 'Y' && c != 'Z'));
    a[i].axis1 = (c == 'X' ? 0 : (c == 'Y' ? 1 : 2));
    scanf("=%d", &a[i].val1);
    while (scanf("%c", &c) && (c != 'X' && c != 'Y' && c != 'Z'));
    a[i].axis2 = (c == 'X' ? 0 : (c == 'Y' ? 1 : 2));
    scanf("=%d", &a[i].val2);
    if (a[i].axis1 > a[i].axis2) {
        swap(a[i].axis1, a[i].axis2);
        swap(a[i].val1, a[i].val2);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m, i, j;
        scanf("%d%d", &n, &m);
        for (i = 0; i < m; ++i) read(i);
        i = 0, j = m - 1;
        while (i <= j) {
            while (i <= j && a[i].axis2 == 2) ++i;
            while (i <= j && a[j].axis2 != 2) --j;
            if (i <= j) {
                swap(a[i], a[j]);
                ++i; --j;
            }
        }
        for (i = 0; i < m; ++i) {
            rep[i] = 0;
            for (j = 0; j < i; ++j) {
                if (a[i] == a[j]) {
                    rep[i] = 1; break;
                }
            }
        }
        ll cnt = 0;
        for (int z = 1; z <= n; ++z) {
            int tx, ty, t;
            tx = ty = t = 0;
            memset(x, 0, sizeof(x));
            memset(y, 0, sizeof(y));
            for (int i = 0; i < m; ++i) {
                if (a[i].axis2 == 2) {
                    if (a[i].axis1 == 0 && a[i].val2 == z) {
                        if (!rep[i]) {
                            ++tx; x[a[i].val1] = 1;
                        }
                    } else if (a[i].axis1 == 1 && a[i].val2 == z) {
                        if (!rep[i]) {
                            ++ty; y[a[i].val1] = 1;
                        }
                    }
                } else {
                    if (!rep[i] && !x[a[i].val1] && !y[a[i].val2]) ++t;
                }
            }
            cnt = cnt + (tx + ty) * n + t - tx * ty;
        }
        printf("%lld\n", cnt);
    }
    return 0;
}
