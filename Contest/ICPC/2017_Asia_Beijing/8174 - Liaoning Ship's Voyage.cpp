#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

#define N 110

struct Node {
    int x, y, step;
};

struct Point {
    double x, y;
};

struct Line {
    double len;
    Point a, b;
    Line() {}
    void init(Point u, Point v) {
        this->a = u, this->b = v;
        this->len = sqrt((u.x - v.x) * (u.x - v.x) + (u.y - v.y) * (u.y - v.y));
    }
};

struct Triangle {
    double s;
    Line a, b, c;
    double sum() {
        double p = (a.len + b.len + c.len) / 2;
        return sqrt(p * fabs(p - a.len) * fabs(p - b.len) * fabs(p - c.len));
    }
};

int n;
Triangle s;
Point t, l, r;
Line ll, rr, bb;
int vis[N][N];
char G[N][N];

bool in(Node v) {
    double S = 0;
    Point p = (Point) {(double)v.x, (double)v.y};
    Triangle tmp;
    Line a, b, c;
    a.init(t, p); b.init(l, p); c.init(r, p);
    tmp.a = ll, tmp.b = a, tmp.c = b; if (tmp.sum() == 0) return 0; S += tmp.sum();
    tmp.a = rr; tmp.b = a, tmp.c = c; if (tmp.sum() == 0) return 0; S += tmp.sum();
    tmp.a = bb, tmp.b = b, tmp.c = c; if (tmp.sum() == 0) return 0; S += tmp.sum();
    if (S == s.sum()) return 1;
    return 0;
}

bool judge(Node v) {
    if (v.x < 0 || v.x >= n || v.y < 0 || v.y >= n) return 0;
    if (G[n - 1 - v.x][v.y] == '#') return 0;
    if (in(v)) return 0;
    return 1;
}

int main() {

    while (scanf("%d", &n) != EOF) {
        scanf("%lf%lf%lf%lf%lf%lf", &t.x, &t.y, &l.x, &l.y, &r.x, &r.y);
        ll.init(t, l); rr.init(t, r); bb.init(l, r);
        s.a = ll; s.b = rr; s.c = bb; s.s = s.sum();

        for (int i = 0; i < n; ++i) scanf("%s", G[i]);
        memset(vis, 0, sizeof(vis));
        queue<Node> q; q.push((Node){0, 0, 0}); vis[0][0];
        while (!q.empty()) {
            Node u = q.front(); printf("%d %d %d\n", u.x, u.y, u.step);
            if (u.x == n - 1 && u.y == n - 1) {
                printf("%d\n", u.step); break;
            } else q.pop();

            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    if (i == 0 && j == 0) continue;
                    Node v = u; v.x = u.x + i; v.y = u.y + j; v.step++;
                    if (judge(v)) {
                        q.push(v); vis[v.x][v.y] = 1;
                    }
                }
            }
        }
        if (q.empty()) puts("-1");
    }
    return 0;
}
