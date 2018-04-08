#include<stdio.h>
#include<string.h>

#define N 100
#define MOD 9973

typedef long long LL;

LL a[N][N],res[N][N],tmp[N][N];

void mul(LL (*a)[N], LL (*b)[N], LL n)
{
    memset(tmp,0,sizeof(tmp));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                tmp[i][j] += (a[i][k] * b[k][j]) % MOD;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            a[i][j] = tmp[i][j];
}

int main()
{
    LL n,k,T;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld",&n,&k);

        memset(a,0,sizeof(a));
        memset(res,0,sizeof(res));
        memset(tmp,0,sizeof(tmp));

        for(LL i = 0; i < n; i++)
            for(LL j = 0; j < n; j++)
            {
                scanf("%lld",&a[i][j]);
                res[i][j] = a[i][j];
            }

        k--;
        while(k)
        {
            if(k & 1)
                mul(res,a,n);
            mul(a,a,n);
            k = k >> 1;
        }

        LL ans = 0;
        for(int i = 0; i < n; i++)
            ans = (ans + res[i][i]) % MOD;

        printf("%lld\n",ans % MOD);
    }
    return 0;
}
