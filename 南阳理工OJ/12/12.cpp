#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn = 100000 + 10;
int vis[maxn];

struct Node
{
    int x,r;
}u[maxn];

int cmp(Node u1, Node u2)
{
    return u1.r < u2.r;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,w,h;
        scanf("%d %d %d",&n,&w,&h);
        for(int i =1; i <= n; i++)
            scanf("%d %d",&u[i].x,&u[i].r);

        memset(vis,0,sizeof(vis));
        sort(u+1, u + 1 + n,cmp);

        int ans = 0;
        for(int i =1; i <= n; i++)
        {
            //左右边界
            int r,l;
            l = u[i].x - u[i].r;
            r = u[i].x + u[i].r;
            if(l < 0) l = 0;
            if(r > w) r = w;

            //判断是否需要安装喷水器
            int yes = 0;
            for(int j = l; j <= r; j++)
                if(!vis[j])
                    {yes = 1; break;}

            //根据情况进行实际操作
            if(yes)
            {
                if(r * 2 < h) continue;
                else
                {
                    ans++;
                    for(int j = l; j <= r; j++)
                        vis[j] = 1;
                }
            }
        }

        //检查是否完全覆盖
        int ok = 1;
        for(int i = 0; i <= w; i++)
            if(!vis[i]) { ok = 0; break; }

        if(ok) printf("%d\n",ans);
        else printf("0\n");
    }
    return 0;
}
