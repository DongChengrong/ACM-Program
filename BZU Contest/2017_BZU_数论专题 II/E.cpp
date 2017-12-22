#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int Mod = 1000;
const int INF = 0x3f3f3f3f;
typedef long long LL;

//求后三位
LL pow_tail(LL a, LL b)
{
    if(b == 0) return 1;
    if(b == 1) return a % Mod;

    LL c = pow_tail(a, b / 2);
    c = c * c % Mod;
    if(b & 1) c = c * a % Mod;
    return c;
}

//求前三位
double pow_head(double a, LL b)
{
    if(b == 0) return 1;
    if(b == 1) return a;

    double c = pow_head(a, b / 2);
    c = c * c;
    while(c >= Mod) c /= 10.0;
    if(b & 1) c = c * a;
    while(c >= Mod) c /= 10.0;
    return c;
}

//主函数
int main()
{
    int T;
    scanf("%d",&T);
    for(int kase = 1; kase <= T; kase++)
    {
        LL n,k;
        scanf("%lld%lld",&n,&k);
        LL b;
        double a;
        a = pow_head((double)n,k);
        b = pow_tail(n,k);
        while(a >= Mod) a /= 10;
        printf("Case %d: %03d %03lld\n",kase,(int)a,b%Mod);
    }
	return 0;
}
