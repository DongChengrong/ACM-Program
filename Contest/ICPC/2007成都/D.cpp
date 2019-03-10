#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

#define N 1100000

int m, n;
int cnt[N], time[N];

struct Node {
    int cnt, time, id;
    bool operator < (const Node &u) const {
        if (u.cnt != cnt) return cnt < u.cnt;
        return time > u.time;
    }
};

int main() {
    int kase = 0;
    while (scanf("%d%d", &m, &n) != EOF && (m + n)) {
        if (m == 0 || n == 0) { printf("Case %d: 0\n", ++kase); continue; }
        int tmp, cap = 0, sum = 0;
        memset(time, 0, sizeof(time));
        memset(cnt, 0, sizeof(cnt));
        priority_queue<Node> q;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &tmp);
            if (!cnt[tmp] && cap == m) {
                ++sum;
                while (!q.empty()) {
                    Node u = q.top(); q.pop();
                    if (cnt[u.id] == u.cnt && u.time == time[u.id]) {
                        cnt[u.id] = 0; break;
                    }
                }
                --cap;
            }
            if (cnt[tmp] == 0) {
                ++cap;
                time[tmp] = i;
            }
            cnt[tmp]++;
            q.push((Node){cnt[tmp], time[tmp], tmp });
        }
        printf("Case %d: %d\n", ++kase, sum);
    }
    return 0;
}
