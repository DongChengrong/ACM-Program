#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

const int maxn=256+10;
char buf[maxn];
int leap[maxn],n,q;

void build()
{
    int len=strlen(buf);
    for(int i=0;i<len;i++)
        leap[i]=buf[i]-'0';
}

void print()
{
    int pos=0;
    for(int i=0;i<strlen(buf);i++)
        pos=pos*2+(buf[i]-'0');
    printf("%d",leap[pos]);
}

int main()
{
    int T=0;
    while(scanf("%d",&n)==1 && n)
    {
        getchar(); gets(buf);
        scanf("%s",buf);
        build();
        scanf("%d",&q);
        printf("S-Tree #%d:\n",++T);
        while(q--)
        {
            scanf("%s",buf);
            print();
        }
        printf("\n\n");
    }
    return 0;
}
