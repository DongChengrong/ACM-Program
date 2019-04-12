#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 550

int n, m;
int cha[N][N];
int ma1[N][N], ma2[N][N];

int _equal() {
    int ok = 1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (ma1[i][j] != ma2[i][j]) { ok = 0; break; }
    return ok;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &ma1[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &ma2[i][j]);
        }
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (ma1[i][j] != ma2[i][j])
                ma1[i][j] ^= 1, ma1[i][0] ^= 1, ma1[0][j] ^= 1, ma1[0][0] ^= 1;
    if (_equal()) puts("Yes"); else puts("No");
    return 0;
}
