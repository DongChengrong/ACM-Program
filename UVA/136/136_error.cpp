#include<cstdio>
#include<queue>
using namespace std;

int main()
{
    queue<long long> q;
    int ans=1;
    q.push(1);
    while(ans!=1500)
    {
        long long x=q.front();
        q.pop();
        q.push(x*2); q.push(x*3); q.push(x*5);
        ans++;
    }
    printf("%d\n",q.front());
    return 0;
}
