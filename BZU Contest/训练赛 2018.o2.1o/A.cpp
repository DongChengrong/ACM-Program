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
    LL a,b,c;
    while(cin >> a >> b >> c)
    {
        LL ans = a + b * c;
        ans = max(ans, a *  (b + c));
        ans = max(ans, a * b * c);
        ans = max(ans, (a + b) * c);
        cout << ans<<endl;
    }
    return 0;
}
