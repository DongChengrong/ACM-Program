#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int a[1000001],dp[1000001],max1[1000001];
int max(int x,int y)
{
    return x>y?x:y;
}
int main()
{
    int i,j,n,m,temp;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            dp[i]=0;
            max1[i]=0;
        }
        dp[0]=0;
        max1[0]=0;
        for(i=1;i<=m;i++)//这里可以省空间
        {
            temp=-100000000;
            for(j=i;j<=n;j++)
            {
                dp[j]=max(dp[j - 1] + a[j],max1[j-1]+a[j]);
                max1[j-1]=temp;//为i+1的时候做准备
                temp=max(temp,dp[j]);//保存前j个段数为i时的最大值
            }
        }
        printf("%d\n",temp);
    }
    return 0;
}
