#include<stdio.h>
#include<string.h>

#define N 10000

int vis[N + 100];

void d(int n)
{
    int x = n;
    while(x)
    {
        n += x % 10;
        x /= 10;
    }
    vis[n] = 1;
}

int main()
{

    memset(vis,0,sizeof(vis));
    for(int i = 0; i <= N; i++)
        d(i);
    for(int i = 1; i < N; i++)
        if(!vis[i]) printf("%d\n",i);
    return 0;
}
