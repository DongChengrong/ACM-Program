#include<stdio.h>

typedef long long LL;

const int maxn = 50 + 10;
LL a[maxn];

void init()
{
    a[1] = 1; a[0] = 1;
    for(int i = 2; i <= 50; i++)
        a[i] = a[i- 1] + a[i - 2];
}

int main()
{
    int n;
    init();
    while(scanf("%d",&n) == 1 && n)
    {
        printf("%lld\n",a[n]);
    }
    return 0;
}
