#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 1100
#define _for(i, a, b) for (int i = (a); i < (b); ++i)

typedef long long ll;

int _rank[N], old[N], ex[N];

int main() {
    int n, kase = 0;
    while (scanf("%d", &n) && n) {
        for (int i = 1; i <= n; ++i) { int tmp; scanf("%d", &tmp); _rank[tmp] = i; }
        for (int i = 1; i <= n; ++i) { int tmp; scanf("%d", &tmp); old[tmp] = i; }
        for (int i = 1; i <= n; ++i) { scanf("%d", &ex[i]); }
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            if (_rank[i] <= ex[i]) sum += 3;
            else if (_rank[i] <= old[i]) sum += 2;
            else sum += 1;
        }
        printf("Case %d: %d\n", ++kase, sum);
    }
    return 0;
}
