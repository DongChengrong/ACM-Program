#include <stdio.h>
#include <string.h>
#include <algorithm>
 
using namespace std;
 
#define N 110000
 
int n, m, cnt;
int vis1[N], vis2[N];
 
struct Node {
    int id, l, r, val;
    void init() {
        val = cnt;
        val += vis2[r] - vis2[l - 1];
    }
    bool operator < (const Node &u) const {
        if (val != u.val) return val < u.val;
        return id > u.id;
    }
};
 
Node a[N];
 
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a[i].l, &a[i].r);
        a[i].id = i + 1;
        vis1[a[i].l]++; vis1[a[i].r + 1]--;
    }
    int sum = 0;
    cnt = 0;
    for (int i = 1; i <= n; ++i) {
        vis2[i] = vis2[i - 1];
        sum += vis1[i];
        if (!sum) cnt++;
        else if (sum == 1) vis2[i]++;
    }
    for (int i = 0; i < m; ++i) a[i].init();
    sort(a, a + m);
    printf("%d %d\n", a[0].id, a[0].val);
    return 0;
}