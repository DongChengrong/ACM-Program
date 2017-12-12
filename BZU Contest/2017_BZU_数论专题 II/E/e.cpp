#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int Mod = 1000;
const int M = 100000000;
const int INF = 0x3f3f3f3f;
typedef long long LL;

//�����λ
LL pow_tail(LL a, LL b)
{
    if(b == 0) return 1;
    if(b == 1) return a % Mod;

    LL c = pow_tail(a, b / 2);
    c = c * c % Mod;
    if(b & 1) c = c * a % Mod;
    return c;
}

//��ǰ��λ
LL pow_head(LL a, LL b)
{
    if(b == 0) return 1;
    if(b == 1) return a;

    LL c = pow_tail(a, b / 2);
    c = c * c;
    while(c >= M) c /= 10;
    if(b & 1) c = c * a;
    while(c >= M) c /= 10;
    return c;
}

//������
int main()
{
    int T;
    scanf("%d",&T);
    for(int kase = 1; kase <= T; kase++)
    {
        LL n,k;
        scanf("%lld%lld",&n,&k);
        LL a,b;
        a = pow_head(n,k);
        b = pow_tail(n,k);
        while(a >= 1000) a /= 10;
        printf("Case %d: %lld %lld\n",kase,a,b);
    }
	return 0;
}
