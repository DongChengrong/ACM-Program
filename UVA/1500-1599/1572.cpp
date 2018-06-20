#include <stdio.h>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

#define N 60
#define _for(i, a, b) for (int i = (a); i < (b); ++i)

int n;
char tmp[N];
int vis[N];
vector <int> G[N];

void init() {
    memset(vis, 0, sizeof(vis));
    _for(i, 0, N) G[i].clear();
}

int id(char tmp[]) {
    int ans = tmp[0] - 'A'; ans *= 2;
    if (tmp[1] == '+') ans++;
    return ans;
}

//ÓÐÏò±ß
void detail(char tmp[]) {
    _for (i, 0, 4) {
        _for (j , 0, 4) {
            if (i == j) continue;
            if (tmp[i * 2] == '0' || tmp[j * 2] == '0') continue;
            int u = id(tmp + i * 2);
            int v = id(tmp + j * 2);
            G[u].push_back(v ^ 1);
        }
    }
}

bool dfs(int u) {
    if (vis[u] == -1) return true;

    vis[u] = -1;

    _for (i, 0, G[u].size()) {
        int v = G[u][i];
        if (vis[v] != 0 && dfs(v)) return true;
    }

    vis[u] = 1;

    return false;
}

bool work() {
    _for (i, 0, 60) {
        if (!vis[i]) {
            if (dfs(i)) return false;
        }
    }
    return true;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    while (scanf("%d",&n) == 1) {
        init(); getchar();
        _for (i, 0, n) {
            scanf("%s", tmp);
            detail(tmp);
        }
        if (work()) puts("bounded");
        else puts("unbounded");
    }
    return 0;
}
