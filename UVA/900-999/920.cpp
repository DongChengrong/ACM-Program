#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

#define N 1100
#define _for(i,a,b) for (int i = (a); i < (b); ++i)

struct Point {
    double x, y;
    Point() {}
    Point(double a, double b) {
        x = a; y = b;
    }
    bool operator < (Point a) {
        return x > a.x;
    }
}tmp[N];

struct Line {
    double k, b;  //y = k * x + b
    Point l, r;   //左右端点
    Line() {}

    Line(Point x, Point y) {
        l = x; r = y;
        k = (r.y - l.y) / (r.x - l.x);
        b = r.y - k * r.x;
    }

    Point getPoint(double y) {
        double x = (y - b) / k;
        return Point(x, y);
    }

    //截取线段
    void inter(double y) {
        r = getPoint(y);
    }

    double top() { return max(r.y, l.y); }

    double dis() { return sqrt((r.x - l.x) * (r.x - l.x) + (r.y - l.y) * (r.y - l.y)); }

    bool operator < (Line a) {
        return r.x < a.r.x;
    }

}lines[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        _for (i, 0, n) {
            double x, y;
            scanf("%lf%lf", &x, &y);
            tmp[i] = Point(x, y);
        }

        sort(tmp, tmp + n);

        for(int i = 0; i < n - 1; ++i) {   //建立线段
            //printf("%.2f %.2f %.2f %.2f\n", tmp[i].x, tmp[i].y, tmp[i + 1].x, tmp[i + 1].y);
            lines[i] = Line(tmp[i + 1], tmp[i]);
        }

        double top = 0;
        double ans = 0;

        _for (i, 0, n - 1) {
            //printf("%.2f %.2f       %.2f %.2f\n", lines[i].l.x, lines[i].l.y, lines[i].r.x, lines[i].r.y);
            if (lines[i].l.y > top) {
                lines[i].inter(top);
                ans += lines[i].dis();
                top = lines[i].top();
            }
        }

        printf("%.2f\n", ans);
    }
    return 0;
}
