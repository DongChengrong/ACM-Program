#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int cash,n;
struct Node
{
    int num,v;
}s[11];

int dp[12][100005];

int main()
{
    while(cin>>cash>>n)
    {
        int cont,ma=0;
        if(!cash || !n) { cout<<0<<endl; continue; }
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++) cin>>s[i].num>>s[i].v;
        for(int i=1;i<=n;i++)
        {
            for(int j=s[i].v;j<=cash;j++)
            {
                cont=min(s[i].num,cash/s[i].v);
                for(int k=1;k<=cont;k++)
                {
                    dp[i][j]=max(dp[i][j],dp[i-1][j-s[i].v*k]+k*s[i].v);
                    cout<<dp[i][j]<<"   1111"<<endl;
                    ma=max(dp[i][j],ma);
                }
            }
        }
        cout<<ma<<endl;
    }
    return 0;
}
