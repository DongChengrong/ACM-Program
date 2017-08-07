#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=250*250;
const int maxroute=maxn+100;

int num[maxn],s[maxn];
int g[maxn],dp[maxn];

int main()
{
    int test;
    int N,q,p;
    scanf("%d",&test);
    for(int j=1;j<=test;j++)
    {
        scanf("%d%d%d",&N,&p,&q);
        int temp,n=0;
        for(int i=1;i<=p+1;i++) { scanf("%d",&temp); num[temp]=i;}
        for(int i=0;i<q+1;i++) { scanf("%d",&temp); if(num[temp]) s[n++]=num[temp];}
        for(int i=1;i<=n;i++) g[i]=maxroute;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int k=lower_bound(g+1,g+1+n,s[i])-g;
            dp[i]=k;
            g[k]=s[i];
            ans=max(dp[i],ans);
        }
        printf("Case %d: %d\n",j,ans);
    }
    return 0;
}
