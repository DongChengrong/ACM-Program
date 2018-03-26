#include<stdio.h>

int main()
{
    long num;
    while(scanf("%ld",&num) && num)
    {
        long n,temp,result = 0;
        n = num;
        while(n)
        {
            temp = n % 10;
            result += temp * temp * temp;
            n /= 10;
        }
        if(result == num) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
