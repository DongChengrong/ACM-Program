#include<stdio.h>

void sort(int A[],int n)
{
    int i,j,tmp;
    for(i=1;i<n;i++)
    {
        tmp=A[i];
        for(j=i;j>0;j--)
        {
            if(tmp<A[j-1])
                A[j]=A[j-1];
            else break;
        }
        A[j]=tmp;
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
