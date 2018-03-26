#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<iostream>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 1000000 + 10;

LL a[maxn];

void init()
{
    memset(a,0,sizeof(a));
    a[0] = a[1] = 1;
    for(int i = 2; i <= 1000; i++)
    {
        for(int j = i + i; j <= maxn; j += i)
            a[j] = 1;
    }
}

int main()
{
    LL n;
    ios::sync_with_stdio(false);
    while(cin >> n)
    {
        for(LL i = 1; i <= n; i++)
        {
            LL x,num = 0;
            cin >> x;
            LL m = (LL)sqrt(x+0.5);
            if(m * m == x && !a[m]) cout <<"YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}
