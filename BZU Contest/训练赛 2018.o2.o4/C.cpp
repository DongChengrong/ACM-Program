#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 100000 + 10;

int main()
{
    int y;
    while(scanf("%d",&y) == 1)
    {
        int ans;
        for(int i = y + 1; ; i++)
        {
            int ok = 1;
            int x = i;
            int a[20];
            memset(a,0,sizeof(a));
            while(x)
            {
                if(a[x % 10]) { ok = 0; break;}
                a[x % 10]++;
                x /= 10;
            }
            if(ok){
                ans = i; break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
