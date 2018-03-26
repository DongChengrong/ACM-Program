#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int is_prime(int n)
{
    if(n <= 1) return 0;
    int m = floor(sqrt(n) + 0.5);
    for(int i = 2;i <= m; i++)
        if(n % i == 0) return 0;
    return 1;
}

int left(int n)
{
    int a = 0;
    while(n--)
    {
        a++;
        if(is_prime(n)) break;
    }
    return a;
}

int right(int n)
{
    int a = 0;
    while(n++)
    {
        a++;
        if(is_prime(n)) break;
    }
    return a;
}

int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        if(n <= 1) printf("2 %d\n",2 - n);
        else if(is_prime(n)) printf("%d %d\n",n,0);
        else
        {
            int x = left(n);
            int y = right(n);
            if(x <= y) printf("%d %d\n",n - x,x);
            else printf("%d %d\n",n + y,y);
        }
    }
    return 0;
}
