#include <iostream>
#include <string>
#include <string.h>
#include <unordered_map>
#include <algorithm>
#include <sstream>

using namespace std;

#define N 110

int n, m, x, y;
int cnt;
int vis[N][N];
string G[N];
unordered_map<int, int> ma;

void init() {
    cnt = 0;
    ma.clear();
    memset(vis, 0, sizeof(vis));
}

int dfs(int x, int y, int color) {
    vis[x][y] = color;
    int res = 1;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int xx = x + i, yy = y + j;
            if (xx >= 0 && xx < m && yy >= 0 && yy < n && vis[xx][yy] == 0 && G[xx][yy] == 'W') res += dfs(xx, yy, color);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T; cin >> T; cin.get(); cin.get();
    while (T--) {
        int i = 0;
        init();
        string line;
        while (getline(cin, line)) {
            if (isdigit(line[0])) break;
            G[i++] = line;
        }
        m = i, n = G[0].size();
        while (1) {
            stringstream ss(line);
            ss >> x >> y; --x; --y;
            if (vis[x][y]) cout << ma[vis[x][y]] << '\n';
            else {
                int tot = dfs(x, y, ++cnt);
                ma[vis[x][y]] = tot;
                cout << tot << '\n';
            }
            getline(cin, line);
            if (line == "") break;
        }
        if (T) cout <<'\n';
    }
    return 0;
}
