#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 100000 + 10;

int main()
{
    LL n,k;
    while(cin >> n >> k)
    {
        LL ans;
        LL mid =  n / 2;
        if(n & 1) mid++;
        if(k <= mid) ans = 2 * k - 1;
        else ans = 2 * (k - mid);
        cout << ans << endl;
    }
    return 0;
}
