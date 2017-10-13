#include<stdio.h>
#include<math.h>

long long c(int i)
{
    return i == 0 ? 1 : 3 * c(i - 1);
}

long long g(int k,int i)
{
    //终止条件
    if(i <= 0) return 0;
    if(k == 0) return 1;

    //2的k-1次方
    int k2 = 1 << (k - 1);

    //递归
    if(i > k2)
        return 2 * g(k - 1, i - k2) + c(k - 1);
    else return g(k - 1, i);
}

int main()
{
    int a,b,k,T;
    scanf("%d",&T);
    for(int kase = 1; kase <= T; kase++)
    {
        scanf("%d%d%d",&k,&a,&b);
        int k2 = 1 << k;
        //最优解
        long long ans = g(k,k2 - a + 1) - g(k,k2 - b);
        printf("Case %d: %lld\n",kase,ans);
    }
    return 0;
}
