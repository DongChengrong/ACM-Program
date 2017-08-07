#include<stdio.h>

void sort(int A[],int N)
{
    for(int i=0;i<N-1;i++)
    {
        for(int j=1;j<N-i;j++)
        {
            if(A[j]<A[j-1])
            {
                int temp=A[j];
                A[j]=A[j-1];
                A[j-1]=temp;
            }
        }
    }
}

int main()
{
    int a[10],i;
    for(i=0;i<10;i++) scanf("%d",&a[i]);
    sort(a,10);
    for(i=0;i<10;i++) printf("%d ",a[i]);
    printf("\n");
}

//12 20 35 68 94 100 2 57 71 36
