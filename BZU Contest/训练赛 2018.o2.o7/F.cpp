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
    int n,m,k;
    while(scanf("%d%d%d",&n,&m,&k) == 3)
    {
        for(int i = 0; i < m+1; i++)
            scanf("%d",&a[i]);
        int num = 0;
        for(int i = 0; i < m; i++)
        {
            int cnt = 0;
            int x = (a[i] ^ a[m]);
            while(x)
            {
                if(cnt > k) break;
                if(x & 1) cnt++;
                x = x >> 1;
            }
            if(cnt <= k) num++;
        }
        printf("%d\n",num);
    }
    return 0;
}
