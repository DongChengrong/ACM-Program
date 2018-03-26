#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 100000 + 10;

int main()
{
    LL n,m;
    while(cin >> n >> m)
    {
        LL ans = 0;
        for(int i = 1; i <= n; i++)
        {
            ans++;
            if(i % m == 0) n++;
        }
        cout << ans << endl;
    }
    return 0;
}
