#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 11000
#define INF 0x3f3f3f3f
#define _for(i, a, b) for (int i = (a); i < (b); ++i)

typedef long long ll;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int sum = 0, MAX = -INF;
        for (int i = 0; i < n; ++i) {
            int x; scanf("%d", &x);
            MAX = max(MAX, x);
            sum += x;
        }
        sum -= MAX;
        if (MAX < sum) puts("Yes");
        else puts("No");
    }
    return 0;
}
