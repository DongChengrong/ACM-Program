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
    LL n,c;
    while(cin >> n >> c)
    {
        for(int i = 0; i < n; i++)
            cin >> a[i];
        sort(a,a+n);
        LL MAX = 1,num = 1;
        for(LL i = 1; i < n; i++)
        {
            if(a[i] - a[i - 1] <= c) num++;
            else{
                num = 1;
            }
        }
        cout << num << endl;
    }
    return 0;
}
