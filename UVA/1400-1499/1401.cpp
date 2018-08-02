#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 310000
#define M 30
#define Mod 20071027

int cnt, root;
int ch[N][M], val[N], d[N];
char s[N];

void init() {
    cnt = root = 0;
    memset(d, 0, sizeof(d));
    memset(val, 0, sizeof(val));
    memset(ch, 0, sizeof(ch));
    d[0] = 1;
}

void join(char *s) {
    int u = root;
    for (int i = 0; i < strlen(s); ++i) {
        int v = s[i] - 'a';
        if (!ch[u][v]) {
            ch[u][v] = ++cnt;
        }
        u = ch[u][v];
    }
    val[u] = 1;
}

void dp(int l, int r) {
    int u = root;
    int i = l;
    while (i <= r) {
        if (val[u]) {
            d[i] = (d[i] + d[l] ) % Mod;
        }
        int v = s[i] - 'a';
        u = ch[u][v];
        if (!u) break;
        ++i;
    }
}

int main() {
    int kase = 0;
    while (scanf("%s", s) != EOF) {
        int n;
        init();
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            char tmp[N];
            scanf("%s", tmp);
            join(tmp);
        }
        for (int i = 0; i < strlen(s); ++i) {
            dp(i, strlen(s));
        }
        printf("Case %d: %d\n", ++kase, d[strlen(s)]);
    }
    return 0;
}
