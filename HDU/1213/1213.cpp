#include<stdio.h>
#include<stdio.h>

const int maxn = 1000 + 10;
int has[maxn], pa[maxn];

void init(int n)
{
    for(int i = 1; i <= n; i++)
    {
        has[i] = 0; pa[i] = i;
    }
}

int findset(int x)
{
    return pa[x] == x ? x : pa[x] = findset(pa[x]);
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);

        init(n);
        int cnt = n;
        while(m--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x = findset(x); y = findset(y);
            if(x != y)
            {
                pa[x] = y;
                cnt--;
            }
        }

        printf("%d\n",cnt);
    }
    return 0;
}
