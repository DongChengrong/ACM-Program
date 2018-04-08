#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define N 1010
#define INF 0x3f3f3f3f

typedef long long LL;

LL pow(LL a, LL b){
    if(b == 1) return a % 1000;
    if(b == 0) return 1;
    LL c = pow(a, b / 2) % 1000;
    c = c * c % 1000;
    if(b & 1) c = c * a % 1000;
    return  c % 1000;
}

int main()
{
    LL a,b;
    while(scanf("%lld%lld",&a,&b) == 2 && (a || b)){
        printf("%lld\n",pow(a,b) % 1000);
    }
    return 0;
}
