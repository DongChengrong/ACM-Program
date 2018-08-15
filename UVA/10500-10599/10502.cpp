#include <stdio.h>
#include <string.h>

#define N 110

typedef long long ll;

int n, m;
char s[N];
int G[N][N];

ll Find(int i, int j) {
    ll sum = 0;
    int r = m;
    int x = i;
    while (G[x][j]) {
        int y;
        for(y = j; y <= r; ++y) {
            if (G[x][y]) sum++;
            else break;
        }
        if (y <= r) r = y - 1;
        x++;
        if (x > n) break;
    }
    return sum;
}

int main() {

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    while (scanf("%d", &n) != EOF && n) {
        scanf("%d", &m);
        for (int i = 1; i <= n; ++i) {
            scanf("%s", s);
            for (int j = 1; j <= m; ++j) {
                G[i][j] = s[j - 1] - '0';
            }
        }
        ll sum = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (G[i][j]) {
                    sum += Find(i, j);
                }
            }
        }

        printf("%lld\n", sum);
    }
    return 0;
}
