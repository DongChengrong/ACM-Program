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
            //ȷ����С�ĺ�����
            if(array[i] <= min)
                min = array[i];
        }

        //�ж��Ƿ��н�
        if(min > V)
        {
            printf("-1\n");
            continue;
        }

        //ȷ�����ֵ�λ��
        int bit = V / min;
        //��ӡ�����
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
