/*
*ÌâÄ¿Á´½Ó£ºhttps://www.nowcoder.com/pat/6/problem/4047
*/

#include <stdio.h>
#include <string.h>

#define N 15
#define M 11000

int vis[N];
char s[M];

int main() {
    while (scanf("%s", s) != EOF) {
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < strlen(s); ++i) {
            int p = s[i] - '0';
            vis[p]++;
        }
        for (int i = 0; i <= 9; ++i) {
            if (vis[i]) {
                printf("%d:%d\n", i, vis[i]);
            }
        }
    }
    return 0;
}
