#include<stdio.h>

const int maxn = 10000 + 10;
const int M = 10001;
int n, x[maxn];

void slove()
{
    for(int a = 0; a < M; a++)
    {
        for(int b = 0; b < M; b++)
        {
            int ok = 1;
            for(int i = 2; i <= 2 * n; i += 2)
            {
                x[i] = (a * x[i - 1] + b) % M;
                if(i < 2 * n && (a * x[i] + b) % M != x[i + 1]  )
                {
                    ok = 0;
                    break;
                }
            }
            if(ok) return;
        }
    }
}

int main()
{
    while(scanf("%d",&n) == 1)
    {
        for(int i = 1; i <= n * 2 - 1; i += 2)
            scanf("%d",&x[i]);

        slove();

        for(int i = 2; i <= 2 * n; i += 2)
            printf("%d\n",x[i]);
    }
}
