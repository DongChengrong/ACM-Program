#include<stdio.h>

int main()
{
    int N,m;
    scanf("%d",&N);
    while(N--)
    {
        int result = 0;
        scanf("%d",&m);
        while(m)
        {
            if(m % 2 != 0) result++;
            m /= 2;
        }
        printf("%d\n",result);
    }
    return 0;
}
