#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 1100

int a[N], b[N];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int i, a = 0, b = 0;
        for (i = 0; i < n; ++i) {
            int tmp; scanf("%d", &tmp);
            a += tmp;
        }
        for (i = 0; i < n; ++i) {
            int tmp; scanf("%d", &tmp);
            b += tmp;
        }
        if (a < b) puts("No");
        else puts("Yes");
    }
    return 0;
}
