#include<stdio.h>
#include<stdlib.h>
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
    int n;
    while(cin >> n)
    {
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        cout << abs(a[2] - a[1]) << ' ' << abs(a[1] - a[n])<<endl;;
        for(int i = 2; i < n; i++)
        {
            cout << min(abs(a[i]-a[i+1]),abs(a[i] - a[i-1])) << ' ';
            cout << max(abs(a[i] - a[1]),abs(a[i]- a[n])) << endl;
        }
        cout<< abs(a[n] - a[n - 1]) <<' '<< abs(a[n] - a[1])<<endl;
    }
    return 0;
}
