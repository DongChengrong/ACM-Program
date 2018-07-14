//ÌâÄ¿Á´½Ó£ºhttps://www.nowcoder.com/pat/6/problem/4054

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 110000

struct Node {
    char s[110];
    int y, m, d;
    Node () {}
    Node (char ss[], int yy, int mm, int dd) {
        y = yy; m = mm;
        d = dd; strcpy(s, ss);
    }

    bool operator < (Node u) {
        if (y != u.y) return y < u.y;
        if (m != u.m) return m < u.m;
        return d < u.d;
    }

}a[N];

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        int cnt = 0, y, m, d;
        for (int i = 0; i < n; ++i) {
            char tmp[110];
            scanf("%s", tmp);
            scanf("%d/%d/%d", &y, &m, &d);
            if (y < 1814 || (y == 1814 && m < 9) || (y == 1814 && m == 9 && d < 6)) continue;
            if (y > 2014 || (y == 2014 && m > 9) || (y == 2014 && m == 9 && d > 6)) continue;
            a[cnt++] = Node(tmp, y, m, d);
        }
        sort(a, a + cnt);
        printf("%d %s %s",cnt, a[0].s, a[cnt - 1].s);
    }
    return 0;
}
