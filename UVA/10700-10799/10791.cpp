#include<stdio.h>
#include<math.h>

int main()
{
    int T = 1;
    long long n;
    while(scanf("%lld",&n) == 1 && n)
    {
        if(n == 1)
        {
            printf("Case %d: %d\n",T++,2);
            continue;
        }

        long long ans = 0,pf = 0; //记录出现了几个素数因子
        int m = floor(sqrt(n) + 0.5);
        for(int i = 2; i <= m; i++)
        {
            if(n % i == 0)
            {
                int x = i;
                n /= i;
                pf++;
                while(n % i == 0)
                {
                    x *= i;
                    n /= i;
                }
                ans += x;
            }
        }
        if(n > 1){
           ans += n;
           pf++;
        }
        if(pf <= 1) ans += 1;
        printf("Case %d: %lld\n",T++,ans);
    }
}
