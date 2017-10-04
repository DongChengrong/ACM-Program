#include <stdio.h>
#include <math.h>
int a[21],sum,all,n,i,j,min;
void dfs(int star)
{
    if(star==n)
        return ;
    if(fabs(all-sum*2)<min)//差值最小。。如果这里不懂 动动手 原式转换得到的
        min=fabs(all-sum*2);
    for(int j=star;j<n;j++)
    {
        sum+=a[j];
        dfs(j+1);
        sum-=a[j];
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        all=0;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]),all+=a[i];
        min=n*10001;
        dfs(0);
        printf("%d\n",min);
    }
}
