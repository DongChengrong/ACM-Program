#include<stdio.h>
#include<algorithm>
using namespace std;

const int maxn = 20 + 10;
int a[maxn], d[maxn];

int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
            scanf("%d",&a[i]);

        for(int i = 0; i < n; i++)
            d[i] = 1;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < i; j++)
                if(a[j] > a[i]) d[i] = max(d[i],d[j] + 1);

        int cnt = 1;
        for(int i = 0; i < n; i++)
            cnt = max(d[i],cnt);

        printf("%d\n",cnt);
    }
    return 0;
}
