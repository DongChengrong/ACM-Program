#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define N 5500

int a[N];
int n, T;
vector<int> l[N], r[N];

int judge() {
    for (int i = 0; i < n; ++i) {
        l[i].clear(); r[i].clear();
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[i]) r[i].push_back(a[j]);
        }
        for (int j = i - 1; j >= 0; --j) {
            if (a[j] > a[i]) l[i].push_back(a[j]);
        }
        sort(r[i].begin(), r[i].end());
        sort(l[i].begin(), l[i].end());
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] < a[j]) {
                if (l[i].empty() || r[j].empty()) continue;
                int pos1 = lower_bound(r[j].begin(), r[j].end(), a[i]) - r[j].begin();
                if (pos1 == r[j].size() || r[j][pos1] < a[i]) continue;
                int pos2 = lower_bound(l[i].begin(), l[i].end(), r[j][pos1]) - l[i].begin();
                if (pos2 != l[i].size() && l[i][pos2] < a[j]) return 1;
            }
        }
    }
    return 0;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        if (judge()) puts("YES");
        else {
            reverse(a, a + n);
            if (judge()) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}
