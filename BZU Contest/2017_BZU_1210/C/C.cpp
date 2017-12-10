#include<stdio.h>
#include<algorithm>
using namespace std;

typedef long long LL;

int main()
{
    LL i,j;
    while(scanf("%lld%lld",&i,&j) == 2)
    {
        LL Max = 0;
        printf("%lld %lld ",i,j);
        if(i > j) swap(i, j);
        for(LL k = i; k <= j; k++)
        {
            LL count = 1;
            LL x = k;
            while(x != 1)
            {
                if(x & 1) x = 3 * x + 1;
                else x /= 2;
                count++;
            }
            Max = max(Max,count);
        }
        printf("%lld\n",Max);
    }
    return 0;
}
