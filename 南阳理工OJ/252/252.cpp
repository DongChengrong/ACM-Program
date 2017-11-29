#include<stdio.h>

const int maxn = 50;
int d[maxn];

void init()
{
    d[1] = 2;
    d[2] = 3;
    for(int i = 3; i <= 40; i++)
        d[i] = d[i - 1] + d[i - 2];
}

int main()
{
    int n,T;
    init();
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        printf("%d\n",d[n]);
    }
    return 0;
}
