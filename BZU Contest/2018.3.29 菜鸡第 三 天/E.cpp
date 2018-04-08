/*
这个题是求连续的不超过T的块有几个的问题
比较简单，可以根据前一个状态来推
这个题两个地方要注意，一个是边界，另一个就是先判断能否转移
*/

#include<stdio.h>

#define N 200100

typedef long long LL;

LL a[N];

int main()
{
    LL n,t,c;
    while(scanf("%lld%lld%lld",&n,&t,&c) == 3)
    {
        for(int i = 1; i <= n; i++)
            scanf("%lld",&a[i]);

        int i,j,cnt = 0;
        i = j = 1;
        while(j <= n){
            if(a[j] <= t) j++;
            else {
                i = j = (j + 1);
            }
            if(j - i ==  c){
                cnt++; i++;
            }

        }
        printf("%d\n",cnt);
    }
    return 0;
}
