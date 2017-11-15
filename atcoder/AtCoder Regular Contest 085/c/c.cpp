#include<stdio.h>
#include<math.h>

int main()
{
    long long n,m;
    while(scanf("%lld%lld",&n,&m) == 2)
    {
        printf("%lld\n",(long long)pow(2,m)*((n-m)*100 + m*1900));
    }
    return 0;
}
