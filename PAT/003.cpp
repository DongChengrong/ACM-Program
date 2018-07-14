/*
*ÌâÄ¿Á´½Ó£»https://www.nowcoder.com/pat/6/problem/4078
*/

#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int a1, a2, a3, a4, a5, x;
        int flag = 0, num = 0;
        a1 = a2 = a3 = a4 = a5 = 0;
        while (n--) {
            scanf("%d", &x);
            if (x % 5 == 0 && x % 2 == 0) a1 += x;
            if (x % 5 == 1) {
                if (!flag) a2 += x;
                else a2 -= x;
                flag = !flag;
            }
            if (x % 5 == 2) ++a3;
            if (x % 5 == 3) {
                ++num; a4 += x;
            }
            if (x % 5 == 4) {
                a5 = max(a5, x);
            }
        }

        if (a1 == 0) printf("N");
        else printf("%d", a1);

        if (a2 == 0) printf(" N");
        else printf(" %d", a2);

        if (a3 == 0) printf(" N");
        else printf(" %d", a3);

        if (a4 == 0) printf(" N");
        else printf(" %.1f", (double)a4 / (double)num);

        if (a5 == 0) printf(" N\n");
        else printf(" %d\n", a5);

    }
    return 0;
}
