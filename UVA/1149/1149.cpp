#include<stdio.h>
#include<algorithm>
using namespace std;

const long maxn = 100000 + 10;
int a[maxn];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,w;
        scanf("%d%d",&n,&w);
        for(int i = 0; i < n; i++)
            scanf("%d",&a[i]);

        sort(a,a+n);

        int l = 0, r = n - 1;
        int ans = 0;
        while(l <= r)
        {
            if(r == l) {ans++; break;}
            if(a[r] + a[l] <= w)
            {
                r--; l++; ans++;
            }
            else
            {
                r--; ans++;
            }
        }
        printf("%d\n",ans);
        if(T) printf("\n");
    }
    return 0;
}
