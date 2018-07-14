//ÌâÄ¿Á´½Ó£ºhttps://www.nowcoder.com/pat/6/problem/4079
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 1100000

int cnt;
int primes[N], vis[N];

void init() {
    cnt = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 2; i <= sqrt(N); ++i) {
        if (!vis[i]) {
            for (int j = i + i; j < N; j += i) {
                vis[j] = 1;
            }
        }
    }
    for (int i = 2; i < N; ++i) {
        if (!vis[i]) primes[cnt++] = i;
    }
}

int main() {
    init();
    int m, n;
    while (scanf("%d%d", &m, &n) == 2) {
        for (int i = m - 1; i < n; ++i) {
            printf("%d", primes[i]);
            if (i == n - 1 || (i - m + 2) % 10 == 0) printf("\n");
            else printf(" ");
        }
    }
    return 0;
}
