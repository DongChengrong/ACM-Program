#include<stdio.h>

#define mod 10003

int f(int a,int n)
{
    if(n == 0) return 1;
    if(n == 1) return a % mod;
    int t = f(a,n / 2);
    t = t * t % mod;
    if(n & 1) return t * a % mod;
    else return t;
}

int main()
{
    int T,a,n;
    scanf("%d",&T);
    while(T--)
    {
        int sum = 0;
        scanf("%d%d",&a,&n);
        for(int i = 1; i <= a; i++)
            sum += f(i,n) % mod;
        printf("%d\n",sum % mod);
    }
    return 0;
}
