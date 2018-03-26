#include<stdio.h>
#include<string.h>

const int maxn = 100000 + 10;
int pa[maxn],has[maxn];

int x,y;
int ok ;
int cnt,node;

void init()
{
    for(int i = 1; i < maxn; i++)
        pa[i] = i;
    memset(has,0,sizeof(has));
    ok = 1; cnt = 0; node = 0;
}

int findset(int x)
{
    return pa[x] == x ? x : pa[x] = findset(pa[x]);
}

int main()
{
    init();
    while(scanf("%d%d",&x,&y) == 2)
    {
        if(x == -1) break;
        if(x == 0)
        {
            if((cnt - node) != -1 && (cnt !=0 && node != 0)) ok = 0;
            if(ok) printf("Yes\n");
            else printf("No\n");
            init();
            continue;
        }
        cnt++;
        if(!has[x]) {node++; has[x] = 1;} if(!has[y]) {node++; has[y] = 1;}
        x = findset(x); y = findset(y);
        if(x == y) ok = 0;
        else
        {
            pa[x] = y;
        }
    }
    return 0;
}
