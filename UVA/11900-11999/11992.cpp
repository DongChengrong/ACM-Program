//尽管v始终大于零，但是我们需要把整个区间赋值为零，所以需要使用setv应该用-1做标记
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 140000
#define INF (100000000)

int ql, qr, r1, r2;
int r, c, m, op, v;
int _sum, _min, _max;

struct IntervalTree{
    int add[N], sum[N], setv[N], minv[N], maxv[N];

    void pushdown(int o) {
        int lc = o * 2, rc = 2 * o + 1;
        if (setv[o] >= 0) {
            add[lc] = add[rc] = 0;
            setv[lc] = setv[rc] = setv[o];
            setv[o] = -1;
        }
        if (add[o]) {
            add[lc] += add[o]; add[rc] += add[o];
            add[o] = 0;
        }
    }

    void maintain(int o, int l, int r) {
        int lc = 2 * o, rc = 2 * o + 1;
        if (r > l) {
            sum[o] = sum[lc] + sum[rc];
            maxv[o] = max(maxv[lc], maxv[rc]);
            minv[o] = min(minv[lc], minv[rc]);
        }
        if (setv[o] >= 0) maxv[o] = minv[o] = setv[o], sum[o] = setv[o] * (r - l + 1);
        if (add[o]) maxv[o] += add[o], minv[o] += add[o], sum[o] += (r - l + 1) * add[o];
    }

    void update(int o, int l, int r) {
        int lc = 2 * o, rc = 2 * o + 1;
        if (ql <= l && qr >= r) {
            if (op == 1) add[o] += v;
            else { add[o] = 0; setv[o] = v; }
        } else {
            pushdown(o);
            int mid = (l + r) / 2;
            if (ql <= mid) update(lc, l, mid); else maintain(lc, l, mid);
            if (qr > mid) update(rc, mid + 1, r); else maintain(rc, mid + 1, r);
        }
        maintain(o, l, r);
    }

    void query(int o, int l, int r, int _add) {
        if (setv[o] >= 0) {
            int v = setv[o] + _add + add[o];
            _sum += v * (min(qr, r) - max(l, ql) + 1);
            _min = min(_min, v);
            _max = max(_max, v);
        } else if (ql <= l && qr >= r) {
            _sum += sum[o] + _add * (r - l + 1);
            _max = max(_max, maxv[o] + _add);
            _min = min(_min, minv[o] + _add);
        } else {
            int mid = (l + r) / 2;
            if (ql <= mid) query(2 * o, l, mid, _add + add[o]);
            if (qr > mid) query(2 * o + 1, mid + 1, r, _add + add[o]);
        }
    }

};

IntervalTree a[23];

void init() {
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= r; ++i) {
        memset(a[i].setv, -1, sizeof(a[i].setv));
        a[i].setv[1] = 0;
    }
}

int main() {

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    while (scanf("%d%d%d", &r, &c, &m) != EOF) {
        init();
        while (m--) {
            scanf("%d%d%d%d%d", &op, &r1, &ql, &r2, &qr);
            if (op == 3) {
                _sum = 0, _max = -INF, _min = INF;
                for (int i = r1; i <= r2; ++i) {
                    a[i].query(1, 1, c, 0);
                }
                printf("%d %d %d\n", _sum, _min, _max);
            } else {
                scanf("%d", &v);
                for (int i = r1; i <= r2; ++i) {
                    a[i].update(1, 1, c);
                }
            }
        }
    }
    return 0;
}
