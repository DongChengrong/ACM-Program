#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

#define N 330

int vis[N];

struct Node {
    int l, r;
    bool operator < (const Node &u) const {
        if (r != u.r) return this->r < u.r;
        return l < u.l;
    }
};

int cmp(Node a, Node b) {
    if (a.l != b.l) return a.l < b.l;
    return a.r < b.r;
}

Node a[N];

int main() {

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int n;
    while (scanf("%d", &n) != EOF && n) {
        for (int i = 0; i < n; ++i) scanf("%d%d", &a[i].l, &a[i].r);
        int MAX = 0;
        for (int st = 0; st < 5; ++st) {
            int num = 0;
            memset(vis, 0, sizeof(vis));
            for(int i = st; i <= 1000 ; i += 5) {
                int x = -1, ed = 1000000;
                for (int k = 0; k < n; ++k) {
                    if (a[k].l <= i && a[k].r > i && !vis[k] && a[k].r < ed) {
                        ed = a[k].r; x = k;
                    }
                }
                if (x != -1) {
                    vis[x] = 1;
                    ++num;
                }
            }
            MAX = max(MAX, num);
        }
        printf("%d\n", MAX);
    }
    return 0;
}
