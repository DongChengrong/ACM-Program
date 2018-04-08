#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define N 1010
#define INF 0x3f3f3f3f

int a[N][N];
char G[N][N];

int main()
{
    int n;
    while(scanf("%d",&n) == 1){
        for(int i = 1; i <= n; i++)
            scanf("%s",G[i]+1);
        memset(a,0,sizeof(a));
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(G[i][j] == 'o') a[i][j] = 1;
        bool ok = true;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
            {
                int x = 0;
                x += a[i - 1][j]; x+= a[i+1][j];
                x += a[i][j - 1]; x += a[i][j+1];
                if(x % 2 == 1) ok = false;
            }
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}