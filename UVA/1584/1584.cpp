#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=100+10;
char s[maxn];
int n;

int less(int p,int q)
{
    for(int i=0;i<n;i++)
    {
        int k1=(p+i)%n;
        int k2=(q+i)%n;
        if(s[k1]!=s[k2]) return s[k1]<s[k2];
    }
    return 0;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s);
        n=strlen(s);
        int ans=0;
        for(int i=1;i<n;i++)
            if(less(i,ans)) ans=i;
        printf("%s",s+ans);
        s[ans]='\0'; printf("%s\n",s);
    }
    return 0;
}
