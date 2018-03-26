#include<stdio.h>
#include<string.h>

const int maxn =  50000 + 10;
int pa[maxn],w[maxn];

void init(int n)
{
    memset(w,0,sizeof(w));
    for(int i = 1; i <= n; i++)
        pa[i] = i;
}

int findset(int x){
    return x == pa[x] ? x : pa[x] = findset(pa[x]);
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m) == 2)
    {
        init(n);
        while(m--)
        {
            int x,y,k;
            scanf("%d%d%d",&x,&y,&k);
            x = findset(x); y = findset(y);
            if(x != y){
                pa[x] = pa[y];
                w[x] = w[y] = max(k,max(w[x],w[y]))
            }
        }
    }
    return 0;
}
