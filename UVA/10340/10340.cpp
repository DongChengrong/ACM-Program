#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=100000+10;
char s[maxn],t[maxn];

int check()
{
    int i=0,j=0;
    while(i<strlen(s) && j<strlen(t))
    {
        if(s[i]==t[j])
        {
            i++;
            j++;
        }
        else j++;
    }
    if(i==strlen(s)) return 1;
    else return 0;
}

int main()
{
    while(scanf("%s %s",s,t)==2)
    {
        if(check()) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
