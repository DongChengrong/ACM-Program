#include<cstdio>
#include<string>
#include<map>
#include<cstring>
#include<sstream>
#include<iostream>
using namespace std;

int row,col,ans,ok;
const int maxn=100;
char table[maxn];
int code[10010][15];
int a,b,c,d;

typedef pair<int,int> P;

map<string,int> id;
map<P,int> m;

void convert(int r)
{
    int c=1;
    string s="";
    for(int i=0;i<=strlen(table);i++)
    {
        char p=table[i];
        if(p==',' || p=='\0')
        {
            if(id.count(s)) code[r][c]=id[s];
            else { id[s]=ans; code[r][c]=ans++; }
            c++; s="";
        }
        else s+=p;
    }
}

void judge()
{
    for(int r=1;r<=row;r++)
    {
       for(int c1=1;c1<=col;c1++)
        {
            for(int c2=c1+1;c2<=col;c2++)
            {
                    P p=make_pair(code[r][c1],code[r][c2]);
                    if(m.count(p)) { ok=1; a=m[p]; b=r; c=c1; d=c2; return; }
                    else m[p]=r;
            }
        }
    }
}

int main()
{
    while(scanf("%d %d",&row,&col)==2)
    {
        getchar(); ok=ans=0; id.clear();
        memset(code,-1,sizeof(code));
        for(int r=1;r<=row;r++)
        {
            gets(table);
            convert(r);
        }
        m.clear();
        judge();
        if(ok)
        {
            printf("NO\n");
            printf("%d %d\n",a,b);
            printf("%d %d\n",c,d);
        }
        else printf("YES\n");
    }
    return 0;
}
