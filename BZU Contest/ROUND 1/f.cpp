#include<stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,i;
        scanf("%d",&n);
        for(i = 1; ; i++)
        {
            if(n <= i) break;
            n -= i;
        }

        int result = n % 9;
        printf("%d\n",result == 0 ? 9 : result);
    }
    return 0;
}
