#include<stdio.h>

int a[20];

void print(int n,int cur)
{
    int i,j,y;
    if(cur==n)
    {
        for(i=0;i<n;i++)
            printf("%d ",a[i]);
        printf("\n");
    }
    else
    {
        for(i=1;i<=n;i++)
        {
            y=1;
            for(j=0;j<cur;j++)
                if(a[j]==i)
                    y=0;
            if(y)
            {
                a[cur]=i;
                print(n,cur+1);
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    print(n,0);
    return 0;
}
