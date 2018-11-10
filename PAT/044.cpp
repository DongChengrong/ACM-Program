/*
题目链接：https://pintia.cn/problem-sets/994805342720868352/problems/994805495863296000
分析：易知，我们仅仅需要对两个数(x和x在d进制下的相反数)进行素性测试就可以了
所以我们写两个函数，一个用来进行素性测试，另一个用来完成求相反数操作
在主函数中我们先对数x进行素性测试，若不是素数直接输出No然后开始下一组样例(小小的剪枝)
然后再求出x在d进制下的相反数y，接着对y进行素数测试就可以了
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

typedef long long ll;

int is_prime(ll x) {
    ll m = sqrt(x);
    if (x == 1) return 0;
    for (ll i = 2; i <= m; ++i) {
        if (x % i == 0) return 0;
    }
    return 1;
}

ll reverse(ll a, ll n) {
    ll res = 0;
    while (a) {
        res = res * n + (a % n);
        a /= n;
    }
    return res;
}

int main() {
    ll a, n;
    while (scanf("%lld%lld", &a, &n) == 2 & a > 0) {
        int ok = is_prime(a);
        if (!ok) {
            puts("No"); continue;
        }
        a = reverse(a, n);
        ok = is_prime(a);
        if (ok) puts("Yes");
        else puts("No");
    }
    return 0;
}
