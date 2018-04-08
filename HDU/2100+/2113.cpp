#include<stdio.h>

int main()
{
    int x;
    bool flag = false;
    while(scanf("%d",&x) == 1)
    {
        if(flag) printf("\n");
        int sum = 0;
        while(x)
        {
            int tmp = x % 10;
            if((tmp & 1) == 0) sum += tmp;
            x /= 10;
        }
        printf("%d\n",sum);
        flag = true;
    }
}
