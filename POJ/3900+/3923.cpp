#include<cstdio>
#include<cstring>
#include<set>
#include<iostream>
using namespace std;

typedef struct Node
{
    int have;
    int x1,x2,y1,y2;
    Node(int have=0) : have(have){}
}Node;

const int maxn=100+10;
char G[maxn][maxn];
bool vis[maxn][maxn];
int n,m,X,Y,x,y;
Node alp[26];

int check(int x1,int y1,int x2,int y2,set<char> &s)
{
    for(int i=0;i<26;i++)
    {
        if(alp[i].have)
        {
            if(x1>alp[i].x1 && x2<alp[i].x2 && y1>alp[i].y1 && y2<alp[i].y2)
                s.erase('A'+i);
            else if(x1<alp[i].x1 && x2>alp[i].x2 && y1<alp[i].y1 && y2>alp[i].y2)
                return 0;
        }
    }
    return 1;
}

int main()
{
    while(scanf("%d %d",&n,&m)==2 && n)
    {
        set<char> s;
        x=y=X=Y=1;
        memset(vis,false,sizeof(vis));
        for(int i=0;i<n;i++) scanf("%s",G[i]);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if( !vis[i][j] && G[i][j]!='.')
                {
                    vis[i][j]=true;
                    char c=G[i][j];
                    int k,z;
                    for(k=j+1;k<m;k++)
                    {
                        if(!vis[i][k] && G[i][k]==c) X++;
                        else break;
                        vis[i][k]=true;
                    }
                    for(z=i+1;z<n;z++)
                    {
                        if(!vis[z][j] && G[z][j]==c) Y++;
                        else break;
                        vis[z][j]=true;
                    }
                    k=k-1; z=z-1;
                    for(int t=i+1;t<n;t++)
                    {
                        if(!vis[t][k] && G[t][k]==c) y++;
                        else break;
                        vis[t][k]=true;
                    }
                    for(int t=j+1;t<m;t++)
                    {
                        if(!vis[z][t] && G[z][t]==c) x++;
                        else break;
                        vis[z][t]=true;
                    }
                    if((X>=3 && Y>=3) && (x+1)==X && Y==y)
                    {
                        if(check(i,j,i+x,j+y-1,s))
                        {
                            int pos=G[i][j]-'A';
                            alp[pos].have=1;
                            alp[pos].x1=i; alp[pos].x2=i+x; alp[pos].y1=j; alp[pos].y2=j+y-1;
                            s.insert(c);
                        }
                    }
                    x=y=X=Y=1;
                }
            }
        }
        for(set<char> ::iterator it=s.begin();it!=s.end();it++)
            cout<<*it;
        printf("\n");
    }
}
