#include <stdio.h>
#include <string.h>

int main() {
    int T, n;
    scanf("%d", &T);
    while (T--) {
        int n, m, time = 0;
        scanf("%d%d", &n, &m); m = m * 60;
        while (n--) {
            int x1, x2, y1, y2;
            scanf("%d:%d %d:%d", &x1, &y1, &x2, &y2);
            time = time + (x2 * 60 + y2) - (x1 * 60 + y1);
        }
        if (time >= m) puts("YES");
        else puts("NO");
    }
    return 0;
}
