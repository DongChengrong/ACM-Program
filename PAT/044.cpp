/*
��Ŀ���ӣ�https://pintia.cn/problem-sets/994805342720868352/problems/994805495863296000
��������֪�����ǽ�����Ҫ��������(x��x��d�����µ��෴��)�������Բ��ԾͿ�����
��������д����������һ�������������Բ��ԣ���һ������������෴������
���������������ȶ���x�������Բ��ԣ�����������ֱ�����NoȻ��ʼ��һ������(СС�ļ�֦)
Ȼ�������x��d�����µ��෴��y�����Ŷ�y�����������ԾͿ�����
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
