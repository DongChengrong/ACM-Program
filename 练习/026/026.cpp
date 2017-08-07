#include<stdio.h>

void sort(int A[],int n)
{
    int i,j,tmp,increment;
    for(increment=n/2;increment>0;increment/=2)
    {
        for(i=increment;i<n;i++)
        {
            tmp=A[i];
            for(j=i;j>=increment;j-=increment)
            {
                if(tmp<A[j-increment])
                    A[j]=A[j-increment];
                else break;
            }
            A[j]=tmp;
        }
    }
}

int main()
{
    int i=10;
    int A[10];
    printf("请输入10个整数：");
    for(i=0;i<10;i++) scanf("%d",&A[i]);
    sort(A,10);
    for(i=0;i<10;i++) printf("%d ",A[i]);
    printf("\n");
    return 0;
}
