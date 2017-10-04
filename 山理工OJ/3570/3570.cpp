#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

const int maxn=10000+10;
char s[maxn];
int cnt;

int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    while(T--)
    {
        cnt=0;
        while(1)
        {
            scanf("%c",&s[cnt++]);
            if(s[cnt-1]=='\n')
            {
                for(int i=cnt-2;i>=0;i--)
                    printf("%c",s[i]);
                printf("\n"); break;
            }
            else if(s[cnt-1]==' ')
            {
                for(int i=cnt-2;i>=0;i--)
                    printf("%c",s[i]);
                printf(" "); cnt=0;
            }
        }
    }
    return 0;
}
