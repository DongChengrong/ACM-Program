#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define N 100000 + 100

int vis[N];

struct Node {
    int l, r, id;
}a[N];

int cmp1(Node a, Node b) {
    return a.l < b.l;
}

struct cmp2 {
    bool operator () (Node &a, Node &b) {
        return a.r > b.r;
    }
};

int main() {
    int T;
    scanf("%d",&T);
    while (T--) {
        int n, cnt, i = 0;
        vector<int> res1;
        memset(vis, 0, sizeof(vis));
        priority_queue<Node, vector<Node>, cmp2> que;
        scanf("%d",&n); cnt = 0;
        for (int i = 0; i < n; ++i) scanf("%d",&a[i].l), a[i].id = i + 1;
        for (int i = 0; i < n; ++i) scanf("%d",&a[i].r);
        sort(a, a + n, cmp1);
        while (1) {
            while (i < n && a[i].l <= cnt) {
                if (a[i].r >= cnt) que.push(a[i++]);
                //printf("%d %d %d\n", cnt, a[i].l, a[i].r);
            }
            if (que.empty()) break;
            else {
                Node u = que.top(); que.pop();
                if (u.r >= cnt && u.l <= cnt) {
                    res1.push_back(u.id);
                    vis[u.id] = 1;
                    cnt++;
                }
            }
        }

        printf("%d\n",res1.size());
        for (int i = 1; i <= n; ++i) if (!vis[i]) res1.push_back(i);
        for (int i = 0; i < res1.size(); ++i) printf("%d%c",res1[i], i == res1.size() - 1 ? '\n' : ' ');
    }
    return 0;
}
