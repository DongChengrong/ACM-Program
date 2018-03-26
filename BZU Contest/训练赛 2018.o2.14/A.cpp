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
    int T,n,m;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&m,&n);
        for(int i = 1; i <= m; i++)
            scanf("%d",&a[i]);

        if(n >= m) printf("100\n");
        else
        {
            int ans = 0;
            a[0] = 0; a[m+1] = a[m + 2] = a[m+3] = 101;
            for(int i = 0; i <= m - n + 1; i++)
                ans = max(ans,a[i + n+1] - a[i] - 1);
            printf("%d\n",ans);
        }
    }
    return 0;
}
