#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct Node
{
    int b;
    int j;
}node[1000+5];

int cmp(struct Node x,struct Node y)
{
    return x.j>y.j;
}

int main()
{
    int s,sum,n,test=1;
    while(cin>>n && n)
    {
        s=sum=0;
        for(int i=0;i<n;i++) cin>>node[i].b>>node[i].j;
        sort(node,node+n,cmp);
        for(int i=0;i<n;i++) { s+=node[i].b; sum=max(sum,s+node[i].j); }
        printf("Case %d: %d\n",test++,sum);
    }
    return 0;
}
