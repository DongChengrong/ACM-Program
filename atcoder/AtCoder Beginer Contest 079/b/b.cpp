#include<stdio.h>
#include<string.h>

const int maxn = 100;
unsigned long long g[maxn];

unsigned long long f(int n)
{
   // printf("1\n");
    if(n == 0) return 2;
    if(n == 1) return 1;
    if(g[n] != 0) return g[n];

    return g[n] = f(n - 1) + f(n - 2);
}

void init()
{
    memset(g,0,sizeof(g));
    g[1] = 1; g[0] = 2;
    f(86);
}

int main()
{
    int n;
    init();
    while(scanf("%d",&n) == 1)
    {
        printf("%lld\n",g[n]);
    }
    return 0;
}
