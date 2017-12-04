#include<stdio.h>

int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        int x = n;
        int sum = 0;
        while(x)
        {
            sum += x % 10;
            x /= 10;
        }
        if(n % sum == 0) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
