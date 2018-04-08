#include<iostream>
#include<algorithm>
using namespace std;

int head[20000];
int knight[20000];

int main()
{
    int n,m;
    int cur,sum;
    while(cin>>n>>m && (n || m) )
    {
        sum=cur=0;
        for(int i=0;i<n;i++) cin>>head[i];
        for(int i=0;i<m;i++) cin>>knight[i];
        sort(head,head+n);
        sort(knight,knight+m);
        for(int i=0;i<m;i++)
        {
            if(cur==n) break;
            if(knight[i]>=head[cur]) { cur++; sum+=knight[i]; }
        }
        if(cur==n) cout<<sum<<endl;
        else cout<<"Loowater is doomed!"<<endl;
    }
    return 0;
}
