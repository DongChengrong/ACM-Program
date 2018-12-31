#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define N 1100
#define mk(a, b) make_pair(a, b)
#define _for(i, a, b) for (int i = (a); i < (b); ++i)

typedef long long ll;
typedef pair<int, int> P;

int x[N], y[N], a[N], b[N];
map<pair<int, int>, int> ma[2];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        ma[0].clear(); ma[1].clear();
        int u = 0;
        for (int i = 0; i < n; ++i) scanf("%d%d", &x[i], &y[i]);
        for (int i = 0; i < n; ++i) scanf("%d%d", &a[i], &b[i]);
        for (int i = 0; i < n; ++i) ma[0][mk(x[0] + a[i], y[0] + b[i])] = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j)  {
                P p = mk(x[i] + a[j], y[i] + b[j]);
                if (ma[u][p] == 1) {
                    ma[u ^ 1][p] = 1;
                }
            }
            ma[u].clear();
            u = u ^ 1;
        }
        auto it = ma[u].begin();
        P p = it->first;
        printf("%d %d\n", p.first, p.second);
    }
    return 0;
}
