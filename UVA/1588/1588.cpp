#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=100+10;
char h1[maxn],h2[maxn];

int main()
{
    while(scanf("%s%s",h1,h2)==2)
    {
        int i,j,t;
        int cnt1,cnt2;
        int m=strlen(h1);
        int n=strlen(h2);
        i=j=t=0;
        while(i<m && j<n)
        {
            if((h1[i]-'0')+(h2[j]-'0')<=3)
            { i++; j++; }
            else
            { t++; i=0;j=t; }
        }
        cnt1=m+n-i;
        i=j=t=0;
        while(i<m && j<n)
        {
            if((h1[i]-'0')+(h2[j]-'0')<=3)
            { i++; j++; }
            else
            { t++; i=t;j=0; }
        }
        cnt2=m+n-j;
        printf("%d\n",cnt1<cnt2?cnt1:cnt2);
    }
    return 0;
}
