//��Ŀ���ӣ�https://pintia.cn/problem-sets/994805342720868352/problems/994805415005503488
#include <stdio.h>
#include <vector>

using namespace std;

#define N 110000

typedef long long ll;

int main() {
    ll n;
    while (scanf("%lld", &n) != EOF) {
        if (n == 1) { puts("1=1"); continue; }   //����n=1�����
        ll cnt = 0, a = 1;
        ll s = n;   //��ǳ�ʼֵ
        vector<ll> fac[N];   //�洢������
        for (ll i = 2; i * i <= n; i += a, a = 2) {   //�������ֽ�
            if (n % i == 0) {
                while (n % i == 0) {
                    fac[cnt].push_back(i); n /= i;
                }
                ++cnt;
            }
        }
        if (n != 1) fac[cnt++].push_back(n);
        //��ӡ���
        printf("%lld=", s);
        for (int i = 0; i < cnt; ++i) {
            if (i) printf("*");
            printf("%lld", fac[i][0]);
            if (fac[i].size() > 1) printf("^%d", fac[i].size());   //sizeΪm�ʹ�����Ϊm
        }
        puts("");
    }
    return 0;
}
