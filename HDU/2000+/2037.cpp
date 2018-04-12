/*
典型的区间调度问题
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define N 110

struct Node {
    int s, t;
};

Node a[N];

int cmp (Node a, Node b) {
    return a.t < b.t;
}

int main () {
    int n;
    while (scanf("%d",&n) == 1 && n) {
        for (int i = 0; i < n; ++i) {
            scanf("%d%d",&a[i].s, &a[i].t);
        }

        sort(a, a + n, cmp);

        int ans = 0;
        int t = 0;
        for (int i = 0; i < n; ++i) {
            if (t <= a[i].s) {
                ans++;
                t = a[i].t;
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}
