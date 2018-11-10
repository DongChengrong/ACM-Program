//ÌâÄ¿Á´½Ó£ºhttps://pintia.cn/problem-sets/994805342720868352/problems/1038429808099098624
#include <stdio.h>
#include <string.h>

#define N 110

typedef struct Node{
    int id;
    char c;
}Node;

Node a[N];

int main() {
    int n, i, j, k;
    scanf("%d", &n); getchar();
    for (i = 1; i <= n; ++i) {
        scanf("%c%d", &a[i].c, &a[i].id); getchar();
    }
    for (i = 1; i <= n; ++i) {
        for (j = i + 1; j <= n; ++j) {
            int l1 = 0, l2 = 0;
            for (k = 1; k <= n; ++k) {
                if (a[k].c == '-') {
                    if (a[k].id != i && a[k].id != j) {
                        if (k == i || k == j) l2++;
                        else l1++;
                    }
                } else {
                    if (a[k].id == i || a[k].id == j) {
                        if (k == i || k == j) l2++;
                        else l1++;
                    }
                }
            }
            //if (j == 4 && i == 1) printf("%d %d\n", l1, l2);
            if (l1 == 1 && l2 == 1) {
                printf("%d %d\n", i, j);
                break;
            }
        }
        if (j <= n) break;
    }
    if (i >= n) puts("No Solution");
    return 0;
}
