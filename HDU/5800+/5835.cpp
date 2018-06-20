//#include <stdio.h>
//
//typedef long long ll;
//
//int main() {
//    int T;
//    scanf("%d",&T);
//    for (int kase = 1; kase <= T; ++kase) {
//        int n;
//        ll sum = 0, x;
//        scanf("%d",&n);
//        while (n--) {
//            scanf("%d",&x);
//            sum += x;
//        }
//        printf("Case #%d: %d\n", kase, sum / 2);
//    }
//    return 0;
//}
#include <cstdio>
#include <algorithm>
using namespace std;
int t,n,x,sum,m;
int main() {
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++){
        sum=m=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            sum+=x;
            m=max(m,x);
        }
        printf("Case #%d: %d\n",cas,min(sum/2,(sum-m)*2+1));
    }
}
