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
    int n;
    while(scanf("%d",&n) == 1)
    {
        for(int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d",&x);
            a[x] = i;
        }
        for(int i = 1; i < n; i++)
            printf("%d ",a[i]);
        printf("%d\n",a[n]);
    }
    return 0;
}
