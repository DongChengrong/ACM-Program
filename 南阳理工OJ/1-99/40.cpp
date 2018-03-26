#include<stdio.h>

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int a,b,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&a,&b);
        printf("%d %d\n",gcd(a,b), a * b / gcd(a,b));
    }
    return 0;
}
