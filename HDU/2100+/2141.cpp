/*
实在没有想到刚才竟然WA了，究其原因是没有考虑到排序问题
使用二分查找的一个重要条件是查找的数组是已排好序的
所以在使用二分查找之前一定要保证数组是排好序的，而上一份代码没有排序所以会WA
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

#define N 510
#define cin(x) scanf("%lld",&x)

typedef long long LL;

int l,n,m,k;
LL a[N], b[N], c[N], d[N * N];

void read(LL a[], int n) {
    for(int i = 0; i < n; i++) {
        cin(a[i]);
    }
}

bool check(LL x) {
    for(int i = 0; i < m; i++) {
        LL y = x - c[i];
        int p = lower_bound(d, d + k, y) - d;
        if(p < k && d[p] == y) return true;
    }
    return false;
}

int main() {
    int T = 1;
    while(scanf("%d%d%d",&l,&n,&m) == 3) {

        LL x,s;
        k = 0;

        printf("Case %d:\n",T++);

        read(a,l); read(b, n); read(c, m);

        for(int i = 0; i < l; i++)
            for(int j = 0; j < n; j++) {
                d[k++] = a[i] + b[j];
            }

        sort(d, d + k); //千万记得要排序

        cin(s);
        while(s--) {
            cin(x);
            if(check(x)) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
