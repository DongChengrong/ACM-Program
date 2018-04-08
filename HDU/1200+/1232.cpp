#include<stdio.h>

const int maxn = 1000 + 10;
int pa[maxn];

void init(int n)
{
    for(int i = 1; i <= n; i++)
        pa[i] = i;
}

int findset(int x)
{
    return x == pa[x] ? x : pa[x] = findset(pa[x]);
}

int main()
{
    int n,m;
    while(scanf("%d",&n) == 1 && n)
    {
        scanf("%d",&m);
        init(n);
        int cnt = n;
        while(m--)
        {
            int x, y;
            scanf("%d%d",&x,&y);
            x = findset(x); y = findset(y);
            if(x != y)
            {
                pa[x] = y; cnt--;
            }
        }
        printf("%d\n",cnt - 1);
    }
    return 0;
}
