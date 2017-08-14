#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;

const int maxn = 200 + 10;

int n;
char buf[maxn][maxn];

void dfs(int r,int c)
{
    printf("%c(",buf[r][c]);
    if(r+1 < n && buf[r+1][c] == '|')
    {
        int pos = c;
        while(pos>=1 && buf[r+2][pos-1] == '-') pos--;
        for(;;pos++)
        {
            if(buf[r+2][pos]!='-' || buf[r+3][pos] == '\0') break;
            if(!isspace(buf[r+3][pos])) dfs(r+3,pos);
        }
    }
    printf(")");
}

void slove()
{
    n = 0;
    for(;;)
    {
        fgets(buf[n],maxn,stdin);
        if(buf[n][0] == '#') break;
        else n++;
    }

    printf("(");

    if(n)
        for(int i=0;i<strlen(buf[0]);i++)
            if(buf[0][i] != ' ') { dfs(0,i); break; }

    printf(")\n");
}

int main()
{
    int T = 0;
    fgets(buf[0],maxn,stdin);
    sscanf(buf[0],"%d",&T);
    while(T--) slove();
    return 0;
}
