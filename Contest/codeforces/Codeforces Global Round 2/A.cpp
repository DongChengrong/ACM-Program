#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>

using namespace std;

#define N 330000

int pos[N], a[N];

int main() {
    int n, m = 0; scanf("%d", &n);
    map<int, int> ma;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if (!ma[a[i]]) {
            pos[m++] = i;
            ma[a[i] ] = 1;
        }
    }
    int res = 0;
    for (int i = 0; i < m; ++i) {
        int j = n;
        while (a[pos[i]] == a[j]) --j;
        res = max(res, j - pos[i]);
    }
    printf("%d\n",res);
    return 0;
}
