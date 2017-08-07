#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int flag=0;
    char c[50],d[50];
    int a[30],b[30];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    scanf("%s%s",c,d);
    for(int i=0;i<strlen(c);i++) a[c[i]-'A']++;
    for(int i=0;i<strlen(d);i++) b[d[i]-'A']++;
    sort(a,a+30); sort(b,b+30);
    for(int i=0; ;i++) { if(a[i]!=b[i]) { flag=1; break; }
    if(!a[i]) break; }
    if(flag) printf("NO\n");
    else printf("YES\n");
    return 0;
}
