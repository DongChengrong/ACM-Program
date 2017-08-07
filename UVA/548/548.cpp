#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=10000+10;
int n,best,best_sum;
int inorder[maxn],postorder[maxn],lch[maxn],rch[maxn];

int read(int *a)
{
    int x;
    string line;
    n=0;
    if(!getline(cin,line)) return 0;
    stringstream ss(line);
    while(ss>>x) a[n++]=x;
    return n>0;
}

int build(int l1,int r1,int l2,int r2)
{
    if(l1>r1) return 0;
    int root=postorder[r2];
    int pos=l1;
    while(inorder[pos]!=root) pos++;
    int cnt=pos-l1;
    lch[root]=build(l1,pos-1,l2,l2+cnt-1);
    rch[root]=build(pos+1,r1,l2+cnt,r2-1);
    return root;
}

void dfs(int root,int sum)
{
    sum+=root;
    if(lch[root]==0 && rch[root]==0)
    {
        if(sum<best_sum || (sum==best_sum && root<best))
        {
            best=root; best_sum=sum;
        }
    }
    if(lch[root]!=0) dfs(lch[root],sum);
    if(rch[root]!=0) dfs(rch[root],sum);
}

int main()
{
    while(read(inorder))
    {
        read(postorder);
        build(0,n-1,0,n-1);
        best=best_sum=100000000;
        dfs(postorder[n-1],0);
        cout<<best<<endl;
    }
    return 0;
}
