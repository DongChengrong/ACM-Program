//ÌâÄ¿Á´½Ó£ºhttps://pintia.cn/problem-sets/994805342720868352/problems/994805345401028608
#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

#define N  11000

struct Node {
    string name;
    int a, b, c, d;
    void init() { a = b = c = d = -1; }
    void convert() {
        if (a < 200) return;
        if (b > c) d = (b * 0.4) + (c * 0.6) + 0.5;
        else d = c;
    }
    bool operator < (const Node &u) const {
        if (d != u.d) return d > u.d;
        return name < u.name;
    }
};

int p, n, m;
Node a[N];
map<string, int> ma;

int main() {
    cin >> p >> m >> n;
    for (int i = 1; i <= p; ++i) {
        a[i].init();
        cin >> a[i].name >> a[i].a;
        ma[a[i].name] = i;
    }
    string name; int point;
    for (int i = 1; i <= m; ++i) {
        cin >> name >> point;
        if (!ma[name]) continue;
        int id = ma[name];
        a[id].b = point;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> name >> point;
        if (!ma[name]) continue;
        int id = ma[name];
        a[id].c = point;
        a[id].convert();
    }
    sort(a + 1, a + 1 + p);
    for (int i = 1; i <= p; ++i) {
        if (a[i].a < 200) continue;
        if (a[i].d < 60 || a[i].d > 100) continue;
        cout << a[i].name;
        printf(" %d %d %d %d\n", a[i].a, a[i].b, a[i].c, a[i].d);
    }
    return 0;
}
