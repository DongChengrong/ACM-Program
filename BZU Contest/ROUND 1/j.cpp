#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn = 10000 + 10;
int a[maxn];

int main()
{
    int n;
    while(scanf("%d",&n) == 1 && n)
    {
        for(int i = 0; i < n; i++)
            scanf("%d",&a[i]);

        int ans = 0;
        int start = 0;
        int end = 0;
        int s = 0, e = 0;
        int Max = -10000000;
        for(int i = 0; i < n; i++)
        {
            if(ans >= 0)
            {
                ans = ans += a[i];
                e = i;
            }
            else
            {
               ans = a[i];
               s = i;
               e = i;
            }

            if(ans > Max)
            {
                Max = ans;
                start = s;
                end = e;
            }
        }
        if(Max < 0) printf("0 %d %d\n",a[0],a[n-1]);
        else printf("%d %d %d\n",Max,a[start],a[end]);
    }
    return 0;
}
