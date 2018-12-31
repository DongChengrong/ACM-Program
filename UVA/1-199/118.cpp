#include <stdio.h>
#include <string.h>

#define N 110

const char *dir = "NESW";

int R, C, x, y;
int vis[55][55];
char s[N], tmp[5];

int main() {

    scanf("%d %d", &R, &C);
    memset(vis, 0, sizeof(vis));
    while (scanf("%d %d %s", &x, &y, tmp) != EOF) {
        char c = tmp[0];
        scanf("%s", s);
        int ok = 1;
        int len = strlen(s);
        for (int i = 0; i < len; ++i) {
            if (s[i] == 'F') {
                if (c == 'N') {
                    if (y + 1 > C) {
                        if (!vis[x][y]) { vis[x][y] = 1; ok = 0; break; }
                    } else ++y;
                } else if (c == 'E') {
                    if (x + 1 > R) {
                        if (!vis[x][y]) { vis[x][y] = 1; ok = 0; break; }
                    } else ++x;
                } else if (c == 'S') {
                    if (y - 1 < 0) {
                        if (!vis[x][y]) { vis[x][y] = 1; ok = 0; break; }
                    } else --y;
                } else if (c == 'W') {
                    if (x - 1 < 0) {
                        if (!vis[x][y]) { vis[x][y] = 1; ok = 0; break; }
                    } else --x;
                }
            } else if (s[i] == 'L') {
                c = dir[((strchr(dir, c) - dir) - 1 +  4) % 4];
            } else if (s[i] == 'R') {
                c = dir[(strchr(dir, c) - dir + 1) % 4];
            }
        }
        printf("%d %d %c", x, y, c);
        if (ok) puts("");
        else puts(" LOST");
    }
    return 0;
}
