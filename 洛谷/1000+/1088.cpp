#include <stdio.h>
#include <algorithm>

using namespace std;

#define N 11000

int a[N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d",&a[i]);
    for (int i = 0; i < m; ++i) next_permutation(a, a + n);
    for (int i = 0; i < n; ++i) printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
    return 0;
}
