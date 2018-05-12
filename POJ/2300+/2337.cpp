//有向图的一笔画问题
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define N 1100

int pa[30], vis[30], d[30], used[N];
string words[N];

int findset(int x) {
    return pa[x] == x ? x : pa[x] = findset(pa[x]);
}

void init() {
    for (int i = 0; i < 30; ++i) pa[i] = i;
    memset(vis, 0, sizeof(vis));
    memset(d, 0, sizeof(d));
    memset(used, 0, sizeof(used));
}

int main() {
    ios_base::sync_with_stdio(false);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        int cnt = 26;
        init();
        for (int i = 1; i <= n; ++i) {
            cin >> words[i];
            int s = words[i][0] - 'a';
            int t = words[i][words[i].size() - 1] - 'a';
            int x = findset(s);
            int y = findset(t);
            if (x != y) {
                 pa[x] = y; cnt--;
            }
            d[s]++; d[t]--;
            vis[s] = vis[t] = 1;

        }

        vector<int> vec;
        for (int i = 0; i < 26; ++i) {
            if (!vis[i]) cnt--;
            if (d[i] != 0) vec.push_back(i);
        }

        sort(words + 1, words + n + 1);

        if (cnt == 1 && (vec.empty() || (vec.size() == 2 && ((d[vec[0]] == -1 && d[vec[1]] == 1) || (d[vec[0]] == 1 && d[vec[1]] == -1)) ) )) {
            int cnt = 0;
            char c = words[1][0];
            if (vec.size() != 0) {
                int s;
                if (d[vec[0]] == 1) c = 'a' + vec[0];
                if (d[vec[1]] == 1) c = 'a' + vec[1];
            }
            while (cnt != n) {
                for (int i = 1; i <= n; ++i) {
                    if (!used[i]) {
                        if (words[i][0] == c) {
                            cout << words[i];
                            cout << (cnt == n -1 ? '\n' : '.');
                            cnt++; used[i] = 1; c = words[i][words[i].size() - 1];
                            continue;
                        }
                    }
                }
            }
        } else cout << "***\n";
    }
    return 0;
}
/*
100
2
acm
mca
*/
