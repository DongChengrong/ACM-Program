#include <stdio.h>
#include <string.h>
#include <set>
#include <list>
#include <algorithm>

using namespace std;

#define N 110000

struct Node {
    int a, b, c, d, len;
    //int a2, b2, c2, d2, len2;
    Node () {
        a = b = c = d = len = 0;
        //a2 = b2 = c2 = d2 = len2 = 0;
    }

    bool operator == (const Node &u) const {
        return (a == u.a) && (b == u.b) && (c == u.c) && (d == u.d) && (len == u.len);
        //return (a2 == u.a2) && (b2 == u.b2) && (c2 == u.c2) && (d2 == u.d2) && (len2 == u.len2);
    }

    bool operator < (const Node &u) const {
        if (a != u.a) return a < u.a;
        if (b != u.b) return b < u.b;
        if (c != u.c) return c < u.c;
        if (d != u.d) return d < u.d;
        return len < u.len;
    }

    void change() {
        int x = d;
        int len2 = 0;
        if (d) {
            x = d;
            len2 = 32;
        } else if (c) {
            x = c, len2 = 24;
        } else if (b) {
            x = b; len2 = 16;
        } else if(a) {
            x = 8;
        }
        if (len2) {
            while (x) {
                if (x & 1) break;
                else len--;
            }
        }
        len = min(len, len2);
    }

    void print() {
        printf("%d.%d.%d.%d/%d\n", a, b, c, d, len);
        //printf("%d.%d.%d.%d/%d\n", a2, b2, c2, d2, len2);
    }

};

Node a[N];

int main() {
    int n, m = 0;
    scanf("%d", &n); getchar();
    while (m < n) {
        int cnt = 0;
        char c;
        a[m] = Node();
        while ((c = getchar()) && c != '\n') {
            if (c == '.') { cnt++; continue; }
            if (c == '/') { cnt = -1; continue; }
            if (cnt == -1) a[m].len = a[m].len * 10 + (c - '0');
            if (cnt == 0) a[m].a = a[m].a * 10 + (c - '0');
            if (cnt == 1) a[m].b = a[m].b * 10 + (c - '0');
            if (cnt == 2) a[m].c = a[m].c * 10 + (c - '0');
            if (cnt == 3) a[m].d = a[m].d * 10 + (c - '0');
        }
        if (a[m].len == 0) a[m].len = (cnt + 1) * 8;
        ++m;
    }
    set<Node> s;
    for (int i = 0; i < n; ++i) {
        s.insert(a[i]);
    }
    for (Node x : s) x.print();
    return 0;
}
