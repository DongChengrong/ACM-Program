#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;

typedef long long LL;
const int maxn = 16000;
int a[maxn + 10];

int is_prime(LL n)
{
    if(n <= 2) return 0;
    LL m = floor(sqrt(n) + 0.5);
    for(LL i = 2; i <= m; i++)
        if(n % i == 0) return 0;
    return 1;
}

void init()
{
    for(int i = 1; i <= maxn; i++)
        a[i] = is_prime(i);
}

int main()
{
    int T = 1;
    int x;
    init();
    while(cin >> x && x > 0)
    {
        printf("%d: %s\n",T++,a[x] ? "yes" : "no");
    }
    return 0;
}
