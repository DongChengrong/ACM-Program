#include <stdio.h>
#include <algorithm>
using namespace std;

struct Vecter {
    double x, y;

    Vecter() {}
    Vecter(double a, double b) {
        x = a; y = b;
    }

    double operator * (const Vecter &a) const {
        return (x * a.y) - (y * a.x);
    }

    Vecter operator - (const Vecter a) const {
        return Vecter(this->x - a.x, this->y - a.y);
    }
};

double direction(Vecter a, Vecter b, Vecter c) {
    return (a - c) * (b - c);
}

bool on_segment(Vecter a, Vecter b, Vecter c) {
    return (a.x >= min(b.x, c.x) && a.x <= max(b.x, c.x)) &&
        (a.y >= min(b.y, c.y) && a.y <= max(b.y, c.y));
}

bool segments_intersect(Vecter a, Vecter b, Vecter c, Vecter d) {
    double d1 = direction(a, c, d);
    double d2 = direction(b, c, d);
    double d3 = direction(c, a, b);
    double d4 = direction(d, a, b);
    //printf("%.2f %.2f %.2f %.2f\n", d1, d2, d3, d4);
    if (d1 * d2 < 0 && d3 * d4 < 0) return true;
    //puts("1");
    if (d1 == 0) {
        if (on_segment(a, d, c)) return true;
    } if (d2 == 0) {
        if (on_segment(b, d, c)) return true;
    } if (d3 == 0) {
        if (on_segment(c, b, a)) return true;
    } if (d4 == 0) {
        if (on_segment(d, b, a)) return true;
    }
    return false;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    int T;
    scanf("%d", &T);
    while (T--) {
        Vecter l, r;
        Vecter a, b, c, d;
        double x1, x2, y1, y2;
        scanf("%lf%lf%lf%lf", &l.x, &l.y, &r.x, &r.y);
        scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
        a = Vecter(min(x1, x2), max(y1, y2));
        b = Vecter(max(x1, x2), max(y1, y2));
        c = Vecter(max(x1, x2), min(y1, y2));
        d = Vecter(min(x1, x2), min(y1, y2));
        if (on_segment(l, a, c) || on_segment(r, a, c)) { puts("T"); continue; }
        else if (segments_intersect(l, r, a, b) || segments_intersect(l, r, c, b)
            || segments_intersect(l, r, d, c) || segments_intersect(l, r, d, a))
                { puts("T"); continue; }
        else puts("F");
    }
    return 0;
}
