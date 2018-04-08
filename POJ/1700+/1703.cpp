/*
利用并查集来维护不同集合之间的关系
此方法仅适用于只有两个集合的情况
我们可以用x + n来表示x的不同集合
这样的话，如果x和y是不同的集合则x+n和y属于同一个集合
y+n和x属于不同集合
两个集合属于同一个集合当且仅当Same(x,y)或Same(x+n,y+n)成立时
两个集合不属于同一个集合时，当且仅当Same(x+n,y)或Same(x,y+n)成立时
否则，x与y的状态未确定
*/

#include<stdio.h>

#define N (2 * 100100)

int pa[N];

void init(int n){
    for(int i = 0; i <= 2 * n; i++)
        pa[i] = i;
}

int findset(int x){
    return pa[x] == x ? x : pa[x] = findset(pa[x]);
}

void Union(int x, int y)
{
    x = findset(x);
    y = findset(y);
    if(x != y)
        pa[x] = y;
}

bool Same(int x, int y)
{
    x = findset(x);
    y = findset(y);
    return x == y;
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
        while(m--)
        {
            char c;
            int x,y;
            getchar();
            scanf("%c %d %d",&c,&x,&y);
            if(c == 'D')
            {
                Union(x,y+n);
                Union(x+n,y);
            }
            if(c == 'A')
            {
                if(Same(x,y) || Same(x+n,y+n)) printf("In the same gang.\n");
                else if(Same(x,y+n) || Same(x+n,y)) printf("In different gangs.\n");
                else printf("Not sure yet.\n");
            }
        }
    }
    return 0;
}

