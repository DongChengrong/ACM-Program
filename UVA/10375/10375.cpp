#include<stdio.h>
#include<string.h>
#include<math.h>

const int maxn = 10000;
int primes[maxn],cnt;
int e[maxn];

int is_prime(int n)
{
    int m = floor(sqrt(n) + 0.5);
    for(int i = 2; i <= m; i++)
        if(n % i == 0) return 0;
    return 1;
}

int init()
{
    cnt = 0;
    for(int i = 2; i < 10000; i++)
        if(is_prime(i)) primes[cnt++] = i;
}

int add_integer(int n, int d)
{
    for(int i = 0; i < cnt; i++)
    {
        while(n % primes[i] == 0)
        {
            e[i] += d;
            n /= primes[i];
        }
        if(n == 1) break;
    }
}

int add_factorial(int n, int d)
{
    for(int i = 1; i <= n; i++)
        add_integer(i,d);
}

int main()
{
    int p,q,r,s;
    init();
    while(scanf("%d%d%d%d",&p,&q,&r,&s) == 4)
    {
        memset(e,0,sizeof(e));

        add_factorial(p,1);
        add_factorial(q,-1);
        add_factorial(p-q,-1);
        add_factorial(s,1);
        add_factorial(r-s,1);
        add_factorial(r,-1);

        double ans = 1;
        for(int i = 0; i < cnt; i++)
        {
            if(e[i] != 0)
                ans *= pow(primes[i],e[i]);
        }

        printf("%.5lf\n",ans);
    }
    return 0;
}
