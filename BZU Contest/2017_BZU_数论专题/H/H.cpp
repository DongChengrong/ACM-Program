#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;

typedef long long LL;

int is_prime(LL n)
{
    if(n <= 1) return 0;
    LL m = floor(sqrt(n) + 0.5);
    for(LL i = 2; i <= m; i++)
        if(n % i == 0) return 0;
    return 1;
}

int main()
{
    LL x,y;
    while(cin >> x >> y && x || y)
    {
        int ok = 1;
        for(LL i = x; i <= y; i++)
        {
            LL n= i * i + i + 41;
            if(!is_prime(n))
            {
                ok = 0;
                break;
            }
        }
        if(ok) printf("OK\n");
        else printf("Sorry\n");
    }
    return 0;
}
