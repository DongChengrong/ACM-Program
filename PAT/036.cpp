//题目链接：https://pintia.cn/problem-sets/994805342720868352/problems/994805502658068480
//抱着试一试的心态写了发暴力，结果竟然过了
//拍四次序就搞定了
#include <stdio.h>
#include <string.h>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define N 3300
#define INF 0x3f3f3f3f

int n, m;

struct Node {
    string id;
    int a, b, c, d;
    int aa, bb, cc, dd;
    int best;
    char sys;
    void init() {
        d = (a + b + c) / 3;
        best = INF;
    }
    void _best() {
        best = min(min(aa, min(cc, dd)), bb);
        if (dd == best) {
            sys = 'A';
        } else if (aa == best) {
            sys = 'C';
        } else if (bb == best) {
            sys = 'M';
        } else if (cc == best) {
            sys = 'E';
        }
    }
};

Node a[N];

bool cmp1(Node a, Node b) {
    return a.d > b.d;
}

bool cmp2(Node a, Node b) {
    return a.a > b.a;
}

bool cmp3(Node a, Node b) {
    return a.b > b.b;
}

bool cmp4(Node a, Node b) {
    return a.c > b.c;
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        unordered_map<string, int> ma;
        for (int i = 1; i <= n; ++i) {
            char tmp[10];
            scanf("%s %d %d %d", tmp, &a[i].a, &a[i].b, &a[i].c);
            a[i].id = tmp; a[i].init();
        }
        sort(a + 1, a + 1 + n, cmp1);
        for (int i = 1; i <= n; ++i) {
            int j = i;
            if (i != 1 && a[i].d == a[i - 1].d) {
                j = a[i - 1].dd;
            }
            a[i].dd = j;
        }
        sort(a + 1, a + 1 + n, cmp2);
        for (int i = 1; i <= n; ++i) {
            int j = i;
            if (i != 1 && a[i].a == a[i - 1].a) {
                j = a[i - 1].aa;
            }
            a[i].aa = j;
        }
        sort(a + 1, a + 1 + n, cmp3);
        for (int i = 1; i <= n; ++i) {
            int j = i;
            if (i != 1 && a[i].b == a[i - 1].b) {
                j = a[i - 1].bb;
            }
            a[i].bb = j;
        }
        sort(a + 1, a + 1 + n, cmp4);
        for (int i = 1; i <= n; ++i) {
            ma[a[i].id] = i;
            int j = i;
            if (i != 1 && a[i].c == a[i - 1].c) {
                j = a[i - 1].cc;
            }
            a[i].cc = j;
            a[i]._best();
        }
        while (m--) {
            char tmp[110];
            scanf("%s", tmp);
            int id = ma[tmp];
            if (id) {
                printf("%d %c\n", a[id].best, a[id].sys);
            } else {
                puts("N/A");
            }
        }
    }
    return 0;
}
