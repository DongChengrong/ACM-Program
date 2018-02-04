#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 1000000 + 10;

int a[maxn];


int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        for(int i = 0; i < n; i++)
            scanf("%d",&a[i]);
        int ma = 1, l = 0;
        while(l < n)
        {
            int j;
            for(j = l + 1; j < n; j++)
                if(a[j] < a[j - 1]) break;
            ma = max(ma, j - l);
            l = j;
        }
        printf("%d\n",ma);
    }
    return 0;
}
