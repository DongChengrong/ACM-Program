#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<sstream>
#include<algorithm>
#include<iostream>
using namespace std;

typedef struct book{
    int state;
    string author;
}book;

const int maxn=200;
char info[maxn];
vector<string> libs;
map<string,book> m;

bool cmp(string s1,string s2)
{
    if(m[s1].author!=m[s2].author) return m[s1].author<m[s2].author;
    else return s1<s2;
}

void add()
{
    stringstream ss(info);
    string title="",author="";
    string buf;
    ss>>buf; title+=buf;
    while(ss>>buf){
        if(buf=="by") break;
        title+=" "; title+=buf;
    }
    libs.push_back(title);
    ss>>buf; author+=buf;
    while(ss>>buf){
        author+=" "; author+=buf;
    }
    book b; b.state=1; b.author=author;
    m[title]=b;
}

void operate(){
    string order,title,buf;
    stringstream ss(info);
    ss>>order; if(ss>>buf) title+=buf;
    while(ss>>buf)
    {
        title+=" "; title+=buf;
    }
    switch(order[0])
    {
        case 'B':{
            m[title].state=-1;
            break;
        }
        case 'R' :{
            m[title].state=0;
            break;
        }
        case 'S':{
            for(int i=0;i<libs.size();i++)
            {
                title=libs[i];
                if(m[title].state!=0) continue;
                int j;
                for(j=i-1;j>=0;j--)
                    if(m[libs[j]].state==1) break;
                if(j<0) cout<<"Put "<<title<<" first"<<endl;
                else cout<<"Put "<<title<<" after "<<libs[j]<<endl;
                m[title].state=1;
            }
            printf("END\n");
            break;
        }
    }
}

int main()
{
    while(gets(info) && info[0]!='E' ) add();
    sort(libs.begin(),libs.end(),cmp);
    while(gets(info) && info[0]!='E') operate();
    return 0;
}
