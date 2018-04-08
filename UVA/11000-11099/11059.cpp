#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=20;
int data[maxn];

int main()
{
    int n,T=1;
    long long maxNumber;
    while(scanf("%d",&n)==1)
    {
        maxNumber=0;
        for(int i=0;i<n;i++)
            scanf("%d",&data[i]);
        for(int i=0;i<n;i++)
        {
            long long ans,cnt;
            ans=data[i];
            for(int j=i+1;j<n;j++)
            {
                cnt=data[i];
                for(int k=i+1;k<=j;k++)
                    cnt*=data[k];
                ans=max(ans,cnt);
            }
            maxNumber=max(ans,maxNumber);
        }
        printf("Case #%d: The maximum product is %lld.\n\n",T++,maxNumber);
    }
    return 0;
}
