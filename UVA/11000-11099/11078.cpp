#include<stdio.h>
#include<algorithm>
using namespace std;

const int maxn = 100000 + 10;
int a[maxn];

int main()
{
    int T, n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
            scanf("%d",&a[i]);
        int ans =  a[0] - a[1];
        int Max = a[0];
        for(int i = 1; i < n; i++)
        {
            ans = max(ans, Max - a[i]);
            Max = max(Max, a[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
