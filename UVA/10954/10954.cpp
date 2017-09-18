#include<stdio.h>
#include<queue>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n) == 1 && n)
    {
        int t;
        priority_queue<int, vector<int>, greater<int> > q;
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&t); q.push(t);
        }
        int ans = 0;
        for(int i = 0; i < n - 1; i++)
        {
            int a = q.top(); q.pop();
            int b = q.top(); q.pop();
            ans += a + b;
            q.push(a + b);
        }
        printf("%d\n",ans);
    }
    return 0;
}
