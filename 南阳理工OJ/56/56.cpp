#include<stdio.h>

int main()
{
    int T,n,m;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        int ans = 0;
        if(n < 2) printf("0\n");
        else
        {
            for(int i = 2; i <= n; i++)
            {
                int t = i;
                while(!(t % m))
                {
                    ans++;
                    t /= m;
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
