#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 100000 + 10;

int a[maxn];

int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m) == 2)
    {
        for(int i = 0; i < m; i++)
            scanf("%d",&a[i]);
        sort(a,a+m);
        int mi = a[n - 1] - a[0];
        for(int i = 1; i <= m - n;i++)
            mi = min(mi,a[i + n - 1] - a[i]);
        printf("%d\n",mi);
    }
    return 0;
}
