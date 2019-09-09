/*
*题目链接：https://pintia.cn/problem-sets/994805342720868352/problems/994805429018673152
*分析：这个题需要考虑时间问题，采用纯c编写
*读入慎用scanf，建议使用getchar
***/
#include <stdio.h>
#include <string.h>

#define N 11000

int vis[300];
char s1[N];

int main() {
    int n = 0;
    memset(vis, 0, sizeof(vis));
    while (1) {
        s1[n++] = getchar();
        if (s1[n - 1] == '\n') break;
    }
    s1[n] = '\0';
    while (1) {
        char c = getchar();
        if (c == '\n') break;
        vis[c] = 1;
    }
    int i = 0;
    while (s1[i] != '\0') {
        if (!vis[s1[i]]) putchar(s1[i]);
        ++i;
    }
    return 0;
}
