/*
* UVA 108
*最大子矩阵和
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 1100
#define INF 0x3f3f3f3f

int n;
int a[N][N], C[N][N];

int main() {
    while (scanf("%d", &n) != EOF) {
        memset(C, 0, sizeof(C));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                scanf("%d", &a[i][j]);
                C[i][j] = C[i][j - 1] + C[i - 1][j] - C[i - 1][j - 1] + a[i][j];
            }
        }
        int MAX = -INF;
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                int sum = -INF;
                for (int k = 1; k <= n; ++k) {
                    int tmp = (C[j][k] - C[i - 1][k]) - (C[j][k - 1] - C[i - 1][k - 1]);
                    if (sum < 0) {
                        MAX = max(sum, MAX);
                        sum = tmp;
                    } else sum += tmp;
                    MAX = max(MAX, sum);
                }
            }
        }
        printf("%d\n", MAX);
    }
    return 0;
}
/*
4
0 -2 -7 0
9 2 -6 2
-4 1 -4 1
-1 8 0 -2
*/
