#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 100000 + 10;

int cmp(int a, int b)
{
    return a > b;
}

int a[maxn];

int main()
{
    int k;
    while(scanf("%d",&k) == 1)
    {
        for(int i = 0; i < 12; i++)
            scanf("%d",&a[i]);
        sort(a,a+12,cmp);
        int i,cnt = 0;
        for(i = 0; i < 12; i++)
        {
            if(cnt >= k) break;
            else cnt += a[i];
        }
        if(i == 12 && cnt < k) printf("-1\n");
        else printf("%d\n",i);
    }
    return 0;
}
