//ÌâÄ¿Á´½Ó£ºhttps://pintia.cn/problem-sets/994805148990160896/problems/994805149279567872
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

#define N 110

int n, m, l, ok = 0;
vector<int> ans;
int wolf[N], said[N];

int dfs(int s) {
    if (ans.size() == m) {
        int tot = 0, wo = 0;
        for (int i = 1; i <= n; ++i) {
            if ((said[i] > 0 && wolf[said[i]]) || (said[i] < 0 && !wolf[-said[i]])) {
                tot++;
                if (wolf[i]) ++wo;
            }
            if (tot > l) return 0;
        }
        if (tot == l && wo) {
            ok = 1;
            for (int i = 0; i < ans.size(); ++i) printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
            return 1;
        }
    }
    for (int i = s; i >= 1; --i) {
        if (i + ans.size() < m) break;
        ans.push_back(i);
        wolf[i] = 1;
        if (dfs(i - 1)) return 1;
        wolf[i] = 0;
        ans.pop_back();
    }
    return 0;
}

int main() {
    scanf("%d%d%d", &n, &m, &l);
    for (int i = 1; i <= n; ++i) scanf("%d", &said[i]);
    dfs(n);
    if (!ok) puts("No Solution");
    return 0;
}
