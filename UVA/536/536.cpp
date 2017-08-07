#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

const int maxn=300;
char s1[maxn],s2[maxn];

void build(int l1,int r1,int l2,int r2)
{
    int pos;
    if(l1>r1) return;
    for(pos=l2;pos<strlen(s2);pos++)
        if(s2[pos]==s1[l1]) break;
    int cnt=pos-l2;
    build(l1+1,l1+cnt,l2,pos-1);
    build(l1+cnt+1,r1,pos+1,r2);
    printf("%c",s1[l1]);
}

int main()
{
    while(scanf("%s",s1)==1)
    {
        scanf("%s",s2);
        build(0,strlen(s1)-1,0,strlen(s2)-1);
        printf("\n");
    }
    return 0;
}
