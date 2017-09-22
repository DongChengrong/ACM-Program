#include<stdio.h>

int main()
{
    int V;
    while(scanf("%d",&V) == 1)
    {
        int array[10];
        int min = 10001;
        for(int i = 1; i <= 9; i++)
        {
            scanf("%d",&array[i]);
            //确定最小的耗油量
            if(array[i] <= min)
                min = array[i];
        }

        //判断是否有解
        if(min > V)
        {
            printf("-1\n");
            continue;
        }

        //确定数字的位数
        int bit = V / min;
        //打印输出解
        while(bit--)
        {
            for(int i = 9; i >= 1; i--)
            {
                if(V >= array[i] && (V - array[i]) / min == bit )
                {
                    printf("%d",i);
                    V -= array[i];
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
