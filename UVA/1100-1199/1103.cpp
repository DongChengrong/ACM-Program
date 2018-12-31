//深搜好题
//思路很简单，人脑的话一会就做出来了，关键是实现的细节，很巧妙的利用了深搜
#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define N 220

int h, w;
char base[256][10];
int G[N][N], vis[N][N];
char line[N];
vector<set<int> > neigh;

const int dr[4] = {-1, 1, 0, 0};
const int dc[4] = {0, 0, -1, 1};
const char codes[10] = "WAKJSD";

void init() {
    strcpy(base['0'], "0000");
    strcpy(base['1'], "0001");
    strcpy(base['2'], "0010");
    strcpy(base['3'], "0011");
    strcpy(base['4'], "0100");
    strcpy(base['5'], "0101");
    strcpy(base['6'], "0110");
    strcpy(base['7'], "0111");
    strcpy(base['8'], "1000");
    strcpy(base['9'], "1001");
    strcpy(base['a'], "1010");
    strcpy(base['b'], "1011");
    strcpy(base['c'], "1100");
    strcpy(base['d'], "1101");
    strcpy(base['e'], "1110");
    strcpy(base['f'], "1111");
}

void decode(int i, int j, char c) {
    for (int k = 0; k < 4; ++k) {
        G[i][j + k] = base[c][k] - '0';
    }
}

void print() {
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            printf("%d", G[i][j]);
        }
        puts("");
    }
}

void dfs(int i, int j, int cnt) {
    vis[i][j] = cnt;
    for (int k = 0; k < 4; ++k) {
        int x = i + dr[k];
        int y = j + dc[k];
        if (x >= 0 && x < h && y >= 0 && y < w && G[x][y] == G[i][j] && vis[x][y] == 0) {
            dfs(x, y, cnt);
        }
    }
}

void check(int i, int j) {
    int cnt = vis[i][j];
    for (int k = 0; k < 4; ++k) {
        int x = i + dr[k];
        int y = j + dc[k];
        if (x >= 0 && x < h && y >= 0 && y < w && !G[x][y] && vis[x][y] != 1) {
            neigh[cnt].insert(vis[x][y]);
        }
    }
}

int rec(int x) {
    return codes[neigh[x].size()];
}

int main() {

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    init();
    int kase = 0;
    while (scanf("%d%d", &h, &w) != EOF && (h + w)) {
        memset(G, 0, sizeof(G));
        for (int i = 1; i <= h; ++i) {
            scanf("%s", line);
            for (int j = 0; j < w; ++j) {
                decode(i, j * 4 + 1, line[j]);
            }
        }
        h += 2; w = 4 * w + 2;
        int cnt = 0;
        vector<int> cc;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (!vis[i][j]) {
                    dfs(i, j, ++cnt);
                    if (G[i][j]) cc.push_back(cnt);
                }
            }
        }
        neigh.clear();
        neigh.resize(cnt + 2);
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (G[i][j]) check(i, j);
            }
        }
        int sz = cc.size();
        vector<char> vec;
        for (int i = 0; i < sz; ++i) {
            vec.push_back(rec(cc[i]));
        }
        sz = vec.size();
        sort(vec.begin(), vec.end());
        printf("Case %d: ", ++kase);
        for (int i = 0; i < sz; ++i) printf("%c", vec[i]);
        puts("");
    }
    return 0;
}
