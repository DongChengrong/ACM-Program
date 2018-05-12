#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL m, n;
struct Node {
    LL x, cnt;
};

int main() {
    ios_base::sync_with_stdio(false);
    while (cin >> n >> m && n) {
        if (n >= 50) {
            cout << "Let me try!\n";
            continue;
        }
        queue<Node> q;
        int ok = 0;
        q.push((Node){0, 1});
        while (!q.empty()) {
            Node u = q.front(); q.pop();

            if (u.x == m) {
                ok = 1; break;
            }

            LL dis = u.cnt * 2 - 1;
            if (dis > n + 5) continue;

            int p1 = u.x + dis;
            int p2 = u.x - dis;
            if (p1 <= n) q.push((Node){p1, u.cnt + 1});
            if (p2 >= 1) q.push((Node){p2, u.cnt + 1});
        }
        if (ok) cout << "Let me try!\n";
        else cout << "Don¡¯t make fun of me!\n";
    }
    return 0;
}
