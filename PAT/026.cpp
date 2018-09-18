/*
*题目链接：简单模拟
*分析：简单模拟
*实现：进行两次排序即可
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 1100
#define M 55

struct Node {
    char id[M];
    int fi, se;
};

bool cmp1(Node u, Node v) {
    return u.fi < v.fi;
}

bool cmp2(Node u, Node v) {
    return u.se < v.se;
}

Node a[N];

int main() {
    int m;
    while (scanf("%d", &m) != EOF) {
        for (int i = 0; i < m; ++i) {
            int h, m, s;
            scanf("%s %d:%d:%d ", a[i].id, &h, &m, &s);
            a[i].fi = h * 3500 + m * 60 + s;
            scanf("%d:%d:%d", &h, &m, &s);
            a[i].se = h * 3600 + m * 60 + s;
        }
        sort(a, a + m, cmp1);
        printf("%s ", a[0].id);
        sort(a, a + m, cmp2);
        puts(a[m - 1].id);
    }
    return 0;
}
