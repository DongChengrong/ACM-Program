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
    LL n;
    while(cin >> n){
        LL ans = (n + 1) / 2;
        if(n & 1) cout << -1 * ans << endl;
        else cout << ans << endl;
    }
    return 0;
}
