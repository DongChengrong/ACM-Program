#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

const int maxn=30;
vector<int> v[maxn];
char order1[10],order2[10];
int N,a,b;

void find(int a,int &p,int &q)
{
    for(int i=0;i<N;i++)
        for(int j=0;j<v[i].size();j++)
        if(v[i][j]==a) { p=i; q=j; return; }
}

void remove(int a)
{
    int p,q;
    find(a,p,q);
    for(int i=q+1;i<v[p].size();i++)
    {
        int value=v[p][i];
        v[value].push_back(value);
    }
    v[p].resize(q+1);
}

void move(int a,int b)
{
    int p1,p2,q1,q2;
    find(a,p1,q1); find(b,p2,q2);
    for(int i=q1;i<v[p1].size();i++)
        v[p2].push_back(v[p1][i]);
    v[p1].resize(q1);
}

int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++) v[i].push_back(i);
    while(scanf("%s",order1) && strcmp("quit",order1)!=0)
    {
        scanf("%d %s %d",&a,order2,&b);
        int p1,p2,q1,q2;
        find(a,p1,q1); find(b,p2,q2);
        if(p1==p2) continue;
        if(!strcmp(order1,"move")) remove(a);
        if(!strcmp(order2,"onto")) remove(b);
        move(a,b);
    }
    for(int i=0;i<N;i++)
    {
        printf("%d:",i);
        for(int j=0;j<v[i].size();j++) printf(" %d",v[i][j]);
        printf("\n");
    }
    return 0;
}
