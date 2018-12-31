#include <stdio.h>

#define N 5500

int a[N];

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i) {
        if (a[a[a[i]]] == i) { puts("YES"); return 0; }
    }
    puts("NO");
    return 0;
}
