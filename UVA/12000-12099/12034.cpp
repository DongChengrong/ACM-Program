#include<stdio.h>

const int maxn = 1000;
const int M =  10056;

int c[maxn+10][maxn+10];
int f[maxn+10];

void init()
{
    for(int i = 0; i <= maxn; i++)
    {
        c[i][0] = c[i][i] = 1;
        for(int j = 1; j < i;j++)
            c[i][j] = (c[i-1][j] + c[i-1][j-1]) % M;
    }
    f[0] = 1;
    for(int i = 1; i <= maxn; i++)
    {
        f[i] = 0;
        for(int j = 1; j <= i; j++)
            f[i] = (f[i] + c[i][j] * f[i - j]) % M;
    }
}

int main()
{
    int T,n;
    scanf("%d",&T);
    init();
    for(int kase = 1; kase <= T; kase++)
    {
        scanf("%d",&n);
        printf("Case %d: %d\n",kase,f[n]);
    }
    return 0;
}
