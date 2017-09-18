#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn = 100 + 10;
char s[maxn];
int n, d[maxn][maxn];

void readline(char *s)
{
    fgets(s, maxn, stdin);
}

int match(int i,int j)
{
    if(s[i] == '(' && s[j] == ')') return 1;
    if(s[i] == '[' && s[j] == ']') return 1;
    return 0;
}

void dp()
{
    for(int i = 0; i < n; i++)
    {
        d[i + 1][i] = 0;
        d[i][i] = 1;
    }
    for(int i = n - 2; i >= 0; i--)
    {
        for(int j = i + 1; j < n; j++)
        {
            d[i][j] = n;
            if(match(i,j)) d[i][j] = min(d[i][j], d[i+1][j-1]);
            for(int k = i; k < j; k++)
                d[i][j] = min(d[i][j], d[i][k] + d[k + 1][j]);
        }
    }
}

void print(int i,int j)
{
    if(i > j) return;
    if(i == j)
    {
        if(s[i] == '(' || s[i] == ')')
            printf("()");
        else printf("[]");
        return;
    }

    int ans = d[i][j];
    if(match(i,j) && ans == d[i+1][j-1])
    {
        printf("%c",s[i]); print(i + 1, j - 1); printf("%c",s[j]);
        return;
    }
    for(int k = i; k < j; k++)
        if(ans == d[i][k] + d[k + 1][j])
        {
            print(i, k); print(k + 1, j);
            return;
        }
}

int main()
{
    int T;
    readline(s);
    sscanf(s, "%d", &T);
    readline(s);
    while(T--)
    {
        readline(s);
        n = strlen(s) - 1;
        memset(d,-1,sizeof(d));
        dp();
        print(0,n - 1);
        printf("\n");
        if(T) printf("\n");
        readline(s);
    }
    return 0;
}
