#include <stdio.h>
#include <string.h>
#include <math.h>

#define N 11000

int m;
int primes[N], vis[N];

void sieve() {
    m = 0;
    memset(vis, 0, sizeof(vis));
    vis[1] = 1;
    for (int i = 2; i < sqrt(N); ++i) {
        if (!vis[i]) {
            for (int j = i + i; j < N; j += i) {
                vis[j] = 1;
            }
        }
    }
    for (int i = 2; i < N; ++i) {
        if (!vis[i]) primes[m++] = i;
    }
}

int main() {
    int n;
    sieve();
    while (scanf("%d", &n) != EOF && n) {
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            if (primes[i] > n) break;
            int tmp = 0, j = i;
            while (tmp < n && j < m) tmp += primes[j++];
            if (tmp == n) cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
