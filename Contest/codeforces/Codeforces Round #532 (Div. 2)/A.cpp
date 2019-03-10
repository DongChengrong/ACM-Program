#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define N 110

int n, k, v1, v2;
int a[N];

int get(int b) {
    int v3 = v1, v4 = v2, c;
    int s = -200;
    while (s * k + b < 1) s++;
    while ((c = s * k + b) <= n) {
        if (a[c] == 1) v3--;
        else v4--;
        s++;
    }
    return abs(v3 - v4);
}

int main() {
    while (scanf("%d%d", &n, &k) != EOF) {
        int ans = -1000;
        v1 = v2 = 0;
        for (int i = 1; i <= n; ++i) { scanf("%d", &a[i]); if (a[i] == 1) v1++; else v2++; }
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, get(i));
        }
        printf("%d\n", ans);
    }
    return 0;
}
