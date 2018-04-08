#include<stdio.h>
#include<string.h>

const int maxn = 20;
long long d[maxn + 10][maxn + 10][maxn + 10];

void init()
{
    d[1][1][1] = 1;
    for(int i = 2; i <= maxn; i++)
        for(int j = 1; j <= i; j++)
            for(int k = 1; k <= i; k++)
            {
                d[i][j][k] = d[i-1][j][k] *(i -2);
                if(j > 1) d[i][j][k] += d[i -1][j -1][k];
                if(k > 1) d[i][j][k] += d[i - 1][j][k - 1];
            }
}

int main()
{
    int T,l,r,n;
    init();
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&l,&r);
        printf("%lld\n",d[n][l][r]);
    }
    return 0;
}
