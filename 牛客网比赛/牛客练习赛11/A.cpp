#include<stdio.h>
#include<algorithm>
using namespace std;

const int maxn = 1000 + 10;
int a[maxn],b[maxn];

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m) == 2)
    {
        for(int i = 1; i <= n; i++)
            scanf("%d",&a[i]);
        while(m--)
        {
            int way;
            scanf("%d",&way);
            if(way == 1)
            {
                int l,r,x,y;
                scanf("%d%d%d%d",&l,&r,&x,&y);
                for(int i = l; i <= r; i++)
                    if(a[i] == x)
                        a[i] = y;
            }
            else
            {
                int l,r,k;
                scanf("%d%d%d",&l,&r,&k);
                int s = 0;
                for(int i = l; i <= r; i++)
                    b[s++] = a[i];
                nth_element(b,b + k - 1, b + s);
                printf("%d\n",b[k - 1]);
            }
        }

    }
    return 0;
}
