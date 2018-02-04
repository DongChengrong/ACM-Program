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
        int num = 0, mon = 0, total = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
            total += a[i];
        }

        sort(a,a+n);

        int j = n - 1;
        while(mon <= total)
        {
            mon += a[j]; total -= a[j];
            num++; j--;
        }

        printf("%d\n",num);

    }
    return 0;
}
