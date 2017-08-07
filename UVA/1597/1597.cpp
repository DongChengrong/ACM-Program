#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<sstream>
#include<iostream>
using namespace std;

const int maxr=1500+10;
const int maxa=100+10;
string A,B;

struct Node
{
    vector<string> context;
}articles[maxa];

int query(int pos,int way)
{
    int ok=1;
    if(way==0)
    {
        for(int i=0;i<articles[pos].context.size();i++)
            if(articles[pos].context[i].find(A)!=-1) { ok=0; break; }
        if(ok)
            for(int i=0;i<articles[pos].context.size();i++)
                cout<<articles[pos].context[i]<<endl;
        return ok;
    }
    ok=0;
    if(way==1)
    {
        for(int i=0;i<articles[pos].context.size();i++)
            if(articles[pos].context[i].find(A)!=-1)
            {
                ok=1;
                cout<<articles[pos].context[i]<<endl;
            }
    }
    if(way==2)
    {
        for(int i=0;i<articles[pos].context.size();i++)
            if(articles[pos].context[i].find(A)!=-1 && articles[pos].context[i].find(B)!=-1)
            {
                ok=1;
                cout<<articles[pos].context[i]<<endl;
            }
    }
    if(way==3)
    {
        for(int i=0;i<articles[pos].context.size();i++)
            if(articles[pos].context[i].find(A)!=-1 || articles[pos].context[i].find(B)!=-1)
            {
                ok=1;
                cout<<articles[pos].context[i]<<endl;
            }
    }
    return ok;
}

int main()
{
    int N,M;
    char s[maxa];
    scanf("%d",&N); getchar();
    int i=0;
    while(i<N)
    {
        gets(s);
        string str(s);
        if(!strcmp(s,"**********")) i++;
        else articles[i].context.push_back(str);
    }
    scanf("%d",&M); getchar();
    while(M--)
    {
        int way;
        gets(s);
        string str=s;
        stringstream ss(str);
        ss>>str;
        if(str=="NOT") { ss>>A; way=0; }
        else
        {
            if(ss>>B)
            {
                if(B=="AND") way=2;
                else way=3;
                ss>>B;
            }
            else way=1;
        }
        int ok=0;
        for(int i=0;i<N;i++)
        {
            if(query(i,way))
            {
                ok=1;
                printf("----------\n");
            }
        }
        if(!ok) printf("¡®Sorry, I found nothing.\n");
        printf("==========\n");

    }
    return 0;
}
