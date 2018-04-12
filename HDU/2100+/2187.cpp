#include <stdio.h>
#include <algorithm>
using namespace std;

#define N 1100

struct Node {
    double p, w;
};

Node a[N];

int cmp(Node a, Node b) {
    return a.p < b.p;
}

int main (){
    double n;
    int m, T;
    scanf("%d",&T);
    while (T--) {
        scanf("%lf%d",&n,&m);

        for (int i = 0; i < m; ++i) {
            scanf("%lf%lf",&a[i].p, &a[i].w);
        }

        sort(a, a + m, cmp);

        double w,ans = 0;
        int i =  0;
        while (n > 0 && i < m) {
            w = n / a[i].p;
            w = w > a[i].w ? a[i].w : w;
            n -= w * a[i].p;
            ans += w;
            ++i;
        }

        printf("%.2f\n",ans);
    }
    return 0;
}
