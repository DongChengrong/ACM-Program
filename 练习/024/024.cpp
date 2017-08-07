#include<stdio.h>

void sort(int A[],int N)
{
    for(int i=0;i<N-1;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            if(A[j]<A[i])
            {
                int temp=A[j];
                A[j]=A[i];
                A[i]=temp;
            }
        }
    }
}

int main()
{
    int a[10];
    for(int i=0;i<10;i++) scanf("%d",&a[i]);
    sort(a,10);
    for(int i=0;i<10;i++) printf("%d ",a[i]);
    printf("\n");
}
//²âÊÔÊý¾Ý
//12 20 35 68 94 100 2 57 71 36
