#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

const int maxn = 1000000 + 10;
int vis[maxn];

struct Point
{
    int x,p;
    Point(){}
    Point(int x,int p)
    {
        this->x = x;
        this->p = p;
    }
};

int bfs(int n,int k)
{
    if(n >= k) return n - k;
    queue<Point> q;
    q.push(Point(n,0));
    while(!q.empty())
    {
        Point p = q.front(); q.pop();
        for(int i = 0; i < 3; i++)
        {
            Point next;
            if(i == 0) next.x = p.x + 1;
            if(i == 1) next.x = p.x - 1;
            if(i == 2) next.x = p.x * 2;
            next.p = p.p + 1;
            if(next.x < 0 || next.x >= maxn || vis[next.x]) continue;
            if(next.x == k) return next.p;
            vis[next.x] = 1;
            q.push(next);
        }
    }
    return 0;
}

int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k) == 2)
    {
        memset(vis,0,sizeof(vis));
        printf("%d\n",bfs(n,k));
    }
    return 0;
}
