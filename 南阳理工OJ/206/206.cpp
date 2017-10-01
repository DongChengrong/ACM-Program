#include<stdio.h>

int main()
{
    long long L,W;
    while(scanf("%lld%lld",&W,&L) == 2)
    {
        printf("%lld\n",((L+1) * L * (W+1)*W) / 4);
    }
    return 0;
}
