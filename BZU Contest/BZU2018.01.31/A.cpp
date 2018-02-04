#include<stdio.h>

const int maxn = 110;
int a[maxn];

int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k) == 2)
    {
        for(int i = 1; i <= n; i++)
            scanf("%d",&a[i]);
        int m = a[k];
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            if(a[i] > 0)
                if(a[i] >= m)
                    cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
