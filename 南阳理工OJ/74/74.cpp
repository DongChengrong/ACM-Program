#include<stdio.h>

int main()
{
    int x,y;
    while(scanf("%d %d",&x,&y) == 2 && x)
    {
        int count = 0,flag = 0;
        while(x)
        {
            int a = x % 10;
            int b = y % 10;
            int c = a + b;
            if(flag) c += 1;
            if(c >= 10)
            {
                count++;
                flag = 1;
            }
            else flag = 0;
            x /= 10; y /= 10;
        }
        printf("%d\n",count);
    }
    return 0;
}
