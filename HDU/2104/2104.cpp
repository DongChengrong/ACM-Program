#include<stdio.h>
#include<iostream>
using namespace std;

typedef long long LL;

LL gcd(LL a, LL b)
{
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int main()
{
    LL n,m;
    while(cin >> n >> m && n != -1)
    {
        if(gcd(n,m) != 1) printf("POOR Haha\n");
        else printf("YES\n");
    }
    return 0;
}
