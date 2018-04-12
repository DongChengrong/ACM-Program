/*
典型的区间调度问题
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

#define N 110

struct Node {
    int s, t;
};

Node a[N];

bool cmp(Node a, Node b) {
    return a.t < b.t;
}

int main() {
    int n;
    while (scanf("%d",&n) == 1) {

        for (int i = 0; i < n; ++i) {
            int h1,h2,m2,m1;
            scanf("%d:%d-%d:%d",&h1,&m1,&h2,&m2);
            int x = h1 * 60 + m1;
            int y = h2 * 60 + m2;
            a[i].s = min(x,y);
            a[i].t = max(x,y);
            //printf("%d %d\n",a[i].s,a[i].t);
        }

        sort(a,a+n, cmp);

        int ans = 1;
        int t = a[0].t;

        for (int i = 1; i < n; ++i) {
            if (t < a[i].s) {
                ++ans; t = a[i].t;
            }
        }

        printf("%d\n",ans);

    }
    return 0;
}
