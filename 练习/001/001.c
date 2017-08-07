#include<stdio.h>

int p[11]={0,1,5,8,9,10,17,17,20,24,30};

int max(int a,int b)
{
    return a>b?a:b;
}

int maxValue(int n)
{
    int i,j,q;
    int r[n+1];
    r[0]=0;
    for(i=1;i<=n;i++)
    {
        q=-1;
        for(j=1;j<=i;j++)
        {
            q=max(q,p[j]+r[i-j]);
        }
        r[i]=q;
    }
    return r[n];
}


int main()
{
    int n,m;
    while(~scanf("%d",&m) && m!=0)
    {
        n=maxValue(m);
        printf("%d\n",n);
    }
    return 0;
}

