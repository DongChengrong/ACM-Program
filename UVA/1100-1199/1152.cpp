#include<stdio.h>
#include<algorithm>
using namespace std;

const int maxn = 4000 + 10;
int a[maxn],b[maxn],c[maxn],d[maxn],ab[maxn * maxn];

int main()
{
    int Test;
    scanf("%d",&Test);
    while(Test--)
    {
        int line, n = 0;
        scanf("%d",&line);

        for(int i = 0; i < line; i++)
            scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);

        for(int i = 0; i < line; i++)
            for(int j = 0; j < line; j++)
                ab[n++] = a[i] + b[j];

        sort(ab, ab + n);

        long long ans = 0;
        for(int i = 0; i < line; i++)
            for(int j = 0; j < line; j++)
                ans += upper_bound(ab, ab + n, -c[i]-d[j]) - lower_bound(ab, ab + n, -c[i]-d[j]);
        printf("%lld\n",ans);
        if(Test) printf("\n");

    }
    return 0;
}
