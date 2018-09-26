//题目链接：https://pintia.cn/problem-sets/994805342720868352/problems/994805415005503488
#include <stdio.h>
#include <vector>

using namespace std;

#define N 110000

typedef long long ll;

int main() {
    ll n;
    while (scanf("%lld", &n) != EOF) {
        if (n == 1) { puts("1=1"); continue; }   //特判n=1的情况
        ll cnt = 0, a = 1;
        ll s = n;   //标记初始值
        vector<ll> fac[N];   //存储素因数
        for (ll i = 2; i * i <= n; i += a, a = 2) {   //素因数分解
            if (n % i == 0) {
                while (n % i == 0) {
                    fac[cnt].push_back(i); n /= i;
                }
                ++cnt;
            }
        }
        if (n != 1) fac[cnt++].push_back(n);
        //打印输出
        printf("%lld=", s);
        for (int i = 0; i < cnt; ++i) {
            if (i) printf("*");
            printf("%lld", fac[i][0]);
            if (fac[i].size() > 1) printf("^%d", fac[i].size());   //size为m就代表幂为m
        }
        puts("");
    }
    return 0;
}
