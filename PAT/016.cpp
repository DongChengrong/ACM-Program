//ÌâÄ¿Á´½Ó£ºhttps://www.nowcoder.com/pat/6/problem/4055

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 1100

int vis[N];
char s1[N], s2[N];

int main() {
    while (scanf("%s", s1) != EOF) {
        int i = 0, j = 0;
        memset(vis, 0, sizeof(vis));
        scanf("%s", s2);
        while (i < strlen(s1)) {
            if (s1[i] == s2[j]) {
                ++i; ++j; continue;
            } else {
                int p;
                if (isalpha(s1[i])) {
                    p = toupper(s1[i]) - 'A' + 10;
                    if (!vis[p]) printf("%c", toupper(s1[i]));
                    vis[p] = 1;
                } else {
                    p = s1[i] - '0';
                    if (!vis[p]) printf("%c", s1[i]);
                    vis[p] = 1;
                }
                ++i;
            }
        }
    }
    return 0;
}
