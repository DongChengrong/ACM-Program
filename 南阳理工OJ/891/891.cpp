#include<stdio.h>
#include<algorithm>
using namespace std;

const int maxn = 100 + 10;

struct Node
{
    int l,r;
}u[maxn];

int cmp(Node u1, Node u2)
{
    if(u1.l != u2.l) return u1.l < u2.l;
    else return u1.r < u2.r;
}

int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        for(int i = 0; i < n; i++)
            scanf("%d%d",&u[i].l,&u[i].r);

        sort(u, u + n, cmp);

        int ans = 1,i = 1,cur = u[0].r;
        while(i < n)
        {
            if(u[i].r < cur) cur = u[i].r;
            else if(u[i].l > cur)
            {
                cur = u[i].r; ans++;
            }
            i++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
