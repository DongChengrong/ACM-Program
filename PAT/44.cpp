#include <stdio.h>
#include <string>
#include <string.h>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define N 10100

double c[26];

struct Node {
    string name;
    int m, d, h, mi, time, state;
    double cost;
    void init() {
        time = (d - 1) * 24 * 60 + h * 60 + mi;
        cost = ((d - 1) * 60 * c[23] + \
         (h != 0? c[h - 1] * 60 : 0) + mi * ((h ? c[h] - c[h - 1] : c[0]))) / 100;
    }
    bool operator < (const Node &u) const {
        if (name != u.name) return name < u.name;
        return time < u.time;
    }
};

Node a[N];

void print(Node u) {
    cout << u.name << " ";
    printf("%02d:%02d:%02d:%02d", u.m, u.d, u.h, u.mi);
    printf(" %d\n", u.time);
}

int main() {
    for (int i = 0; i < 24; ++i) {
        scanf("%lf", &c[i]);
        if (i != 0) c[i] += c[i - 1];
    }
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].name;
        char tmp[10];
        scanf("%d:%d:%d:%d %s", &a[i].m, &a[i].d, &a[i].h, &a[i].mi, tmp);
        a[i].state = (tmp[1] == 'n' ? 0 : 1);
        a[i].init();
    }

    map<string, vector<Node>> ma;
    sort(a, a + n);
    for (int i = 1; i < n; ++i) {
        if (a[i].state && !a[i - 1].state && a[i].name == a[i - 1].name) {
            if (a[i].time >= a[i - 1].time) {
                ma[a[i].name].push_back(a[i - 1]);
                ma[a[i].name].push_back(a[i]);
            }
        }
    }

    for (auto it : ma) {
        double tot = 0;
        vector<Node> res = it.second;
        cout << res[0].name; printf(" %02d\n", res[0].m);
        for (int i = 1; i < res.size(); i += 2) {
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", \
               res[i - 1].d, res[i - 1].h, res[i - 1].mi, res[i].d, \
               res[i].h, res[i].mi, res[i].time - res[i - 1].time, \
               (res[i].cost - res[i - 1].cost));
            tot += res[i].cost - res[i - 1].cost;
        }
        printf("Total amount: $%.2f\n", tot);
    }
    return 0;
}
