#include<stdio.h>

const int maxn = 5000 + 10;
int a[maxn];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,k;
        scanf("%d%d",&n,&k);

        for(int i = 1; i <= n; i++)
            scanf("%d",&a[i]);

        int ok = 0;
        int i = 1,j = n;
        for(i <= j)
            for(int j = i; j <= n; j++)
            {
                if(ok) continue;

                int sum = 0;
                for(int z = i; z <= j; z++)
                    sum += a[z];
                if(sum == k)
                {
                    printf("%d %d\n",i,j);
                    ok = 1;
                    break;
                }
            }
    }
    return 0;
}
