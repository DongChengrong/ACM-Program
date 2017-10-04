#include<stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,x,sum,max;
        scanf("%d",&n);
        scanf("%d",&sum);
        max = sum;
        n--;

        while(n--)
        {
            scanf("%d",&x);
            if(sum < 0) sum = x;
            else sum += x;
            if(max < sum) max = sum;
        }

        printf("%d\n",max);
    }
    return 0;
}
