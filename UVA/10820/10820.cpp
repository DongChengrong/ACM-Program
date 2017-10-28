#include<stdio.h>

const int maxn =  50001 + 10;
int phi[maxn];

void phi_table(int n)
{
    for(int i = 2; i <= n; i++) phi[i] = 0;
    phi[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        if(!phi[i])
        {
            for(int j = i; j <= n; j += i)
            {
                if(!phi[j]) phi[j] = j;
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
}

int main()
{
    int n;
    phi_table(50001);
    while(scanf("%d",&n) == 1 && n)
    {
        if(n == 1)
        {
            printf("1\n");
            continue;
        }
        int ans = 0;
        for(int i = 2; i <= n; i++)
            ans += phi[i];
        printf("%d\n", 2 * ans + 1);
    }
    return 0;
}
