#include<stdio.h>

long long f(long long n)
{
    if(n == 1) return 1;
    return f(n/2) + 1;
}

int main()
{
    long long n;
    while(scanf("%lld",&n) == 1)
    {
        printf("%lld\n",f(n));
    }
    return 0;
}
