#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn = 1000 + 20;
char s1[maxn],s2[maxn];
int d[maxn][maxn];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s%s",s1 + 1,s2 + 1);
        memset(d,0,sizeof(d));
        printf("%d\n",d[0][0]);

        int n = strlen(s1 + 1);
        int m = strlen(s2 + 1);

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
            {
                if(s1[i] == s2[j]) d[i][j] = d[i - 1][j - 1] + 1;
                else d[i][j] = max(d[i - 1][j], d[i][j - 1]);
            }

        printf("%d\n",d[n][m]);
    }
    return 0;
}
