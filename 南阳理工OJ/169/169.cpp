#include<stdio.h>
#include<stdlib.h>
#include<math.h>

const int maxn = 1000 + 10;
int prime[maxn];

int is_prime(int n)
{
    if(n <= 1) return 0;
    int m = floor(sqrt(n) + 0.5);
    for(int i = 2;i <= m; i++)
        if(n % i == 0) return 0;
    return 1;
}

void init()
{
    int cnt = 0;
    for(int i = 2; i <= 2000; i++)
        if(is_prime(i)) prime[cnt++] = i;
}

int main()
{
    int T,n;
    init();
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int pos = 0,min = 1000000;
        for(int i = 0; i < 1000; i++)
        {
            if(abs(n - prime[i]) <= min)
            {
                pos = i; min = abs(n - prime[i]);
            }
            else break;
        }
        printf("%d\n",prime[pos]);
    }
    return 0;
}
