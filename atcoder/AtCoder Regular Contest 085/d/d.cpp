#include<stdio.h>
#include<algorithm>
using namespace std;

const int maxn = 2000 + 10;
int a[maxn];

int main()
{
    int n,x,y;
    while(scanf("%d%d%d",&n,&x,&y) == 3)
    {
        for(int i = 1; i <= n; i++)
            scanf("%d",&a[i]);
        if(n == 1)
            printf("%d\n",abs(a[1] - y));
        else
            printf("%d\n",max(abs(a[n] - y),abs(a[n] - a[n - 1])));
    }
    return 0;
}
