#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=7;
char G[maxn][maxn];
char order[100];
int over,x,y,ok,have;

void move(char c)
{
    switch (c)
    {
        case 'A':
            {
                if(x-1<0){ over=1; break; }
                G[x][y]=G[x-1][y];
                G[x-1][y]=' ';
                x=x-1; break;
            }
        case 'B':
            {
                if(x+1>=5){ over=1; break; }
                G[x][y]=G[x+1][y];
                G[x+1][y]=' ';
                x=x+1; break;
            }
        case 'L':
            {
                if(y-1<0){ over=1; break; }
                G[x][y]=G[x][y-1];
                G[x][y-1]=' ';
                y=y-1; break;
            }
        case 'R':
            {
                if(y+1>=5){ over=1; break; }
                G[x][y]=G[x][y+1];
                G[x][y+1]=' ';
                y=y+1; break;
            }
        default :
            {
                over=1;
                break;
            }
    }
}

void locate()
{
    for(int i=0;i<5;i++)
            for(int j=0;j<5;j++)
            if(G[i][j]==' ') {  x=i; y=j; break; }
}

int main()
{
    int have=0,T=1;
    while(1)
    {
        for(int i=0;i<5;i++) {gets(G[i]); fflush(stdin); if(G[i][0]=='Z') return 0;}
        if(have) printf("\n");
        locate();
        over=0; char c;
        while((c=getchar()) && c!='0')
        {
            if(c=='\n') continue;
            if(over) continue;
            move(c);
        }
        getchar();
        printf("Puzzle #%d:\n",T++);
        if(!over) for(int i=0;i<5;i++) printf("%c %c %c %c %c\n",G[i][0],G[i][1],G[i][2],G[i][3],G[i][4]);
        else printf("This puzzle has no final configuration.\n");
        have=1;
    }
    return 0;
}
