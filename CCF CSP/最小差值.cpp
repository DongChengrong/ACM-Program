//ÌâÄ¿Á´½Ó£ºhttp://118.190.20.162/view.page?gpid=T68
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define N 1100
#define INF 0x3f3f3f3f

int a[N];

int main() {
    int n, res = INF;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; ++i) for (int j = i + 1; j < n; ++j) res = min(res, abs(a[i] - a[j]));
    printf("%d\n", res);
    return 0;
}
