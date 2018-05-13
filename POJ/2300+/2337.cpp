#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define N 2100
#define M 30
#define For(i, s, n) for (int i = (s); i < (n); ++i)
#define FOR(i, s, n) for (int i = (s); i <= (n); ++i)

int T, n;
int pa[M], vis[M], used[N], d[M], ma[M];
string a[N], res[N];

void init() {
    memset(ma, 0, sizeof(ma));
    memset(d, 0, sizeof(d));
    memset(vis, 0, sizeof(vis));
    memset(used, 0, sizeof(used));
    For (i, 0, M) pa[i] = i;
}

int findset(int x) {
    return x == pa[x] ? x : pa[x] = findset(pa[x]);
}

int dfs(int s, int cnt, bool flag) {
    int num = cnt;
    if (flag) num++;
    if (num == n) {
        for (int i = 0; i < n; ++i) {
            cout << res[i] << (i == n - 1 ? '\n' : '.');
        }
        return 1;
    }

    int i = ma[s]; ma[s]++;
    used[i] = 1;
    res[cnt] = a[i];
    if (dfs(a[i][a[i].size() - 1] - 'a', cnt + 1,flag)) return 1;
    used[i] = 0;

    return 0;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        init();
        int cnt = 26;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            int u = a[i][0] - 'a';
            int v = a[i][a[i].size() - 1] - 'a';
            d[u]++; d[v]--;
            vis[u] = vis[v] = 1;
            int x = findset(u);
            int y = findset(v);
            if (x != y) { pa[x] = y; cnt--; }
        }

        int s = -1, t = -1;
        vector<int> vec;
        for (int i = 0; i < 26; ++i) {
            if (!vis[i]) cnt--;
            if (d[i] != 0) vec.push_back(d[i]);
            if (d[i] == 1) s = i;
            if (d[i] == -1) t = i;
        }

        if (cnt != 1) { puts("***"); continue; }

        sort(a, a + n);

        int pre = -1;
        for (int i = 0; i < n; ++i) {
            int v = a[i][0] - 'a';
            if (v != pre) {
                ma[v] = i;
                pre = i;
            }
        }

        if (vec.empty()) {
            used[0] = 1; res[0] = a[0]; int s = a[0][0] - 'a'; ma[s]++;
            dfs(a[0][a[0].size() - 1] - 'a', 1,false);
        } else if (vec.size() == 2 && ((vec[0] == 1 && vec[1] == -1) || (vec[1] == 1 && vec[0] == -1)) ) {
            for (int i = n - 1; i >= 0; --i) {
                if (a[i][a[i].size() - 1] - 'a' == t) {
                    res[n - 1] = a[i]; used[i] = 1; break;
                }
            }

            for (int i = ma[s]; i < n; ++i) {
                if (a[i][0] - 'a' == s && !used[i]) {
                    used[i] = 1; res[0] = a[i];
                    if (dfs(a[i][a[i].size() - 1] - 'a', 1,true)) break;
                }

            }
        } else puts("***");
    }
    return 0;
}
