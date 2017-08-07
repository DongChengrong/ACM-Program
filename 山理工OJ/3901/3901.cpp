#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=1000+10;
char s[maxn];

int num()
{
    int ans=0;
    for(int i=0;i<strlen(s);i++)
        ans+=(s[i]-'0');
    return ans;
}

int main()
{
    while(scanf("%s",s)==1)
    {
        int n=num();
        if(n%3==0) printf("0\n");
        else printf("1\n");
    }
    return 0;
}
