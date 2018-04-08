#include<cstdio>
#include<string>
#include<map>
#include<cstring>
#include<iostream>
using namespace std;

const int maxn=100;
char table[maxn];
int row,col;
int ok;
int r1,r2,c[2];

void judge(int r,map<string,int> *m)
{
    int cnt=0;
    int ans=0;
    string s="";
    for(int i=0;i<=strlen(table);i++)
    {
        if(table[i]==',' || table[i]=='\0')
        {
            if(m[cnt].count(s)) { r1=m[cnt][s]+1; r2=r+1; c[ans++]=cnt+1; cnt++;  }
            else { m[cnt][s]=r; cnt++;  }
            s="";
        }
        else
        {
            s+=table[i];
        }
    }
    if(ans==2) ok=1;
}

int main()
{
    while(scanf("%d %d",&row,&col)==2)
    {
       ok=0;
       getchar();
       map<string,int> m[10];
       for(int r=0;r<row;r++)
       {
           gets(table);
           if(ok) continue;
           judge(r,m);
       }
       if(!ok) printf("YES\n");
       else
       {
           printf("NO\n");
           printf("%d %d\n",r1,r2);
           printf("%d %d\n",c[0],c[1]);
       }
    }
    return 0;
}
