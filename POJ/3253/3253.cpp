#include<cstdio>
#include<queue>
using namespace std;
struct cmp
{
    bool operator()(const int a,const int b)
    {
        return a>b;
    }
};
int main()
{
    int n,x;
    long long total;
    priority_queue<int,vector<int>,cmp> q;
    total=0;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&x);
        q.push(x);
    }
    int a,b;
    while(q.size()>1)
    {
        a=q.top();
        q.pop();
        b=q.top();
        q.pop();
        total+=a+b;
        q.push(a+b);
    }
    printf("%lld",total);
    return 0;
}
