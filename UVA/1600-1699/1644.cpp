#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

#define N 1300000
#define M 110000
#define _for(i, a, b) for (int i = (a); i < (b); ++i)

int n;
int vis[N];
int primes[M];

void sieve() {
    n = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 2; i <= sqrt(N); ++i) {
        if (!vis[i]) {
            primes[n++] = i;
            for (int j = i + i; j < N; j += i) {
                vis[j] = 1;
            }
        }
    }
    for (int i = sqrt(N) + 1; i < N; ++i) {
        if (!vis[i]) primes[n++] = i;
    }
}

int main() {
    sieve();
    int x;
    while (scanf("%d",&x) == 1 && x > 0) {
        int p = lower_bound(primes, primes + n, x) - primes;
        if (primes[p] == x) puts("0");
        else printf("%d\n", primes[p] - primes[p - 1]);
    }
    return 0;
}
