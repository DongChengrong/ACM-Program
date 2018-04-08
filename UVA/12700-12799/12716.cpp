#include<stdio.h>
#include<string.h>

const int M = 30000000;
const int maxn = 30000000 + 10;
int cnt[maxn],sum[maxn];

void init()
{
    memset(cnt,0,sizeof(cnt));
    for(int c = 1; c <= M; c++)
    {
        for(int a = c * 2; a <= M; a += c)
        {
            int b = a - c;
            if((a ^ b) == c) cnt[a]++;
        }
    }

    sum[0] = 0;
    for(int i = 1; i <= M; i++)
        sum[i] = sum[i - 1] + cnt[i];
}

int main()
{
    int T,n;
    init();
    scanf("%d",&T);
    for(int kase = 1; kase <= T; kase++)
    {
        scanf("%d",&n);
        printf("Case %d: %d\n",kase,sum[n]);
    }
    return 0;
}
