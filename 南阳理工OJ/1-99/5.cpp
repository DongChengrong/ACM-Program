#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=1000+10;
char s1[maxn],s2[maxn];
int cnt;

void match()
{
    int pos=0;
    int len1=strlen(s1);
    int len2=strlen(s2);
    while(pos<len2)
    {
        bool flag=true;
        for(int i=0;i<len1;i++)
            if(s1[i]!=s2[pos+i]) { flag=false; break; }
        if(flag) cnt++;
        pos++;
    }
}

int main()
{
    int Test;
    scanf("%d",&Test);
    while(Test--)
    {
        cnt=0;
        scanf("%s%s",s1,s2);
        match();
        printf("%d\n",cnt);
    }
    return 0;
}
