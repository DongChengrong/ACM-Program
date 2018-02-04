#include<stdio.h>
#include<iostream>
using namespace std;

typedef unsigned long long LL;

int main()
{
    LL n,m,a;
    while(cin >> n >> m >> a)
    {
        LL ans = ((n + a - 1) / a) * ((m + a - 1) / a);
        cout << ans << endl;
    }
    return 0;
}
