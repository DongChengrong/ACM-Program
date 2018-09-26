#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        int sum = 0, MAX = -1;
        for (int i = 0; i < n; ++i) {
            int tmp; scanf("%d", &tmp);
            sum += tmp; MAX = max(MAX, tmp);
        }
        int k = MAX * n - sum;
        if (k >= m) printf("%d ", MAX);
        else {
            k = m - k;
            int res = MAX + k / n;
            if (k % n != 0) res += 1;
            printf("%d ", res);
        }
        printf("%d\n", MAX + m);
    }
    return 0;
}
