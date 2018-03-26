#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 100000 + 10;

LL a[maxn];

int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    while(cin >> n)
    {
        LL pre = 0;
        for(int i = 1; i <= n; i++)
        {
            LL x;
            cin >> x;
            a[i] = pre + x;
            pre = a[i];
        }
        cin >> m;
        while(m--)
        {
            LL x;
            cin >> x;
            int pos = lower_bound(a,a+n,x) - a;
            cout << pos << endl;
        }
    }
    return 0;
}
