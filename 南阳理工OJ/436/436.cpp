#include<stdio.h>

const int maxn = 10000 + 10;
int nums[maxn];

void init()
{
    nums[1] = 1;
    for(int i = 2; i <= 10000; i++)
        nums[i] = nums[i - 1] + i;
}

int main()
{
    int n;
    init();
    while(scanf("%d",&n) == 1)
    {
        if(n == 0) printf("1\n");
        else if(n > 0) printf("%d\n",nums[n]);
        else  printf("%d\n",-1 * nums[n * -1] + 1);
    }
    return 0;
}
