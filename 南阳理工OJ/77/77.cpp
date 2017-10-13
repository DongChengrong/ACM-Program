#include<stdio.h>
#include<string.h>

const int maxn = 1000 + 10;
int a[maxn];

int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k) == 2)
    {
        if(k == 1)
        {
            for(int i = 1; i < n; i++)
                printf("%d ",i);
            printf("%d\n",n);
        }
        else
        {
            memset(a,1,sizeof(a));
            for(int i = 2; i <= k; i++)
            {
                for(int j = 1; j <= n; j++)
                    if(j % i == 0) a[j] = !a[j];
            }
            int flag = 0;
            for(int i = 1; i <= n; i++)
            {
                if(a[i])
                {
                    if(flag) printf(" ");
                    else flag = 1;
                    printf("%d",i);
                }
            }
            printf("\n");
        }
    }
    return 0;
}
