#include<iostream>
#include<queue>
using namespace std;

int n;

void bfs()
{
    queue<long long> q;
    long long pos,x;
    q.push(1);
    while(!q.empty())
    {
        pos=q.front();
        q.pop();
        for(int i=0;i<2;i++)
        {
            x=pos*10+i;
            if(x%n==0) { cout<<x<<endl; return; }
            q.push(x);
        }
    }
}

int main()
{
    while(cin>>n && n)
    {
        if(n==1) { cout<<1<<endl; continue; }
        bfs();
    }
    return 0;
}
