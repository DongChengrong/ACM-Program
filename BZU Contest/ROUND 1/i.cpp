#include<stdio.h>

long long gcd(long long a,long long b)
{
    long long c;
    if(b == 1) return a % 10;
    if(b == 0) return 1;
    c = gcd(a, b / 2) % 10;
    c = c * c % 10;
    if(b & 1) c = c * a % 10;
    return c;
}

int main()
{
    int T;
    long long n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld",&n);
        long long result = gcd(n % 10,n);
        printf("%lld\n",result);
    }
    return 0;
}
