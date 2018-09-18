#include <stdio.h>
#include <string.h>

#define N 1100

typedef struct Node {
    int e;
    double p;
} Node;

Node a[N], b[N], c[N];

int main() {
    int k1, k2, i, j, k3;
    scanf("%d", &k1);
    for (i = 0; i < k1; ++i) scanf("%d %lf", &a[i].e, &a[i].p);
    scanf("%d", &k2);
    for (i = 0; i < k2; ++i) scanf("%d %lf", &b[i].e, &b[i].p);
    i = 0, j = 0, k3 = 0;
    while (i < k1 || j < k2) {
        if (i < k1 && j < k2 && a[i].e == b[j].e) {
            c[k3++] = (Node) {a[i].e, a[i].p + b[j].p };
            i++; j++;
        } else if (j >= k2 || a[i].e > b[i].e) {
            c[k3++] = a[i++];
        } else if(i >= k1 || a[i].e < b[j].e) c[k3++] = b[j++];
    }
    printf("%d", k3);
    for (i = 0; i < k3; ++i) printf(" %d %.1f", c[i].e, c[i].p);
    puts("");
    return 0;
}
