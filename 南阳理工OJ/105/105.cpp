#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=1000000+10;
char s[maxn];

int mod()
{
    int ans=0;
    char *p=s;
    while(*p)
    {
        ans+=*p-'0';
        p++;
    }
    return ans%9;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long x;
        scanf("%s",s);
        printf("%d\n",mod());
    }
    return 0;
}
