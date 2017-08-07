#include<cstdio>
using namespace std;

const int maxn=10;
char s[maxn];
int a[3];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s);
        for(int i=0;i<3;i++)
            a[i]=s[i]-'0';
        if(a[0]<a[1])
        {
            if(a[2]<a[0])
            {
                printf("%c %c %c\n",s[2],s[0],s[1]);
            }
            else
            {
                printf("%c %c %c\n",s[0],a[1]<a[2]?s[1]:s[2],a[1]<a[2]?s[2]:s[1]);
            }
        }
        else
        {
            if(a[2]<a[1])
            {
                printf("%c %c %c\n",s[2],s[1],s[0]);
            }
            else
            {
                printf("%c %c %c\n",s[1],a[0]<a[2]?s[0]:s[2],a[0]<a[2]?s[2]:s[0]);
            }
        }
    }
    return 0;
}
