#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=10000+10;
int data[maxn];
int cnt,ma,n;

bool read_group()
{
    int cur=3*(cnt-1);
    int ans=data[cur];
    for(int i=1;i<3;i++)
    {
        if(cnt%2) ans=max(ans,data[cur+i]);
        else ans=min(ans,data[cur+i]);
    }
    ma=max(ans,ma);
    return 3*cnt==n;
}

int main()
{
    while(scanf("%d",&n)==1)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&data[i]);
        }
        //³õÊ¼»¯
        cnt=1; ma=data[0];
        while(1)
        {
            if(read_group()) break;
            cnt++;
        }
        printf("%d\n",ma);
    }
    return 0;
}
