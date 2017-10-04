#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        int sum = ((abs(n - 1) + 1) * (n + 1)) / 2;
        printf("%d\n",sum);
    }
    return 0;
}
