//ÌâÄ¿Á´½Ó£ºhttps://pintia.cn/problem-sets/994805342720868352/problems/994805514284679168
#include <stdio.h>
#include <algorithm>

using namespace std;

#define N 110000
#define INF 0x3f3f3f3f

int n;
int a[N];

int main() {
    while (scanf("%d", &n) != EOF) {
        int MAX = -1, fi = 0, se = n - 1, sum = 0, tmp = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            sum += a[i];
            if (sum < 0) {
                tmp = i + 1;
                sum = 0;
            } else if(sum > MAX) {
                if (sum > MAX) {
                    MAX = sum, fi = tmp, se = i;
                }
            }
        }
        if (MAX < 0) MAX = 0;
        printf("%d %d %d\n", MAX, a[fi], a[se]);
    }
    return 0;
}
