#include <iostream>
#include <vector>
#include <stdio.h>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

#define M 110

const int maxn = 10000 + 100;
const int maxb = 1000000000 + 10;

struct Node {
    int p, q;
};

int cnt = 1;
int n, b;
char s1[M], s2[M];
vector<Node> v[maxn];
unordered_map<string, int> ma;

int _id(string s) {
    if (ma[s]) return ma[s];
    else return ma[s] = cnt++;
}

int ok(int x) {
    int sum = 0;
    for (int i = 1; i < cnt; ++i) {
        int tmp = maxb;
        for (int j = 0; j < v[i].size(); ++j) {
            if (v[i][j].q >= x) tmp = min(tmp, v[i][j].p);
        }
        if (tmp == maxb) return 0;
        else sum += tmp;
    }
    return sum <= b;
}

int main() {
    int T;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d", &T);
    while (T--) {
        cnt = 1; ma.clear();
        for (int i = 0; i < maxn; ++i) v[i].clear();
        scanf("%d%d", &n, &b);
        for (int i = 0; i < n; ++i) {
            int id, p, q;
            scanf("%s %s %d %d", s1, s2, &p, &q);
            id = _id(s1);
            v[id].push_back((Node){p, q});
        }
        int res = 0, l = 0, r = maxb;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (ok(mid)) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
