#include<stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long m;
        scanf("%lld",&m);
        printf("%lld\n",471 + 1000 * (m - 1));
    }
    return 0;
}
