#include<cstdio>
#include<queue>
#include<set>
#include<vector>
using namespace std;

typedef long long LL;
int d[]={2,3,5};

int main()
{
    set<long long> s;
    priority_queue<LL,vector<LL>,greater<LL> > q;
    int ans=1;
    s.insert(1);
    q.push(1);
    while(ans!=1500)
    {
        long long x=q.top();
        q.pop();
        for(int i=0;i<3;i++)
        {
            long long y=x*d[i];
            if(!s.count(y)) { s.insert(y); q.push(y); }
        }
        ans++;
    }
    printf("The 1500'th ugly number is %lld.\n",q.top());
    return 0;
}
