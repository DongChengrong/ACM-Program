#include<stdio.h>

int f(int n)
{
    if(n == 1 || n == 0) return 1;

    int ans = 1;
    for(int i = 1; i <= n; i++)
        ans *= i;
    return ans;
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m) == 2)
    {
        int result = f(n) / (f(n - m) * f(m)) * m;
        printf("%d\n",result);
    }
    return 0;
}
