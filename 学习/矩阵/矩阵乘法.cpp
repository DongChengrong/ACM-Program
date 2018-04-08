#include<stdio.h>
#include<string.h>

#define N 110

int a[N][N],res[N][N];

void read(int n)
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d",&a[i][j]);
}

void mutil(int n)
{
    memset(res,0,sizeof(res));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= n; k++)
                res[i][j] += a[i][k] * a[k][j];
}

void write(int n)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            printf("%d ",res[i][j]);
        printf("\n");
    }
}

int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        read(n);

        mutil(n);

        write(n);
    }
    return 0;
}
