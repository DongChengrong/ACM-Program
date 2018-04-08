#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=100;
char s[maxn];
int len;

int judge(int p)
{
    int i=p;
    while(i!=len)
    {
        for(int j=0;j<p;j++)
            if(s[j]!=s[j+i]) return 0;
        i+=p;
    }
    return 1;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        char c;
        getchar();
        getchar();
        scanf("%s",s);
        len=strlen(s);
        int ans=len;
        for(int i=1;i<=len/2;i++)
        {
            if(len%i==0) if(judge(i)) { ans=i; break; }
        }
        printf("%d\n",ans);
        if(T!=0) printf("\n");
    }
    return 0;
}
