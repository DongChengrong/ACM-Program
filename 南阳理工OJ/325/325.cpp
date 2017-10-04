#include<stdio.h>
#include<stdlib.h>
#include<math.h>

const int maxn = 20 + 5;
int w[maxn],total,sum,min,n;

void dfs(int start)
{
    if(start == n) return;

    if(abs(total - sum * 2) < min)
        min = abs(total - sum * 2);

    for(int i = start; i < n; i++)
    {
        sum += w[i];
        dfs(i+1);
        sum -= w[i];
    }
}

int main()
{
    while(scanf("%d",&n) != EOF)
    {
        total = sum = 0;
        min = 10001 * n;
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&w[i]);
            total += w[i];
        }
        dfs(0);
        printf("%d\n",min);
    }
    return 0;
}
