#include<cstdio>
#include<queue>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        queue<int> q;
        printf("Discarded cards:");
        for(int i=1;i<=n;i++) q.push(i);
        while(q.size()>2)
        {
            int x1=q.front(); q.pop();
            int x2=q.front(); q.pop();
            printf(" %d,",x1);
            q.push(x2);
        }
        if(q.size()==2) { printf(" %d",q.front()); q.pop(); }
        putchar('\n');
        printf("Remaining card: %d\n",q.front());
    }
    return 0;
}
