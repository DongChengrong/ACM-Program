#include <bits/stdc++.h>
using namespace std;

struct Line
{
    double x1, y1;
    double x2, y2;
};

struct Rectangle {
    double x1, y1;
    double x2, y2;
};

Line l;
Rectangle rec;

void read() {
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &l.x1, &l.y1, &l.x2, &l.y2, &rec.x1, &rec.y1, &rec.x2, &rec.y2);
    if (l.x1 > l.x2) {
        swap(l.x1, l.x2);
        swap(l.y1, l.y2);
    }
    if (rec.x1 > rec.x2) {
        swap(rec.x1, rec.x2);
        swap(rec.y1, rec.y2);
    }
}

bool above() {
    if (min(l.y2,l.y1) > rec.y1)
        return true;
    return false;
}

bool below() {
    if (max(l.y1,l.y2) < rec.y2)
        return true;
    return false;
}

bool left() {
    if (max(l.x2, l.x1) < rec.x1)
        return true;
    return false;
}

bool right() {
    if (min(l.x1, l.x2) > rec.x2)
        return true;
    return false;
}

bool inRec() {
    if (l.x1 > rec.x1 && l.x2 < rec.x2 && max(l.y1, l.y2) < rec.y1 && min(l.y1, l.y2) > rec.y2)
        return true;
    return false;
}

bool intersecte() {
    double k, b, y;
    k = (l.y1 - l.y2) / (l.x1 - l.x2);
    b = l.y1 - k * l.x1;
    if (max(l.y1, l.y2) >= rec.y1 && min(l.y1, l.y2) <= rec.y1) {
        double x = (rec.y1 - b) / k;
        if (x <= rec.x2 && x >= rec.x1)
            return true;
    }
    if (max(l.y1, l.y2) >= rec.y2 && min(l.y1, l.y2) <= rec.y2) {
        double x = (rec.y2 - b) / k;
        if (x >= rec.x1 && x <= rec.x2)
            return true;
    }
    return false;
}

bool judge() {
    if (inRec()) return true;
    if (above()) return true;
    if (below()) return true;
    if (left()) return true;
    if (right()) return true;
}

int main() {
    int T;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d",&T);
    while (T--) {
        read();
        if (judge()) puts("F");
        else if (l.y1 == l.y2) {
            if (l.y1 >= rec.y2) puts("T");
            else puts("F");
        } else if (l.x1 == l.x2) {
            if (max(l.y1, l.y2) >= rec.y1 && min(l.y1, l.y2) <= rec.y1) puts("T");
            else if (max(l.y1, l.y2) >= rec.y2 && min(l.y1, l.y2) <= rec.y2) puts("T");
            else puts("F");
        }
        else {
            if (intersecte()) puts("T");
            else puts("F");
        }
    }
    return 0;
}
