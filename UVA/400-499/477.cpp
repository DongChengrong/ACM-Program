//基本计算几何
#include <stdio.h>
#include <math.h>
#include <string.h>

#define N 15

struct Rectangle {
    double x1, y1, x2, y2;
    int in(double x, double y) {
        return (x1 <= x && x <= x2) && (y2 <= y && y <= y1);
    }
};

struct Circle {
    double x1, y1, r;
    int in(double x, double y) {
        double dis = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
        return dis <= r;
    }
};


struct Node {
    int flag;
    Rectangle a;
    Circle b;
};

int n;
char s[N];
Node figures[N];

int main() {

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    n = 0;
    while (scanf("%s", s) != EOF) {
        if (s[0] == '*') break;
        if (s[0] == 'r') {
            double x1, x2, y1, y2;
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            figures[n].flag = 0;
            figures[n].a = (Rectangle){x1, y1, x2, y2};
        }
        if (s[0] == 'c') {
            double x, y, r;
            scanf("%lf%lf%lf", &x, &y, &r);
            figures[n].flag = 1;
            figures[n].b = (Circle){x, y, r};
        }
        ++n;
    }
    int cnt = 1;
    double x, y;
    while (scanf("%lf%lf", &x, &y) != EOF && !(x == 9999.9 && y == 9999.9)) {
        int flag = 0;
        for (int i = 0; i < n; ++i) {
            if (figures[i].flag) {
                if (figures[i].b.in(x, y)) {
                    printf("Point %d is contained in figure %d\n", cnt, i + 1);
                    flag = 1;
                }
            } else {
                if (figures[i].a.in(x, y)) {
                    printf("Point %d is contained in figure %d\n", cnt, i + 1);
                    flag = 1;
                }
            }

        }
        if (!flag) printf("Point %d is not contained in any figure\n", cnt);
        cnt++;
    }

    return 0;
}



