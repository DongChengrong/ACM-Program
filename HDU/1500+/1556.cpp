/*
*  HDU 1556
*  差分标记板子题
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 110000

int sum[N];

int main() {
    int n;
    while (scanf("%d", &n) != EOF && n) {
        memset(sum, 0, sizeof sum);
        for (int i = 0; i < n; ++i) {
            int a, b; scanf("%d%d", &a, &b);
            ++sum[a]; --sum[b + 1];
        }
        int res = 0;
        for (int i = 1; i < n; ++i) {
            res += sum[i];
            printf("%d ", res);
        }
        res += sum[n];
        printf("%d\n", res);
    }
    return 0;
}
