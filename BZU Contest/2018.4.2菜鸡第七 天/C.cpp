#include<stdio.h>
#include<algorithm>
using namespace std;

#define N 200100

int a[N], b[N];

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m) == 2)
    {
        for(int i = 0; i < n; i++)
            scanf("%d",&a[i]);
        for(int i = 0; i < m; i++)
            scanf("%d",&b[i]);

        sort(a,a+n);

        for(int i = 0; i < m; i++)
        {
            int ans = upper_bound(a,a+n,b[i]) - a;
            printf("%d%c",ans,i == m - 1 ? '\n' : ' ');
        }
    }
    return 0;
}
